//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_FRIENDSHIPSERVICE_H
#define PROIECTSDA_FRIENDSHIPSERVICE_H
#include "../Domain/Friendship.h"
#include "../Repository/FriendshipRepository.h"

class FriendshipService {
private:
    FriendshipRepository f_repo;
public:
    FriendshipService();
    explicit FriendshipService(FriendshipRepository&);
    void add_friendship(int id, int id_u1, int id_u2);
    void delete_friendship(int id);
    vector<vector<Friendship>> get_all();
    int get_size();
    bool search_friendship(int id);
    ~FriendshipService();
};


#endif //PROIECTSDA_FRIENDSHIPSERVICE_H
