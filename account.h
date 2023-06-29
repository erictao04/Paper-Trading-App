#include <unordered_map>
#include <memory>

#include "portfolio.h"

using namespace std;

class Account {
    private:
        string username;
        string password;
        string actions[3][2] = {{"l", "Log out"}, {"r", "Reset password"}, {"o", "Open Portfolio"}};
        int numActions = 3;
        shared_ptr<Portfolio> portfolio;
        

    public:
        Account(string username, string password);
        Account() {}; // necessary for cereal serialization
        void run();
        void handleInputs();
        void displayActions();
        void openPortfolio();
        void resetPassword();
        string getUsername();
        string getPassword();
        
        template <class Archive>
        void serialize( Archive & ar )
        {
        ar( username, password, portfolio );
        }
};
