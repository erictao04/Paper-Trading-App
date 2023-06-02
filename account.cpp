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

    while (input != "q") {
        // Reset password
        // Open portfolio
        
        displayActions();
        cin >> input;
    }
}

void Account::displayActions() {

}

string Account::getPassword() {
    return password;
}

string Account::getUsername() {
    return username;
}