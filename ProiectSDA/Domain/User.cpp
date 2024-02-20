//
// Created by raulb on 5/16/2022.
//

#include "User.h"

#include <utility>
#include <iostream>

// default constructor
User::User() {
    this->id = 0;
    this->username = "";
}

// parameter constructor
User::User(int id, string username) {
    this->id = id;
    this->username = std::move(username);
}

// returns the id of the user
int User::get_id() {
    return this->id;
}

// returns teh username of the user
string User::get_username() {
    return this->username;
}

// sets the id of the user
void User::set_id(int new_id) {
    this->id = new_id;
}

// sets the username of the user
void User::set_username(string new_username) {
    this->username = std::move(new_username);
}

// overloaded "=" operator
User &User::operator=(const User & u) {
    this->id = u.id;
    this->username = u.username;
    return *this;
}

ostream &operator<<(ostream& os, User& u) {
    os << "Id: " << u.id << " // Username: " << u.username;
    return os;
}

istream &operator>>(istream &is, User& u) {
    is >> u.id >> u.username;
    return is;
}

// returns true if the attributes of 2 users are equal, false otherwise
bool User::operator==(const User& u) {
    return (this->id == u.id && this->username == u.username);
}
