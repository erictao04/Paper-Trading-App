#include <iostream>

using namespace std;

class Holding {
    private:
        string ticker;
        int numShares;
    public:
        Holding(string ticker);
        Holding() {}; // necessary for cereal serialization
        double sellShare(int numShares);
        double buyShare(int numShares);
        double getCurrentValuation();
        bool exists();
        double getSharePrice();
        int getNumShares();

        template <class Archive>
        void serialize( Archive & ar )
        {
        ar( ticker, numShares );
        }
};