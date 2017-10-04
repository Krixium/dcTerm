/********************************************************************************
** Form generated from reading UI file 'dcTerm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCTERM_H
#define UI_DCTERM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dcTermClass
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionClose;
    QAction *actionParityy;
    QAction *action1200;
    QAction *action2400;
    QAction *action4800;
    QAction *action9600;
    QAction *action19200;
    QAction *action38400;
    QAction *action57600;
    QAction *action115200;
    QAction *action5;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *action1;
    QAction *action2;
    QAction *actionEven;
    QAction *actionOdd;
    QAction *actionNone;
    QAction *actionCurrent_Settings;
    QAction *actionNo_Flow_Control;
    QAction *actionHardware_Control;
    QAction *actionSoftware_Control;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuBit_Rate;
    QMenu *menuData_Bits;
    QMenu *menuStop_Bits;
    QMenu *menuParity;
    QMenu *menuFlow_Control;
    QMenu *menuPort;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dcTermClass)
    {
        if (dcTermClass->objectName().isEmpty())
            dcTermClass->setObjectName(QStringLiteral("dcTermClass"));
        dcTermClass->resize(1280, 720);
        actionConnect = new QAction(dcTermClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(dcTermClass);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setEnabled(false);
        actionClose = new QAction(dcTermClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionParityy = new QAction(dcTermClass);
        actionParityy->setObjectName(QStringLiteral("actionParityy"));
        action1200 = new QAction(dcTermClass);
        action1200->setObjectName(QStringLiteral("action1200"));
        action1200->setCheckable(false);
        action2400 = new QAction(dcTermClass);
        action2400->setObjectName(QStringLiteral("action2400"));
        action2400->setCheckable(false);
        action4800 = new QAction(dcTermClass);
        action4800->setObjectName(QStringLiteral("action4800"));
        action4800->setCheckable(false);
        action9600 = new QAction(dcTermClass);
        action9600->setObjectName(QStringLiteral("action9600"));
        action9600->setCheckable(false);
        action19200 = new QAction(dcTermClass);
        action19200->setObjectName(QStringLiteral("action19200"));
        action19200->setCheckable(false);
        action38400 = new QAction(dcTermClass);
        action38400->setObjectName(QStringLiteral("action38400"));
        action38400->setCheckable(false);
        action57600 = new QAction(dcTermClass);
        action57600->setObjectName(QStringLiteral("action57600"));
        action57600->setCheckable(false);
        action115200 = new QAction(dcTermClass);
        action115200->setObjectName(QStringLiteral("action115200"));
        action115200->setCheckable(false);
        action5 = new QAction(dcTermClass);
        action5->setObjectName(QStringLiteral("action5"));
        action6 = new QAction(dcTermClass);
        action6->setObjectName(QStringLiteral("action6"));
        action7 = new QAction(dcTermClass);
        action7->setObjectName(QStringLiteral("action7"));
        action8 = new QAction(dcTermClass);
        action8->setObjectName(QStringLiteral("action8"));
        action1 = new QAction(dcTermClass);
        action1->setObjectName(QStringLiteral("action1"));
        action2 = new QAction(dcTermClass);
        action2->setObjectName(QStringLiteral("action2"));
        actionEven = new QAction(dcTermClass);
        actionEven->setObjectName(QStringLiteral("actionEven"));
        actionOdd = new QAction(dcTermClass);
        actionOdd->setObjectName(QStringLiteral("actionOdd"));
        actionNone = new QAction(dcTermClass);
        actionNone->setObjectName(QStringLiteral("actionNone"));
        actionCurrent_Settings = new QAction(dcTermClass);
        actionCurrent_Settings->setObjectName(QStringLiteral("actionCurrent_Settings"));
        actionNo_Flow_Control = new QAction(dcTermClass);
        actionNo_Flow_Control->setObjectName(QStringLiteral("actionNo_Flow_Control"));
        actionHardware_Control = new QAction(dcTermClass);
        actionHardware_Control->setObjectName(QStringLiteral("actionHardware_Control"));
        actionSoftware_Control = new QAction(dcTermClass);
        actionSoftware_Control->setObjectName(QStringLiteral("actionSoftware_Control"));
        centralWidget = new QWidget(dcTermClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dcTermClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dcTermClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuBit_Rate = new QMenu(menuSettings);
        menuBit_Rate->setObjectName(QStringLiteral("menuBit_Rate"));
        menuData_Bits = new QMenu(menuSettings);
        menuData_Bits->setObjectName(QStringLiteral("menuData_Bits"));
        menuStop_Bits = new QMenu(menuSettings);
        menuStop_Bits->setObjectName(QStringLiteral("menuStop_Bits"));
        menuParity = new QMenu(menuSettings);
        menuParity->setObjectName(QStringLiteral("menuParity"));
        menuFlow_Control = new QMenu(menuSettings);
        menuFlow_Control->setObjectName(QStringLiteral("menuFlow_Control"));
        menuPort = new QMenu(menuBar);
        menuPort->setObjectName(QStringLiteral("menuPort"));
        dcTermClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(dcTermClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dcTermClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuPort->menuAction());
        menuFile->addAction(actionConnect);
        menuFile->addAction(actionDisconnect);
        menuFile->addAction(actionClose);
        menuSettings->addAction(menuBit_Rate->menuAction());
        menuSettings->addAction(menuData_Bits->menuAction());
        menuSettings->addAction(menuParity->menuAction());
        menuSettings->addAction(menuStop_Bits->menuAction());
        menuSettings->addAction(menuFlow_Control->menuAction());
        menuBit_Rate->addAction(action1200);
        menuBit_Rate->addAction(action2400);
        menuBit_Rate->addAction(action4800);
        menuBit_Rate->addAction(action9600);
        menuBit_Rate->addAction(action19200);
        menuBit_Rate->addAction(action38400);
        menuBit_Rate->addAction(action57600);
        menuBit_Rate->addAction(action115200);
        menuData_Bits->addAction(action5);
        menuData_Bits->addAction(action6);
        menuData_Bits->addAction(action7);
        menuData_Bits->addAction(action8);
        menuStop_Bits->addAction(action1);
        menuStop_Bits->addAction(action2);
        menuParity->addAction(actionEven);
        menuParity->addAction(actionOdd);
        menuParity->addAction(actionNone);
        menuFlow_Control->addAction(actionNo_Flow_Control);
        menuFlow_Control->addAction(actionHardware_Control);
        menuFlow_Control->addAction(actionSoftware_Control);

        retranslateUi(dcTermClass);

        QMetaObject::connectSlotsByName(dcTermClass);
    } // setupUi

    void retranslateUi(QMainWindow *dcTermClass)
    {
        dcTermClass->setWindowTitle(QApplication::translate("dcTermClass", "dcTerm", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("dcTermClass", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("dcTermClass", "Disconnect", Q_NULLPTR));
        actionClose->setText(QApplication::translate("dcTermClass", "Close", Q_NULLPTR));
        actionParityy->setText(QApplication::translate("dcTermClass", "Parityy", Q_NULLPTR));
        action1200->setText(QApplication::translate("dcTermClass", "1200", Q_NULLPTR));
        action2400->setText(QApplication::translate("dcTermClass", "2400", Q_NULLPTR));
        action4800->setText(QApplication::translate("dcTermClass", "4800", Q_NULLPTR));
        action9600->setText(QApplication::translate("dcTermClass", "9600", Q_NULLPTR));
        action19200->setText(QApplication::translate("dcTermClass", "19200", Q_NULLPTR));
        action38400->setText(QApplication::translate("dcTermClass", "38400", Q_NULLPTR));
        action57600->setText(QApplication::translate("dcTermClass", "57600", Q_NULLPTR));
        action115200->setText(QApplication::translate("dcTermClass", "115200", Q_NULLPTR));
        action5->setText(QApplication::translate("dcTermClass", "5", Q_NULLPTR));
        action6->setText(QApplication::translate("dcTermClass", "6", Q_NULLPTR));
        action7->setText(QApplication::translate("dcTermClass", "7", Q_NULLPTR));
        action8->setText(QApplication::translate("dcTermClass", "8", Q_NULLPTR));
        action1->setText(QApplication::translate("dcTermClass", "1", Q_NULLPTR));
        action2->setText(QApplication::translate("dcTermClass", "2", Q_NULLPTR));
        actionEven->setText(QApplication::translate("dcTermClass", "Even", Q_NULLPTR));
        actionOdd->setText(QApplication::translate("dcTermClass", "Odd", Q_NULLPTR));
        actionNone->setText(QApplication::translate("dcTermClass", "None", Q_NULLPTR));
        actionCurrent_Settings->setText(QApplication::translate("dcTermClass", "Current Settings", Q_NULLPTR));
        actionNo_Flow_Control->setText(QApplication::translate("dcTermClass", "No Flow Control", Q_NULLPTR));
        actionHardware_Control->setText(QApplication::translate("dcTermClass", "Hardware Control", Q_NULLPTR));
        actionSoftware_Control->setText(QApplication::translate("dcTermClass", "Software Control", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("dcTermClass", "File", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("dcTermClass", "Settings", Q_NULLPTR));
        menuBit_Rate->setTitle(QApplication::translate("dcTermClass", "Bit Rate", Q_NULLPTR));
        menuData_Bits->setTitle(QApplication::translate("dcTermClass", "Data Bits", Q_NULLPTR));
        menuStop_Bits->setTitle(QApplication::translate("dcTermClass", "Stop Bits", Q_NULLPTR));
        menuParity->setTitle(QApplication::translate("dcTermClass", "Parity", Q_NULLPTR));
        menuFlow_Control->setTitle(QApplication::translate("dcTermClass", "Flow Control", Q_NULLPTR));
        menuPort->setTitle(QApplication::translate("dcTermClass", "Port", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dcTermClass: public Ui_dcTermClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCTERM_H
