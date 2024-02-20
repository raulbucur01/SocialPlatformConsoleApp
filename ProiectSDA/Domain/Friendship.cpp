//
// Created by raulb on 5/21/2022.
//

#include "Friendship.h"

// default constructor
Friendship::Friendship() = default;

// param constructor
Friendship::Friendship(int id, int u1, int u2) {
    this->id = id;
    this->id_user1 = u1;
    this->id_user2 = u2;
}

// overloaded "=" operator
Friendship &Friendship::operator=(const Friendship &f) {
    this->id = f.id;
    this->id_user1 = f.id_user1;
    this->id_user2 = f.id_user2;
    return *this;
}

// true if attributes match
bool Friendship::operator==(const Friendship &f) {
    return ( this->id == f.id && this->id_user1 == f.id_user1 && this->id_user2 == f.id_user2);
}

ostream &operator<<(ostream &os, Friendship &f) {
    os << "Id prietenie: " << f.id << " // User: " << f.id_user1 << " prieten cu user: " << f.id_user2;
    return os;
}

// gets the id of the friendship
int Friendship::get_id() {
    return this->id;
}

// sets the id of the friendship
void Friendship::set_id(int new_id_f) {
    this->id = new_id_f;
}

// gets user1 id
int Friendship::get_id_user1() {
    return this->id_user1;
}

// gets user2 id
int Friendship::get_id_user2() {
    return this->id_user2;
}

// sets user 1 id
void Friendship::set_id_user1(int new_id_u1) {
    this->id_user1 = new_id_u1;
}

// sets user 2 id
void Friendship::set_id_user2(int new_id_u2) {
    this->id_user2 = new_id_u2;
}

// destructor
Friendship::~Friendship() = default;


