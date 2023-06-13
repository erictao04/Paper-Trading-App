#include <iostream>
#include <unordered_map>
#include "portfolio.h"

using namespace std;

class Account {
    private:
        string username;
        string password;
        string actions[3][2] = {{"l", "Log out"}, {"r", "Reset password"}, {"o", "Open Portfolio"}};
        int numActions = 3;
        Portfolio* portfolio;
        

    public:
        Account(string username, string password);
        ~Account();
        void run();
        void handleInputs();
        void displayActions();
        void openPortfolio();
        void resetPassword();
        string getUsername();
        string getPassword();
};
