// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // PIN Entry
    void on_submitPinButton_clicked();

    // Card Selection
    void on_nextCardButton_clicked();
    void on_welcomeNextButton_clicked();
    // ATM Menu
    void on_balanceInquiryButton_clicked();
    void on_cashWithdrawalButton_clicked();
    void on_depositMoneyButton_clicked();
    void on_transferMoneyButton_clicked();
    void on_changePinButton_clicked();
    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;

    // ATM Variables
    double totalCash = 500000;
    double balance = 80000;
    double totalCashWithdraw = 0;
    double maxDeposit = 0;
    int currentPin = 1234;
    int pinAttempts = 0;

    // Helper Functions
    void loadPin();
    void savePin();
    void loadBalance();
    void saveBalance();
    bool validatePin(int inputPin);
    void showMessage(const QString &title, const QString &message);
};

#endif // MAINWINDOW_H

