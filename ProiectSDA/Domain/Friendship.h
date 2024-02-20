//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_FRIENDSHIP_H
#define PROIECTSDA_FRIENDSHIP_H
#include <iostream>
#include "User.h"
using namespace std;

class Friendship {
private:
    int id{};
    int id_user1{};
    int id_user2{};
public:
    Friendship();
    Friendship(int id, int id_u1, int id_u2);
    int get_id();
    int get_id_user1();
    int get_id_user2();
    void set_id(int new_id_f);
    void set_id_user1(int new_id_u1);
    void set_id_user2(int new_id_u2);
    Friendship& operator=(const Friendship& f);
    bool operator==(const Friendship& f);
    friend ostream& operator<<(ostream& os, Friendship& f);
    ~Friendship();
};


#endif //PROIECTSDA_FRIENDSHIP_H
