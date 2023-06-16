#include <iostream>
#include <string>

using namespace std;

class RequestException : public exception {
    public:
        char * what () {
        return "Failed to fetch stock price";
    }

};
