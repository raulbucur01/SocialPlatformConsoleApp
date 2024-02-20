//
// Created by raulb on 5/16/2022.
//

#ifndef PROIECTSDA_USERREPOSITORY_H
#define PROIECTSDA_USERREPOSITORY_H
#include "../Domain/List.h"
#include "../Domain/User.h"

class UserRepository {
private:
    List<User> users;
public:
    UserRepository();
    ~UserRepository();
    void add_user(User& u);
    bool search_user(User& u);
    void update_user(User& old_u, User& new_u);
    void delete_user(User& u);
    int get_size();
    List<User> get_all();
};


#endif //PROIECTSDA_USERREPOSITORY_H
