//
// Created by raulb on 5/21/2022.
//

#include "FriendshipRepository.h"

// default constructor
FriendshipRepository::FriendshipRepository() = default;

// destructor
FriendshipRepository::~FriendshipRepository() = default;

// adds a friendship to the multimap
void FriendshipRepository::add_friendship(Friendship &f) {
    this->friendship_repo.put(f.get_id(), f);
}

// deletes a friendship from the multimap
void FriendshipRepository::delete_friendship(Friendship &f) {
    this->friendship_repo.remove(f.get_id(),f);
}

// returns the nr of elements in the multimap
int FriendshipRepository::get_size() {
    return this->friendship_repo.get_size();
}

// returns a vector of friendships from the multimap
vector<vector<Friendship>> FriendshipRepository::get_all() {
    return this->friendship_repo.get_all();
}
