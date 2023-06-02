#include <iostream>
#include <unordered_map>
#include "portfolio.h"

using namespace std;

class Account {
    private:
        string username;
        string password;
        //Portfolio portfolio;
        

    public:
        Account(string username, string password);
        void run();
        void handleInputs();
        void displayActions();
        string getUsername();
        string getPassword();
};
