#include <unordered_map>
#include <memory>

#include "holding.h"

using namespace std;

class Portfolio {
    private:
        unordered_map<string, shared_ptr<Holding>> holdings;
        double totalDeposits;
        double cash;
        string actions[7][2] = {{"e", "Exit"}, {"d", "Deposit"}, {"w", "Withdraw"}, {"b", "Buy stock"}, 
                                {"s", "Sell stock"}, {"c", "Calculate profitability"}, {"v", "View portfolio"}};
        int numActions = 7;

        shared_ptr<Holding> getHolding(string ticker);
        bool sufficientFunds(int numShares, shared_ptr<Holding> holding);

    public:
        Portfolio();
        void run();
        void displayActions();
        void handleInputs();
        void buyStock();
        void sellStock();
        void deposit();
        void withdraw();
        void showPortfolio();
        void calculateProfitability();
        
        template <class Archive>
        void serialize( Archive & ar )
        {
        ar( totalDeposits, cash, holdings );
        }
};