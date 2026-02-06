/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox;
    QLabel *labelStatus;
    QPushButton *btnConnect;
    QComboBox *comboParity;
    QComboBox *comboBaud;
    QComboBox *comboPort;
    QLCDNumber *lcdData0;
    QLCDNumber *lcdData1;
    QLCDNumber *lcdData2;
    QLCDNumber *lcdData3;
    QLCDNumber *lcdData4;
    QLCDNumber *lcdData5;
    QLCDNumber *lcdData6;
    QLCDNumber *lcdData7;
    QLCDNumber *lcdData8;
    QLCDNumber *lcdData9;
    QLCDNumber *lcdData10;
    QChartView *chartView;
    QLabel *labelTimeout;
    QPushButton *btnResetZoom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(612, 433);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 10, 131, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 90, 120, 161));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        groupBox->setFont(font1);
        labelStatus = new QLabel(groupBox);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(10, 127, 103, 13));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        labelStatus->setFont(font2);
        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName("btnConnect");
        btnConnect->setGeometry(QRect(10, 98, 103, 23));
        btnConnect->setFont(font2);
        comboParity = new QComboBox(groupBox);
        comboParity->setObjectName("comboParity");
        comboParity->setGeometry(QRect(10, 72, 103, 20));
        comboBaud = new QComboBox(groupBox);
        comboBaud->setObjectName("comboBaud");
        comboBaud->setGeometry(QRect(10, 46, 103, 20));
        comboPort = new QComboBox(groupBox);
        comboPort->setObjectName("comboPort");
        comboPort->setGeometry(QRect(10, 20, 103, 20));
        lcdData0 = new QLCDNumber(centralwidget);
        lcdData0->setObjectName("lcdData0");
        lcdData0->setGeometry(QRect(120, 60, 64, 23));
        lcdData1 = new QLCDNumber(centralwidget);
        lcdData1->setObjectName("lcdData1");
        lcdData1->setGeometry(QRect(120, 90, 64, 23));
        lcdData2 = new QLCDNumber(centralwidget);
        lcdData2->setObjectName("lcdData2");
        lcdData2->setGeometry(QRect(120, 120, 64, 23));
        lcdData3 = new QLCDNumber(centralwidget);
        lcdData3->setObjectName("lcdData3");
        lcdData3->setGeometry(QRect(120, 150, 64, 23));
        lcdData4 = new QLCDNumber(centralwidget);
        lcdData4->setObjectName("lcdData4");
        lcdData4->setGeometry(QRect(120, 180, 64, 23));
        lcdData5 = new QLCDNumber(centralwidget);
        lcdData5->setObjectName("lcdData5");
        lcdData5->setGeometry(QRect(120, 210, 64, 23));
        lcdData6 = new QLCDNumber(centralwidget);
        lcdData6->setObjectName("lcdData6");
        lcdData6->setGeometry(QRect(120, 240, 64, 23));
        lcdData7 = new QLCDNumber(centralwidget);
        lcdData7->setObjectName("lcdData7");
        lcdData7->setGeometry(QRect(120, 270, 64, 23));
        lcdData8 = new QLCDNumber(centralwidget);
        lcdData8->setObjectName("lcdData8");
        lcdData8->setGeometry(QRect(120, 300, 64, 23));
        lcdData9 = new QLCDNumber(centralwidget);
        lcdData9->setObjectName("lcdData9");
        lcdData9->setGeometry(QRect(120, 330, 64, 23));
        lcdData10 = new QLCDNumber(centralwidget);
        lcdData10->setObjectName("lcdData10");
        lcdData10->setGeometry(QRect(120, 360, 64, 23));
        chartView = new QChartView(centralwidget);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(190, 60, 421, 311));
        labelTimeout = new QLabel(centralwidget);
        labelTimeout->setObjectName("labelTimeout");
        labelTimeout->setGeometry(QRect(20, 280, 71, 20));
        btnResetZoom = new QPushButton(centralwidget);
        btnResetZoom->setObjectName("btnResetZoom");
        btnResetZoom->setGeometry(QRect(20, 330, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 612, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Data Integrity", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Serial Settings", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Connection Status", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        labelTimeout->setText(QCoreApplication::translate("MainWindow", "Timeout", nullptr));
        btnResetZoom->setText(QCoreApplication::translate("MainWindow", "Reset Zoom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
