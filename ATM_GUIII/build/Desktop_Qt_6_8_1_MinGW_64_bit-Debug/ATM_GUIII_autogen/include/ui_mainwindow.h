/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *welcomeLabel;
    QPushButton *welcomeNextButton;
    QWidget *PIN;
    QLabel *label;
    QLineEdit *pinLineEdit;
    QPushButton *submitPinButton;
    QWidget *page_2;
    QLabel *label_2;
    QRadioButton *silverRadioButton;
    QRadioButton *goldRadioButton;
    QRadioButton *platinumRadioButton;
    QPushButton *nextCardButton;
    QWidget *page;
    QPushButton *balanceInquiryButton;
    QPushButton *depositMoneyButton;
    QPushButton *cashWithdrawalButton;
    QPushButton *transferMoneyButton;
    QPushButton *exitButton;
    QLabel *label_3;
    QPushButton *changePinButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(130, 20, 461, 321));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        welcomeLabel = new QLabel(page_3);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(50, 60, 321, 91));
        welcomeNextButton = new QPushButton(page_3);
        welcomeNextButton->setObjectName("welcomeNextButton");
        welcomeNextButton->setGeometry(QRect(300, 220, 111, 31));
        stackedWidget->addWidget(page_3);
        PIN = new QWidget();
        PIN->setObjectName("PIN");
        label = new QLabel(PIN);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 80, 151, 71));
        pinLineEdit = new QLineEdit(PIN);
        pinLineEdit->setObjectName("pinLineEdit");
        pinLineEdit->setGeometry(QRect(200, 100, 191, 31));
        submitPinButton = new QPushButton(PIN);
        submitPinButton->setObjectName("submitPinButton");
        submitPinButton->setGeometry(QRect(210, 200, 131, 31));
        stackedWidget->addWidget(PIN);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 211, 71));
        silverRadioButton = new QRadioButton(page_2);
        silverRadioButton->setObjectName("silverRadioButton");
        silverRadioButton->setGeometry(QRect(120, 100, 91, 31));
        goldRadioButton = new QRadioButton(page_2);
        goldRadioButton->setObjectName("goldRadioButton");
        goldRadioButton->setGeometry(QRect(120, 140, 111, 41));
        platinumRadioButton = new QRadioButton(page_2);
        platinumRadioButton->setObjectName("platinumRadioButton");
        platinumRadioButton->setGeometry(QRect(120, 190, 111, 41));
        nextCardButton = new QPushButton(page_2);
        nextCardButton->setObjectName("nextCardButton");
        nextCardButton->setGeometry(QRect(320, 250, 111, 31));
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName("page");
        balanceInquiryButton = new QPushButton(page);
        balanceInquiryButton->setObjectName("balanceInquiryButton");
        balanceInquiryButton->setGeometry(QRect(30, 110, 171, 31));
        depositMoneyButton = new QPushButton(page);
        depositMoneyButton->setObjectName("depositMoneyButton");
        depositMoneyButton->setGeometry(QRect(30, 170, 171, 31));
        cashWithdrawalButton = new QPushButton(page);
        cashWithdrawalButton->setObjectName("cashWithdrawalButton");
        cashWithdrawalButton->setGeometry(QRect(280, 110, 151, 31));
        transferMoneyButton = new QPushButton(page);
        transferMoneyButton->setObjectName("transferMoneyButton");
        transferMoneyButton->setGeometry(QRect(280, 170, 151, 31));
        exitButton = new QPushButton(page);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(280, 230, 151, 31));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 20, 181, 41));
        changePinButton = new QPushButton(page);
        changePinButton->setObjectName("changePinButton");
        changePinButton->setGeometry(QRect(30, 230, 171, 31));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Welcome to the ATM Machine!", nullptr));
        welcomeNextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enter Your PIN:", nullptr));
        submitPinButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Your Card type :", nullptr));
        silverRadioButton->setText(QCoreApplication::translate("MainWindow", "Silver", nullptr));
        goldRadioButton->setText(QCoreApplication::translate("MainWindow", "Gold", nullptr));
        platinumRadioButton->setText(QCoreApplication::translate("MainWindow", "Platinum", nullptr));
        nextCardButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        balanceInquiryButton->setText(QCoreApplication::translate("MainWindow", "Balance inquiry", nullptr));
        depositMoneyButton->setText(QCoreApplication::translate("MainWindow", "Cash Deposit", nullptr));
        cashWithdrawalButton->setText(QCoreApplication::translate("MainWindow", "Cash Withdrawl", nullptr));
        transferMoneyButton->setText(QCoreApplication::translate("MainWindow", "Funds Transfer", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Select an option:", nullptr));
        changePinButton->setText(QCoreApplication::translate("MainWindow", "Change PIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
