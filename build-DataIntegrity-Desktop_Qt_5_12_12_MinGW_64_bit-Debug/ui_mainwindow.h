/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView.h>
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(612, 433);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 131, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 90, 120, 161));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        labelStatus = new QLabel(groupBox);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(10, 127, 103, 13));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        labelStatus->setFont(font2);
        btnConnect = new QPushButton(groupBox);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(10, 98, 103, 23));
        btnConnect->setFont(font2);
        comboParity = new QComboBox(groupBox);
        comboParity->setObjectName(QString::fromUtf8("comboParity"));
        comboParity->setGeometry(QRect(10, 72, 103, 20));
        comboBaud = new QComboBox(groupBox);
        comboBaud->setObjectName(QString::fromUtf8("comboBaud"));
        comboBaud->setGeometry(QRect(10, 46, 103, 20));
        comboPort = new QComboBox(groupBox);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        comboPort->setGeometry(QRect(10, 20, 103, 20));
        lcdData0 = new QLCDNumber(centralwidget);
        lcdData0->setObjectName(QString::fromUtf8("lcdData0"));
        lcdData0->setGeometry(QRect(120, 60, 64, 23));
        lcdData1 = new QLCDNumber(centralwidget);
        lcdData1->setObjectName(QString::fromUtf8("lcdData1"));
        lcdData1->setGeometry(QRect(120, 90, 64, 23));
        lcdData2 = new QLCDNumber(centralwidget);
        lcdData2->setObjectName(QString::fromUtf8("lcdData2"));
        lcdData2->setGeometry(QRect(120, 120, 64, 23));
        lcdData3 = new QLCDNumber(centralwidget);
        lcdData3->setObjectName(QString::fromUtf8("lcdData3"));
        lcdData3->setGeometry(QRect(120, 150, 64, 23));
        lcdData4 = new QLCDNumber(centralwidget);
        lcdData4->setObjectName(QString::fromUtf8("lcdData4"));
        lcdData4->setGeometry(QRect(120, 180, 64, 23));
        lcdData5 = new QLCDNumber(centralwidget);
        lcdData5->setObjectName(QString::fromUtf8("lcdData5"));
        lcdData5->setGeometry(QRect(120, 210, 64, 23));
        lcdData6 = new QLCDNumber(centralwidget);
        lcdData6->setObjectName(QString::fromUtf8("lcdData6"));
        lcdData6->setGeometry(QRect(120, 240, 64, 23));
        lcdData7 = new QLCDNumber(centralwidget);
        lcdData7->setObjectName(QString::fromUtf8("lcdData7"));
        lcdData7->setGeometry(QRect(120, 270, 64, 23));
        lcdData8 = new QLCDNumber(centralwidget);
        lcdData8->setObjectName(QString::fromUtf8("lcdData8"));
        lcdData8->setGeometry(QRect(120, 300, 64, 23));
        lcdData9 = new QLCDNumber(centralwidget);
        lcdData9->setObjectName(QString::fromUtf8("lcdData9"));
        lcdData9->setGeometry(QRect(120, 330, 64, 23));
        lcdData10 = new QLCDNumber(centralwidget);
        lcdData10->setObjectName(QString::fromUtf8("lcdData10"));
        lcdData10->setGeometry(QRect(120, 360, 64, 23));
        chartView = new QChartView(centralwidget);
        chartView->setObjectName(QString::fromUtf8("chartView"));
        chartView->setGeometry(QRect(190, 60, 421, 311));
        labelTimeout = new QLabel(centralwidget);
        labelTimeout->setObjectName(QString::fromUtf8("labelTimeout"));
        labelTimeout->setGeometry(QRect(20, 280, 71, 20));
        btnResetZoom = new QPushButton(centralwidget);
        btnResetZoom->setObjectName(QString::fromUtf8("btnResetZoom"));
        btnResetZoom->setGeometry(QRect(20, 330, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 612, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Data Integrity", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Serial Settings", nullptr));
        labelStatus->setText(QApplication::translate("MainWindow", "Connection Status", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        labelTimeout->setText(QApplication::translate("MainWindow", "Timeout", nullptr));
        btnResetZoom->setText(QApplication::translate("MainWindow", "Reset Zoom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
