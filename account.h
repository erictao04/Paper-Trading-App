#include <iostream>
#include "portfolio.h"

using namespace std;

class Account {
    private:
        string username;
        string password;
        

    public:
        Account(string username, string password);
        string getUsername();
        string getPassword();
};
