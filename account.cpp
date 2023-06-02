#include "account.h"

Account::Account(string _username, string _password) {
    username = _username;
    password = _password;
}

void Account::run() {
    handleInputs();
}

void Account::handleInputs() {
    string input;

    displayActions();
    cin >> input;

    while (input != "l") {
        if (input == "r") {
            resetPassword();
        } else if (input == "o") {
            openPortfolio();
        } else {
            cout << input << " is not a valid input" << endl;
        }
        
        displayActions();
        cin >> input;
    }
}

void Account::displayActions() {
    string message = "";

    for (int i = 0; i < numActions; i++) {
        message += "("+ actions[i][0] + ") " + actions[i][1] + ", ";
    }

    cout << message << endl;
}

void Account::openPortfolio() {
    portfolio.run();
}

void Account::resetPassword() {
    string newPassword, newPassword2;

    cout << "Enter new password: ";
    cin >> newPassword;

    cout << "Re-enter new password: ";
    cin >> newPassword2;

    if (newPassword == newPassword2) {
        password = newPassword;
        cout << "Password has been updated" << endl;
    } else {
        cout << "Passwords did not match, password not reset" << endl;
    }
}

string Account::getPassword() {
    return password;
}

string Account::getUsername() {
    return username;
}