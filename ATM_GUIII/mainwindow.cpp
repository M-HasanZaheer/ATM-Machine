// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include<QinputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    // Load PIN and Balance from files
    loadPin();
    loadBalance();

    // Initially show Welcome screen
    stackedWidget->setCurrentIndex(0); // Show the Welcome screen first

    connect(ui->welcomeNextButton, &QPushButton::clicked, this, &MainWindow::on_welcomeNextButton_clicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Helper function to show message boxes
void MainWindow::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}

// Load PIN from file
void MainWindow::loadPin()
{
    QFile pinFile("pin.txt");
    if (pinFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&pinFile);
        in >> currentPin;
        pinFile.close();
    } else {
        currentPin = 1234; // Default PIN
    }
}

// Save PIN to file
void MainWindow::savePin()
{
    QFile pinFile("pin.txt");
    if (pinFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&pinFile);
        out << currentPin;
        pinFile.close();
    } else {
        showMessage("Error", "Failed to save PIN!");
    }
}

// Load Balance from file
void MainWindow::loadBalance()
{
    QFile balanceFile("balance.txt");
    if (balanceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&balanceFile);
        in >> balance;
        balanceFile.close();
    } else {
        balance = 80000; // Default Balance
    }
}

// Save Balance to file
void MainWindow::saveBalance()
{
    QFile balanceFile("balance.txt");
    if (balanceFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&balanceFile);
        out << balance;
        balanceFile.close();
    } else {
        showMessage("Error", "Failed to save balance!");
    }
}

// Validate PIN
bool MainWindow::validatePin(int inputPin)
{
    if (inputPin == currentPin) {
        return true;
    } else {
        pinAttempts++;
        return false;
    }
}

// Slot for Next Button on Welcome Screen
void MainWindow::on_welcomeNextButton_clicked()
{
    // Move to the next page (PIN Entry page)
    stackedWidget->setCurrentIndex(1);
}





// Slot for Submit PIN Button
void MainWindow::on_submitPinButton_clicked()
{
    bool ok;
    int inputPin = ui->pinLineEdit->text().toInt(&ok);
    if (!ok) {
        showMessage("Error", "Please enter a valid PIN.");
        return;
    }

    if (validatePin(inputPin)) {
        showMessage("Success", "PIN validated successfully!");
        stackedWidget->setCurrentIndex(2); // Move to Card Selection
    } else {
        if (pinAttempts >= 3) {
            showMessage("Locked", "Too many incorrect attempts. Try again later.");
            QApplication::quit();
        } else {
            showMessage("Error", "Incorrect PIN. Please try again.");
        }
    }
}

// Slot for Next Button in Card Selection
void MainWindow::on_nextCardButton_clicked()
{
    if (ui->silverRadioButton->isChecked()) {
        totalCashWithdraw = 50000;
        maxDeposit = 50000;
    } else if (ui->goldRadioButton->isChecked()) {
        totalCashWithdraw = 100000;
        maxDeposit = 100000;
    } else if (ui->platinumRadioButton->isChecked()) {
        totalCashWithdraw = 200000;
        maxDeposit = 200000;
    } else {
        showMessage("Error", "Please select a card type.");
        return;
    }
    stackedWidget->setCurrentIndex(3); // Move to ATM Menu
}

// Slot for Balance Inquiry
void MainWindow::on_balanceInquiryButton_clicked()
{
    QString msg = QString("Your Current Balance is: Rs %1").arg(balance);
    showMessage("Balance Inquiry", msg);
}

// Slot for Cash Withdrawal
void MainWindow::on_cashWithdrawalButton_clicked()
{
    bool ok;
    double amount = QInputDialog::getDouble(this, "Cash Withdrawal",
                                            QString("Enter amount to withdraw (Max: Rs %1):").arg(totalCashWithdraw),
                                            0, 0, totalCashWithdraw, 2, &ok);
    if (!ok) return;

    if (amount > balance) {
        showMessage("Error", "Insufficient Balance.");
        return;
    }
    if (amount > totalCashWithdraw) {
        showMessage("Error", QString("Amount should be below Rs %1").arg(totalCashWithdraw));
        return;
    }
    if (amount <= 0) {
        showMessage("Error", "Amount must be positive.");
        return;
    }

    // Perform Withdrawal
    balance -= amount;
    totalCash -= amount;
    saveBalance();
    showMessage("Success", QString("Rs %1 has been withdrawn.\nNew Balance: Rs %2").arg(amount).arg(balance));
}

// Slot for Deposit Money
void MainWindow::on_depositMoneyButton_clicked()
{
    bool ok;
    double amount = QInputDialog::getDouble(this, "Deposit Money",
                                            QString("Enter amount to deposit (Max: Rs %1):").arg(maxDeposit),
                                            0, 0, maxDeposit, 2, &ok);
    if (!ok) return;

    if (amount > maxDeposit) {
        showMessage("Error", QString("Amount should be below Rs %1").arg(maxDeposit));
        return;
    }
    if (amount <= 0) {
        showMessage("Error", "Amount must be positive.");
        return;
    }

    // Perform Deposit
    balance += amount;
    totalCash += amount;
    saveBalance();
    showMessage("Success", QString("Rs %1 has been deposited.\nNew Balance: Rs %2").arg(amount).arg(balance));
}

// Slot for Funds Transfer
void MainWindow::on_transferMoneyButton_clicked()
{
    bool ok;
    int accNum = QInputDialog::getInt(this, "Transfer Money",
                                      "Enter Account Number for transfer:", 0, 0, 999999999, 1, &ok);
    if (!ok) return;
    if (accNum <= 0) {
        showMessage("Error", "Invalid Account Number.");
        return;
    }

    double transferAmount = QInputDialog::getDouble(this, "Transfer Money",
                                                    QString("Enter amount to transfer (Max: Rs %1):").arg(balance),
                                                    0, 0, balance, 2, &ok);
    if (!ok) return;
    if (transferAmount <= 0 || transferAmount > balance) {
        showMessage("Error", "Invalid transfer amount.");
        return;
    }

    // Perform Transfer
    balance -= transferAmount;
    totalCash -= transferAmount;
    saveBalance();
    showMessage("Success", QString("Rs %1 has been transferred to Account Number: %2.\nNew Balance: Rs %3")
                               .arg(transferAmount)
                               .arg(accNum)
                               .arg(balance));
}

// Slot for Change PIN
void MainWindow::on_changePinButton_clicked()
{
    bool ok;
    int oldPin = QInputDialog::getInt(this, "Change PIN", "Enter your old PIN:", 0, 0, 9999, 1, &ok);
    if (!ok) return;
    if (oldPin != currentPin) {
        showMessage("Error", "Incorrect old PIN.");
        return;
    }

    int newPin = QInputDialog::getInt(this, "Change PIN", "Enter your new PIN:", 0, 0, 9999, 1, &ok);
    if (!ok) return;
    int confirmPin = QInputDialog::getInt(this, "Change PIN", "Confirm your new PIN:", 0, 0, 9999, 1, &ok);
    if (!ok) return;

    if (newPin != confirmPin) {
        showMessage("Error", "PINs do not match.");
        return;
    }

    currentPin = newPin;
    savePin();
    showMessage("Success", "Your PIN has been successfully changed.");
}

// Slot for Exit Button
void MainWindow::on_exitButton_clicked()
{
    showMessage("Goodbye", "Thank you for choosing this ATM. Goodbye!");
    QApplication::quit();
}





