#include <iostream>
#include <fstream>
#include <unordered_map>
#include <memory>

#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/archives/json.hpp>

#include "account.h"

using namespace std;

class App {
    private:
        unordered_map<string, shared_ptr<Account>> accounts;
        string actions[3][2] = {{"q", "Quit"}, {"l", "Login"}, {"s", "Sign up"}};
        int numActions = 3;

        void welcome() {
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
                accounts.insert({username, shared_ptr<Account> (new Account(username, password))});
                cout << "Account created" << endl;
            }

        }

        void load() {
            std::ifstream is("data.json");
            cereal::JSONInputArchive input(is);
            input(accounts);
        }

        void save() {
            std::ofstream os("data.json");
            cereal::JSONOutputArchive output(os);
            output(accounts);
        }
        
    public:
        void run() {
            load();
            welcome();
            handleInputs();
            goodBye();
            save();
        }
};

int main() 
{
    App app;
    app.run();
}
