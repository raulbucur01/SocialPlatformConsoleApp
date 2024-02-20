//
// Created by raulb on 5/21/2022.
//

#include "FriendshipService.h"

// default constructor
FriendshipService::FriendshipService() = default;

// destructor
FriendshipService::~FriendshipService() = default;

// gets the friendships in the repo
vector<vector<Friendship>> FriendshipService::get_all() {
    return this->f_repo.get_all();
}

// param constructor
FriendshipService::FriendshipService(FriendshipRepository & fr) {
    this->f_repo = fr;
}

// adds a friendship to the repo
void FriendshipService::add_friendship(int id, int id_u1, int id_u2) {
    Friendship f(id,id_u1,id_u2);
    Friendship f2(id,id_u2,id_u1);
    this->f_repo.add_friendship(f);
    this->f_repo.add_friendship(f2);
}

// deletes a friendship from the repo
void FriendshipService::delete_friendship(int id) {
    vector<vector<Friendship>> friends = this->f_repo.get_all();
    for (auto& t: friends)
        for (auto& elem: t)
            if (elem.get_id() == id){
                Friendship f_to_delete1(elem.get_id(),elem.get_id_user1(),elem.get_id_user2());
                Friendship f_to_delete2(elem.get_id(),elem.get_id_user2(),elem.get_id_user1());
                this->f_repo.delete_friendship(f_to_delete1);
                this->f_repo.delete_friendship(f_to_delete2);
            }
}

// returns the nr of values in the multimap
int FriendshipService::get_size() {
    return this->f_repo.get_size();
}

// returns true if a friendship exists in the multimap
bool FriendshipService::search_friendship(int id) {
    vector<vector<Friendship>> friends = this->f_repo.get_all();
    for (auto& t: friends)
        for (auto& elem: t)
            if (elem.get_id() == id)
                return true;
    return false;
}
