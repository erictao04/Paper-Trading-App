#include "portfolio.h"

Portfolio::Portfolio() {
    totalDeposits = 0;
    cash = 0;
}

Portfolio::~Portfolio() {
    for (auto holding : holdings) {
        delete holding.second;
    }
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
        } else if (input == "v") {
            showPortfolio();
        } else {
            cout << input << " is not a valid input" << endl;
        }
        
        displayActions();
        cin >> input;
    }
}

void Portfolio::calculateProfitability() {
    double portfolioValue = cash;

    for (auto holding : holdings) {
        portfolioValue += holding.second->getCurrentValuation();
    }

    double profit = portfolioValue - totalDeposits;
    cout << "Total profit: $" << profit << endl;
    cout << "Total profit: %" << profit / totalDeposits * 100 << endl;
}

Holding* Portfolio::getHolding(string ticker) {
    if (holdings.count(ticker) == 1) {
        return holdings.at(ticker);
    } else {
        Holding* holding = new Holding(ticker);
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

    Holding* holding = getHolding(ticker);
    double cost = holding->buyShare(numShares);

    cash -= cost;
    cout << "Bought " << numShares << " of " << ticker << endl;

}

void Portfolio::sellStock() {
    // TODO guard against stocks that don't exist
    string ticker;
    int numShares;

    cout << "Enter ticker: ";
    cin >> ticker;

    cout << "Enter number of shares: ";
    cin >> numShares;

    Holding* holding = getHolding(ticker);

    if (numShares < 0) {
        cout << "Can't sell negative number of shares" << endl;
    } else if (!holding->exists()) {
        cout << "Ticker " << ticker << " doesn't exist" << endl;
    } else if (numShares > holding->getNumShares()) {
        cout << "Don't own enough shares" << endl;
    } else {
        double sales = holding->sellShare(numShares);
        cash += sales;
        cout << "Sold " << numShares << " of " << ticker << endl;
    }

    cout << "Updated number of shares: " << holding->getNumShares() << endl;
    cout << "Updated valuation of shares: $" << holding->getCurrentValuation() << endl;
}

void Portfolio::withdraw() {
    double amount;

    cout << "Withdraw amount: $";
    cin >> amount;

    if (amount < 0) {
        cout << "Can't withdraw negative amount" << endl;
    }
    else if (amount > cash) {
        cout << "Not enough cash to withdraw" << endl;
    } else {
        totalDeposits -= amount;
        cash -= amount;

        cout << "Withdrew $" << amount << endl;
    }

    cout << "Updated account balance: $" << cash << endl;
}

void Portfolio::deposit() {
    double amount;

    cout << "Enter amount: $";
    cin >> amount;

    if (amount < 0) {
        cout << "Can't deposit negative amount" << endl;
    } else {
        totalDeposits += amount;
        cash += amount;

        cout << "Deposited $" << amount << endl;
    }

    cout << "Updated account balance: $" << cash << endl;
}

void Portfolio::showPortfolio() {
    double portfolioValue = cash;

    cout << "Cash: $" << cash << endl;

    for (auto holding : holdings) {
        double value = holding.second->getCurrentValuation();
        cout << holding.first << ": $" << value << endl;
        portfolioValue += value;
    }

    cout << "Total portfolio value: $" << portfolioValue << endl;
}
