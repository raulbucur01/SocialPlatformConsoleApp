//
// Created by raulb on 5/16/2022.
//

#include "UserService.h"

// parameter constructor
UserService::UserService(UserRepository &ur) {
    this->user_repo = ur;
}

// adds a user to the repo
void UserService::add_user(int id, const string& username) {
    User user_to_add(id,username);
    this->user_repo.add_user(user_to_add);
}

// returns the list of users from the repo
List<User> UserService::get_all() {
    return this->user_repo.get_all();
}

// replaces the user with the specified id from the repo with a new user
void UserService::update_user(int id, int new_id, const string &new_username) {
    List<User> users = this->user_repo.get_all();
    for (int i = 0; i < this->user_repo.get_size(); i++)
        if (users[i].get_id() == id){
            User new_user(new_id, new_username);
            User old_user = users[i];
            this->user_repo.update_user(old_user, new_user);
        }
}

// deletes the user with the specified id from the repo
void UserService::delete_user(int id) {
    List<User> users = this->user_repo.get_all();
    for (int i = 0; i < this->user_repo.get_size(); i++)
        if (users[i].get_id() == id){
            User user_to_delete = users[i];
            this->user_repo.delete_user(user_to_delete);
        }
}

// returns true if the user with the specified id exists in the repo, false otherwise
bool UserService::search_user(int id) {
    List<User> users = this->user_repo.get_all();
    for (int i = 0; i < this->user_repo.get_size(); i++)
        if (users[i].get_id() == id){
            //User user_to_search = users[i];
            //return this->user_repo.search_user(user_to_search);
            return true;
        }
    return false;
}

// returns the user with the specified id
User UserService::get_user_by_id(int id) {
    List<User> users = this->user_repo.get_all();
    for (int i = 0; i < users.size(); i++)
        if (users[i].get_id() == id) {
            return users[i];
        }
    return User();
}

// destructor
UserService::~UserService() = default;

// default constructor
UserService::UserService() = default;
