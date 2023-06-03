#include "portfolio.h"

Portfolio::Portfolio() {
    totalDeposits = 0;
    cash = 0;
}

void Portfolio::run() {
    handleInputs();
}

void Portfolio::displayActions() {
    string message = "";

    for (int i = 0; i < numActions; i++) {
        message += "("+ actions[i][0] + ") " + actions[i][1] + ", ";
    }

    cout << message << endl;
}


void Portfolio::handleInputs() {
    string input;

    displayActions();
    cin >> input;

    while (input != "e") {
        if (input == "d") {
            deposit();
        } else if (input == "w") {
            withdraw();
        } else if (input == "b") {
            buyStock();
        } else if (input == "s") {
            sellStock();
        } else if (input == "c") {
            calculateProfitability();
        } else {
            cout << input << " is not a valid input" << endl;
        }
        
        displayActions();
        cin >> input;
    }
}

void Portfolio::calculateProfitability() {
    unordered_map<string, Holding>::iterator it;
    double portfolioValue = cash;

    for (it = holdings.begin(); it != holdings.end(); it++) {
        portfolioValue += it->second.getCurrentValuation();
    }

    double profit = portfolioValue - totalDeposits;
    cout << "Total profit: $" << profit << endl;
    cout << "Total profit: %:" << profit / totalDeposits * 100 << endl;
}

Holding Portfolio::getHolding(string ticker) {
    if (holdings.count(ticker) == 1) {
        return holdings.at(ticker);
    } else {
        Holding holding(ticker);
        holdings.insert({ticker, holding});

        return holding;
    }
}

void Portfolio::buyStock() {
    // TODO add catch for negative amounts and over
    string ticker;
    int numShares;

    cout << "Enter ticker: ";
    cin >> ticker;

    cout << "Enter number of shares: ";
    cin >> numShares;

    Holding holding = getHolding(ticker);
    double cost = holding.buyShare(numShares);

    cash -= cost;
    cout << "Bought " << numShares << " of " << ticker << endl;

}

void Portfolio::sellStock() {
    // TODO add catch for negative amounts and over
    string ticker;
    int numShares;

    cout << "Enter ticker: ";
    cin >> ticker;

    cout << "Enter number of shares: ";
    cin >> numShares;

    Holding holding = getHolding(ticker);
    double sales = holding.sellShare(numShares);

    cash += sales;

    cout << "Sold " << numShares << " of " << ticker << endl;
}

void Portfolio::withdraw() {
    // TODO add catch for negative amounts
    double amount;

    cout << "Withdraw amount: $";
    cin >> amount;

    totalDeposits -= amount;
    cash -= amount;

    cout << "Withdrew from account" << endl;

}

void Portfolio::deposit() {
    // TODO add catch for negative amounts
    double amount;

    cout << "Enter amount: $";
    cin >> amount;

    totalDeposits += amount;
    cash += amount;

    cout << "Deposited into account" << endl;
}
