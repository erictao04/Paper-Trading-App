#include <iostream>
#include "account.h"

using namespace std;

// create Actions ENUM

int main() 
{
    App app;

    app.run();
}

class App {
    private:
        Account accounts[];

        void welcome() {

        }

        void goodBye() {

        }

        void handleInputs() {
            string input;

            displayActions();
            cin >> input;

            while (input != "q") {
                // Sign up
                // Login
                
                displayActions();
                cin >> input;
            }

        }

        void displayActions() {

        }
    
        void login() {

        }

        void signup() {
            
        }
    public:
        App() {

        }

        void run() {
            welcome();
            handleInputs();
            displayActions();

        }
};