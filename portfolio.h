#include <unordered_map>
#include "holding.h"

using namespace std;

class Portfolio {
    private:
        unordered_map<string, Holding*> holdings;
        double totalDeposits;
        double cash;
        string actions[7][2] = {{"e", "Exit"}, {"d", "Deposit"}, {"w", "Withdraw"}, {"b", "Buy stock"}, 
                                {"s", "Sell stock"}, {"c", "Calculate profitability"}, {"v", "View portfolio"}};
        int numActions = 7;

        Holding* getHolding(string ticker);

    public:
        Portfolio();
        ~Portfolio();
        void run();
        void displayActions();
        void handleInputs();
        void buyStock();
        void sellStock();
        void deposit();
        void withdraw();
        void showPortfolio();
        void calculateProfitability();

};