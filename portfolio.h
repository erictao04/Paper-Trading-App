#include <unordered_map>
#include "holding.h"

using namespace std;

class Portfolio {
    private:
        unordered_map<string, Holding> holdings;
        double totalDeposits;
        double cash;

    public:
        Portfolio();
        void run();
        void handleInputs();
        int calculateProfitability();
        void buyStock(string ticker);
        void sellStock(string ticker);

};