#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    virtual void signup() = 0;
    virtual bool login() = 0;
    string getUsername() const { return username; }
};

#endif