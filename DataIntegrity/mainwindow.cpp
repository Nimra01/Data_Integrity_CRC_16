#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <QtCharts/QLegendMarker>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // --- CSV File Logging Setup ---
    QString filename = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + "_log.csv";
    csvFile.setFileName(filename);
    if (csvFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        csvStream.setDevice(&csvFile);
        csvStream << "Time(ms),Data0,Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10\n";
        csvLoggingEnabled = true;
    }

    // --- Timeout Setup ---
    timeoutTimer = new QTimer(this);
    timeoutTimer->setInterval(400);
    timeoutTimer->setSingleShot(true);
    connect(timeoutTimer, &QTimer::timeout, this, [=]() {
        timedOut = true;
        ui->labelTimeout->setText("⏱️ TIMEOUT");
        ui->labelTimeout->setStyleSheet("color: red; font-weight: bold;");
    });

    // --- Chart Setup ---
    chart = new QChart();
    chart->setTitle("Live 11-Channel Data Stream");
    chart->legend()->setAlignment(Qt::AlignTop); // Put legend on top

    // --- 11 Distinct Colors ---
    QStringList colors = {
        "#e6194B", "#3cb44b", "#ffe119", "#4363d8", "#f58231",
        "#911eb4", "#46f0f0", "#f032e6", "#bcf60c", "#fabebe", "#008080"
    };

    // --- Setup Line Series ---
    for (int i = 0; i < 11; ++i) {
        QLineSeries *s = new QLineSeries();
        s->setName(QString("Ch %1").arg(i));  // Use short names for neat legend

        QColor color = QColor(colors[i]).lighter(120);
        QPen pen(color);
        pen.setWidth(1);
        s->setPen(pen);


        seriesList.append(s);
        chart->addSeries(s);
    }

    // --- Axis X: Shows Recent Samples (sliding window) ---
    axisX = new QValueAxis;
    axisX->setRange(0, 200);  // Shows last 200 samples
    axisX->setLabelFormat("%d");
    axisX->setTitleText("Samples");

    // --- Axis Y: 8-bit sensor range ---
    axisY = new QValueAxis;
    axisY->setRange(0, 255);
    axisY->setTitleText("Value");

    // --- Add Axes to Chart ---
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // --- Attach All Series to Axes ---
    for (auto *series : seriesList) {
        series->attachAxis(axisX);
        series->attachAxis(axisY);
    }

    // --- Chart View Styling ---
    ui->chartView->setChart(chart);
    ui->chartView->setRubberBand(QChartView::RectangleRubberBand);
    ui->chartView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->chartView->setInteractive(true);
    ui->chartView->setRenderHint(QPainter::Antialiasing);

    connect(ui->btnResetZoom, &QPushButton::clicked, [=]() {
        axisX->setRange(0, 100);
        axisY->setRange(0, 255);
        ui->chartView->chart()->zoomReset();
    });


    // --- Serial Port Setup ---
    serial = new QSerialPort(this);
    scanSerialPorts();  // Populates port list in dropdown

    ui->comboBaud->addItems({"9600", "19200", "38400", "57600", "115200"});
    ui->comboBaud->setCurrentText("9600");

    ui->comboParity->addItems({"None", "Even", "Odd"});
    ui->comboParity->setCurrentText("None");

    connect(ui->btnConnect, &QPushButton::clicked, this, &MainWindow::connectSerial);
}

MainWindow::~MainWindow() {
    if (serial->isOpen()) serial->close();
    delete ui;
}

void MainWindow::scanSerialPorts() {
    ui->comboPort->clear();
    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts()) {
        ui->comboPort->addItem(info.portName());
    }
}

void MainWindow::connectSerial() {
    if (!connected) {
        serial->setPortName(ui->comboPort->currentText());
        serial->setBaudRate(ui->comboBaud->currentText().toInt());

        QString parity = ui->comboParity->currentText();
        if (parity == "None") serial->setParity(QSerialPort::NoParity);
        else if (parity == "Even") serial->setParity(QSerialPort::EvenParity);
        else if (parity == "Odd") serial->setParity(QSerialPort::OddParity);

        serial->setDataBits(QSerialPort::Data8);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            connect(serial, &QSerialPort::readyRead, this, &MainWindow::handleReadyRead);
            connected = true;
            ui->btnConnect->setText("Disconnect");
            updateConnectionStatus(true);
        } else {
            updateConnectionStatus(false);
            qDebug() << "Serial open failed!";
        }
    } else {
        serial->close();
        connected = false;
        ui->btnConnect->setText("Connect");
        updateConnectionStatus(false);
    }
}

void MainWindow::updateConnectionStatus(bool ok) {
    if (ok) {
        ui->labelStatus->setStyleSheet("background-color: green; border-radius: 8px;");
    } else {
        ui->labelStatus->setStyleSheet("background-color: red; border-radius: 8px;");
    }
}

quint16 MainWindow::crc16_ccitt(const QByteArray &data) {
    quint16 crc = 0xFFFF;
    for (char byte : data) {
        crc ^= (quint8)byte << 8;
        for (int i = 0; i < 8; ++i) {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc <<= 1;
        }
    }
    return crc;
}

void MainWindow::handleReadyRead() {
    serialBuffer.append(serial->readAll());

    while (serialBuffer.size() >= 16) {
        int headerIndex = serialBuffer.indexOf("$DC");
        if (headerIndex == -1) {
            int lastDollar = serialBuffer.lastIndexOf('$');
            serialBuffer = serialBuffer.mid(lastDollar);
            return;
        }

        if (serialBuffer.size() - headerIndex < 16)
            return;

        QByteArray packet = serialBuffer.mid(headerIndex, 16);
        QByteArray payload = packet.left(14);
        quint16 receivedCrc = (quint8)packet[14] << 8 | (quint8)packet[15];
        quint16 computedCrc = crc16_ccitt(payload);

        if (receivedCrc == computedCrc) {
            timeoutTimer->start();       // restart timeout
            timedOut = false;
            ui->labelTimeout->setText("Active");
            ui->labelTimeout->setStyleSheet("color: green; font-weight: bold;");

            QByteArray dataBytes = packet.mid(3, 11);
            qDebug() << "✅ Valid packet:" << dataBytes.toHex(' ');

            // Update LCDs
            for (int i = 0; i < 11; ++i) {
                int val = static_cast<unsigned char>(dataBytes[i]);
                switch (i) {
                case 0: ui->lcdData0->display(val); break;
                case 1: ui->lcdData1->display(val); break;
                case 2: ui->lcdData2->display(val); break;
                case 3: ui->lcdData3->display(val); break;
                case 4: ui->lcdData4->display(val); break;
                case 5: ui->lcdData5->display(val); break;
                case 6: ui->lcdData6->display(val); break;
                case 7: ui->lcdData7->display(val); break;
                case 8: ui->lcdData8->display(val); break;
                case 9: ui->lcdData9->display(val); break;
                case 10: ui->lcdData10->display(val); break;
                }
            }

            // Update Chart
            //for (int i = 0; i < 11 && i < seriesList.size(); ++i) {
              //  int y = static_cast<unsigned char>(dataBytes[i]);
                //seriesList[i]->append(xVal, y);

                // Limit data points to 100
                //if (seriesList[i]->count() > 100)
                  //  seriesList[i]->removePoints(0, seriesList[i]->count() - 100);
           // }
            const int maxPoints = 200;

            for (int i = 0; i < 11; ++i) {
                int y = static_cast<unsigned char>(dataBytes[i]);
                seriesList[i]->append(xVal, y);

                if (seriesList[i]->count() > maxPoints) {
                    seriesList[i]->remove(0);
                }
            }

            // Move x-axis window forward
            if (xVal > maxPoints) {
                axisX->setRange(xVal - maxPoints, xVal);
            }

            xVal++;



            if (csvLoggingEnabled) {
                csvStream << QString::number(QDateTime::currentMSecsSinceEpoch());
                for (int i = 0; i < 11; ++i) {
                    int val = static_cast<unsigned char>(dataBytes[i]);
                    csvStream << "," << val;
                }
                csvStream << "\n";
                csvStream.flush();  // ensure it's written immediately
            }


            // Move x-axis window forward
            if (xVal > 100) {
                axisX->setRange(xVal - 100, xVal);
            }

            xVal++;
        } else {
            qDebug() << "❌ CRC mismatch. Packet discarded.";
        }

        serialBuffer.remove(0, headerIndex + 16);
    }
}
