//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_FRIENDSHIPREPOSITORY_H
#define PROIECTSDA_FRIENDSHIPREPOSITORY_H
#include "../Domain/Multimap.h"
#include "../Domain/User.h"
#include "../Domain/Friendship.h"

class FriendshipRepository {
private:
    Multimap<int,Friendship> friendship_repo;
public:
    FriendshipRepository();
    ~FriendshipRepository();
    void add_friendship(Friendship& f);
    void delete_friendship(Friendship& f);
    int get_size();
    vector<vector<Friendship>> get_all();
};


#endif //PROIECTSDA_FRIENDSHIPREPOSITORY_H
