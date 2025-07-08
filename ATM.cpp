#include<iostream>
#include<fstream>
using namespace std;

// Global variables for balance, ATM cash, and PIN
double totalcash = 500000;
double balance = 80000;
double totalcashwithdraw = 0;
double maxdeposit = 0;
int currentpin = 1234;

// Load PIN from file if it exists, else use default PIN
void loadPin() {
    ifstream pinFile("pin.txt");
    if (pinFile.is_open()) {
        pinFile >> currentpin;
        pinFile.close();
    }
    else {
        currentpin = 1234;
    }
}

// Save current PIN to file
void savepin() {
    ofstream pinFile("pin.txt");
    if (pinFile.is_open()) {
        pinFile << currentpin;
        pinFile.close();
    }
    else {
        cout << "Error saving PIN!" << endl;
    }
}

// Load balance from file if it exists, else use default balance
void loadBalance() {
    ifstream balanceFile("balance.txt");
    if (balanceFile.is_open()) {
        balanceFile >> balance;
        balanceFile.close();
    }
    else {
        balance = 80000;
    }
}

// Save current balance to file
void saveBalance() {
    ofstream balanceFile("balance.txt");
    if (balanceFile.is_open()) {
        balanceFile << balance;
        balanceFile.close();
    }
    else {
        cout << "Error saving balance!" << endl;
    }
}

// Validate user PIN by allowing up to 3 attempts
int validatepin() {
    int inputpin;
    cout << "\n\n Please Enter your pin: ";
    cin >> inputpin;

    for (int attempt = 1; attempt <= 3; attempt++) {
        if (currentpin == inputpin) {
            cout << "\nPin Validated successfully";
            return 1;
        }
        else {
            cout << "Incorrect Pin!";
            cout << "\nPlease Enter the pin again : ";
            cin >> inputpin;
        }
        if (attempt == 3) {
            cout << "You have entered wrong pin multiple time";
            cout << "\nTry again later";
            exit(0);
        }
    }
}

// Select card type and set withdrawal and deposit limits based on the card type
int cardselection() {
    int cardtype;
    cout << "\n\nSelect your card type";
    cout << "\n1.Silver";
    cout << "\n2.Gold";
    cout << "\n3.Platinum";
    do {
        cout << "\nEnter the type: ";
        cin >> cardtype;
        switch (cardtype) {
        case 1:
            totalcashwithdraw = 50000;
            maxdeposit = 50000;
            break;
        case 2:
            totalcashwithdraw = 100000;
            maxdeposit = 100000;
            break;
        case 3:
            totalcashwithdraw = 200000;
            maxdeposit = 200000;
            break;
        default:
            cout << "Invalid!";
        }
    } while (cardtype != 1 && cardtype != 2 && cardtype != 3);
    return totalcashwithdraw;
}

// Display ATM menu options
void displaymenu() {
    cout << "\nATM MENU: ";
    cout << "\n\n1. Balance Inquiry" << "\t" << "2. Cash Withdrawl";
    cout << "\n\n3. Deposit Money  " << "\t" << "4. Transfer Money";
    cout << "\n\n5. Change Pin     " << "\t" << "6. Exit          ";
}

// Show current account balance
void balanceinquiry() {
    cout << "\nYour Current Balance is: " << balance;
}

// Withdraw cash from ATM with checks for balance and limits
void cashwithdraw() {
    double amountwithdraw;
    cout << "\nEnter amount for withdrawl (Max:" << totalcashwithdraw << "): ";
    cin >> amountwithdraw;
    string choice;

    if (totalcash == 0) {
        cout << "ATM is out of cash!";
        exit(0);
    }

    while (amountwithdraw > totalcashwithdraw) {
        if (amountwithdraw > balance) {
            cout << "Insufficient Balance" << endl;
        }
        if (amountwithdraw > totalcashwithdraw) {
            cout << "Amount should be below " << totalcashwithdraw;
        }
        cout << "\nDo you want to enter again (yes/no): ";
        cin >> choice;
        if (choice == "yes" || choice == "Yes") {
            cout << "Enter amount again(Max:" << totalcashwithdraw << "): ";
            cin >> amountwithdraw;
        }
        else {
            cout << "Thank you for choosing this ATM";
            exit(0);
        }
    }
    while (amountwithdraw < 0) {
        cout << "Cannot be negative";
        cout << "\nEnter amount again(Max:" << totalcashwithdraw << "): ";
        cin >> amountwithdraw;
    }
    if (amountwithdraw <= balance && amountwithdraw < totalcashwithdraw) {
        balance = balance - amountwithdraw;
        totalcash = totalcash - amountwithdraw;
        cout << amountwithdraw << " is being withdrawn";
        cout << "\nYour new balance is: " << balance;
        saveBalance();
    }
}

// Deposit cash into the account with checks for limits
void cashdeposit() {
    string depositchoice;
    double cashdeposit;
    cout << "Enter amount you want to deposit(Max:" << maxdeposit << "):";
    cin >> cashdeposit;

    while (cashdeposit > maxdeposit) {
        cout << "Amount should be below " << maxdeposit;
        cout << "\nDo you want to enter again (yes/no): ";
        cin >> depositchoice;
        if (depositchoice == "yes" || depositchoice == "Yes") {
            cout << "Enter amount again(Max:" << maxdeposit << "): ";
            cin >> cashdeposit;
        }
        else {
            cout << "Thank you for choosing this ATM";
            exit(0);
        }
    }
    while (cashdeposit < 0) {
        cout << "Cannot be negative";
        cout << "\nEnter amount again(Max:" << maxdeposit << "): ";
        cin >> cashdeposit;
    }
    if (cashdeposit <= maxdeposit) {
        balance = balance + cashdeposit;
        totalcash = totalcash + cashdeposit;
        cout << cashdeposit << " is being deposited";
        cout << "\nYour new balance is: " << balance;
        saveBalance();
    }
}

// Transfer funds to another account with checks for valid amounts
void fundstransfer() {
    int accnum, transferamount;
    cout << "\nEnter the Account number for transfer: ";
    cin >> accnum;
    while (accnum < 0) {
        cout << "Can not be negative!";
        cout << "\nEnter the Account number again for transfer: ";
        cin >> accnum;
    }
    cout << "\nEnter the Amount for transfer: ";
    cin >> transferamount;
    while (transferamount < 0 || transferamount > balance) {
        cout << "Invalid Amount!";
        cout << "\nEnter the Amount again for transfer: ";
        cin >> transferamount;
    }
    if (transferamount <= balance) {
        balance = balance - transferamount;
        totalcash = totalcash - transferamount;
        cout << "Transferring Rs= " << transferamount << " \nto Account Number: " << accnum;
        cout << "\nTransferred...";
        cout << "\nYour new balance is: " << balance;
        saveBalance();
    }
    else {
        cout << "Invalid data";
    }
}

// Change the PIN with confirmation and validation
void changepin() {
    int oldpin, newpin, confirmpin;
    cout << "\nEnter your old PIN: ";
    cin >> oldpin;

    while (oldpin != currentpin) {
        cout << "Incorrect old PIN. Please try again.\n";
        cout << "\nEnter your old PIN again: ";
        cin >> oldpin;
    }
    cout << "Enter your new PIN: ";
    cin >> newpin;

    cout << "Confirm your new PIN: ";
    cin >> confirmpin;
    if (newpin == confirmpin) {
        currentpin = newpin;
        savepin();
        cout << "Your PIN has been successfully changed.\n";
    }
    while (newpin != confirmpin) {
        cout << "\nDoes not match";
        cout << "\nConfirm your new PIN again: ";
        cin >> confirmpin;
    }
}

// Main function to control the flow of the ATM operations
int main() {
    int choice;
    string selection;
    cout << "Welcome to the ATM";
    loadPin(); // Load PIN from file
    validatepin(); // Validate PIN
    loadBalance(); // Load balance from file
    cardselection(); // Select card type
    do {
        displaymenu(); // Show menu options
        cout << "\n\n Enter Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            balanceinquiry(); // Show balance
            break;
        case 2:
            cashwithdraw(); // Withdraw cash
            break;
        case 3:
            cashdeposit(); // Deposit cash
            break;
        case 4:
            fundstransfer(); // Transfer funds
            break;
        case 5:
            changepin(); // Change PIN
            break;
        case 6:
            return 0; // Exit program
            break;
        default:
            cout << "Invalid data";
            break;
        }
        cout << "\nDo You want to make another transaction(Yes/No): ";
        cin >> selection;
    } while (selection != "No" && selection != "no"); // Repeat until 'No' is selected
    return 0;
}
