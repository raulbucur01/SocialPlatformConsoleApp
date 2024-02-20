//
// Created by raulb on 5/16/2022.
//

#ifndef PROIECTSDA_USERSERVICE_H
#define PROIECTSDA_USERSERVICE_H
#include "../Repository/UserRepository.h"

class UserService {
private:
    UserRepository user_repo;
public:
    UserService();
    explicit UserService(UserRepository&);
    void add_user(int id, const string& username);
    void update_user(int id, int new_id, const string& new_username);
    void delete_user(int id);
    bool search_user(int id);
    User get_user_by_id(int id);
    List<User> get_all();
    ~UserService();
};


#endif //PROIECTSDA_USERSERVICE_H
