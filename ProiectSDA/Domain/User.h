//
// Created by raulb on 5/16/2022.
//

#ifndef PROIECTSDA_USER_H
#define PROIECTSDA_USER_H
#include <string>
using namespace std;

class User {
private:
    int id;
    string username;
public:
    User();
    User(int id, string username);
    int get_id();
    string get_username();
    void set_id(int new_id);
    void set_username(string new_username);
    User& operator=(const User& u);
    bool operator==(const User& u);
    friend ostream& operator<<(ostream& os, User& u);
    friend istream& operator>>(istream& is, User& u);
};


#endif //PROIECTSDA_USER_H
