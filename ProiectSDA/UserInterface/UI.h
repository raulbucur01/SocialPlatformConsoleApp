//
// Created by raulb on 5/19/2022.
//

#ifndef PROIECTSDA_UI_H
#define PROIECTSDA_UI_H
#include "../Service/UserService.h"
#include "../Service/MessageService.h"
#include "../Service/EventService.h"
#include "../Service/FriendshipService.h"

class UI {
private:
    UserService user_service;
    MessageService message_service;
    EventService event_service;
    FriendshipService friend_service;
    static void show_menu();
    static void show_user_crud_menu();
    static void show_friendship_crud_menu();
    static void show_message_crud_menu();
    static void show_event_crud_menu();
    void handle_add_user();
    void handle_show_users();
    void handle_delete_user();
    void handle_update_user();
    void handle_add_message();
    void handle_update_message();
    void handle_delete_message();
    void handle_show_messages();
    void handle_show_conversation();
    void handle_add_event();
    void handle_update_event();
    void handle_delete_event();
    void handle_show_events();
    void handle_add_participant_to_event();
    void handle_delete_participant_to_event();
    void handle_add_friendship();
    void handle_delete_friendship();
    void handle_show_friendships();
    void handle_show_friends_of_user();
public:
    explicit UI(UserService&, MessageService&, EventService&, FriendshipService&);
    void run_ui();
    ~UI();
};


#endif //PROIECTSDA_UI_H
