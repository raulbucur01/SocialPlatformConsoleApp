//
// Created by raulb on 5/16/2022.
//

#include "UserRepository.h"

// adds a user to the user list
void UserRepository::add_user(User &u) {
    this->users.add(u);
}

// returns true if the specified user exists in the user list, false otherwise
bool UserRepository::search_user(User &u) {
    return this->users.search(u);
}

// replaces an old user from the user list with a new one
void UserRepository::update_user(User &old_u, User &new_u) {
    this->users.update(old_u,new_u);
}

// deletes an user from the user list
void UserRepository::delete_user(User& u) {
    this->users.remove(u);
}

// returns the list of users
List<User> UserRepository::get_all() {
    return this->users;
}

// returns the number of users in the user list
int UserRepository::get_size() {
    return this->users.size();
}

// destructor
UserRepository::~UserRepository() = default;

// default constructor
UserRepository::UserRepository() = default;
