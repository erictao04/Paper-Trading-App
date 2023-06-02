#include <iostream>

using namespace std;

class Holding {
    private:
        string ticker;
        int numShares;
        double getSharePrice();
    public:
        Holding(string ticker);
        double sellShare(int numShares);
        void buyShare(int numShares);
        double getCurrentValuation();

};