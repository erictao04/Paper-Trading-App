#include <iostream>
#include <unordered_map>
#include "account.h"
// #include <sqlite3.h>

using namespace std;

// create Actions ENUM

class App {
    private:
        unordered_map<string, Account*> accounts;
        string actions[3][2] = {{"q", "Quit"}, {"l", "Login"}, {"s", "Sign up"}};
        int numActions = 3;

        void welcome() {
//   std::cout << sqlite3_libversion() << '\n';
            cout << "Welcome to Tao's Brokerage!" << endl;
        }



        void goodBye() {
            cout << "Good bye!" << endl;
        }

        void handleInputs() {
            string input;

            displayActions();
            cin >> input;

            while (input != "q") {
                if (input == "l") {
                    login();
                } else if (input == "s") {
                    signup();
                } else {
                    cout << input << " is not a valid input" << endl;
                }
                
                displayActions();
                cin >> input;
            }

        }

        void displayActions() {
            string message = "";

            for (int i = 0; i < numActions; i++) {
                message += "("+ actions[i][0] + ") " + actions[i][1] + ", ";
            }

            cout << message << endl;
        }
    
        void login() {
            string username, password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            if (accounts.count(username) == 1 && accounts.at(username)->getPassword() == password) {
                cout << "Login successful" << endl;
                
                accounts.at(username)->run();
            } else {
                cout << "Incorrect username or password" << endl;
            }
        }

        void signup() {
            string username, password;

            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            if (accounts.count(username) == 1) {
                cout << "Account already exists" << endl;
            } else {
                Account* account = new Account(username, password);

                accounts.insert({username, account});
                cout << "Account created" << endl;
            }

        }
        
    public:
        void run() {
            welcome();
            handleInputs();
            goodBye();

        }

        ~App() {
            cout << "destroting app " << endl;
            // TODO release memory
        }
};

int main() 
{
    App app;

    app.run();
}
