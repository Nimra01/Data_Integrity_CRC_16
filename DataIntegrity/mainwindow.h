#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QTimer>
#include <QFile>
#include <QTextStream>

QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void scanSerialPorts();
    void connectSerial();
    void handleReadyRead();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    bool connected = false;

    QTimer *timeoutTimer;
    bool timedOut = false;

    QFile csvFile;
    QTextStream csvStream;
    bool csvLoggingEnabled = false;

    // Add to private:
    QList<QLineSeries*> seriesList;
    QValueAxis *axisX, *axisY;
    QChart *chart;
    int xVal = 0;
    QLineSeries *series;             // <-- moved inside class
    QByteArray serialBuffer;

    quint16 crc16_ccitt(const QByteArray &data);
    void parseIncomingData();
    void updateConnectionStatus(bool ok);
};

#endif // MAINWINDOW_H
