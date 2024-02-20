//
// Created by raulb on 5/17/2022.
//
#include <cassert>
#include <iostream>
#include "../Domain/User.h"
#include "../Repository/UserRepository.h"
#include "../Domain/List.h"
#include "../Service/UserService.h"
#include "../Domain/Message.h"
#include "../Repository/MessageRepository.h"
#include "../Service/MessageService.h"
#include "../Domain/Event.h"
#include "../Repository/EventRepository.h"
#include "../Service/EventService.h"
#include "../Domain/Friendship.h"
#include "../Domain/Multimap.h"
#include "../Repository/FriendshipRepository.h"
#include "../Service/FriendshipService.h"
using namespace std;

// entity tests
void test_user(){
    User user;
    assert(user.get_id() == 0);
    assert(user.get_username().empty());

    user.set_id(1);
    user.set_username("raul807");
    assert(user.get_id() == 1);
    assert(user.get_username() == "raul807");

    User user2(1,"wow123");
    assert(user2.get_id() == 1);
    assert(user2.get_username() == "wow123");
}
void test_message(){
    Message msg;
    assert(msg.get_id_message() == 0);
    assert(msg.get_id_sender() == 0);
    assert(msg.get_id_receiver() == 0);
    assert(msg.get_content().empty());

    msg.set_id_message(1);
    msg.set_id_sender(1);
    msg.set_id_receiver(2);
    msg.set_content("Wow");
    assert(msg.get_id_message() == 1);
    assert(msg.get_id_sender() == 1);
    assert(msg.get_id_receiver() == 2);
    assert(msg.get_content() == "Wow");

    Message msg2(1,2,"Salut",3);
    assert(msg2.get_id_sender() == 2);
    assert(msg2.get_id_receiver() == 3);
    assert(msg2.get_id_message() == 1);
    assert(msg2.get_content() == "Salut");
}

void test_event(){
    Event event;
    assert(event.get_id() == 0);
    assert(event.get_name().empty());
    assert(event.get_location().empty());
    assert(event.get_participants().empty());

    vector<User> participants;
    User u1(1,"raul807");
    User u2(2,"raulraul20");
    participants.push_back(u1);
    participants.push_back(u2);

    event.set_id(2);
    assert(event.get_id() == 2);
    event.set_name("wow");
    assert(event.get_name() == "wow");
    event.set_location("wow2");
    assert(event.get_location() == "wow2");
    event.set_participants(participants);
    assert(event.get_participants().size() == 2);

    Event event2(1,"Joris Voorn", "Form", participants);
    assert(event2.get_id() == 1);
    assert(event2.get_name() == "Joris Voorn");
    assert(event2.get_location() == "Form");
    assert(event2.get_participants().size() == 2);
}

void test_friendship(){
    Friendship f;
    assert(f.get_id() == 0);
    assert(f.get_id_user1() == 0);
    assert(f.get_id_user2() == 0);

    Friendship f2(1,1,2);
    assert(f2.get_id() == 1);
    assert(f2.get_id_user1() == 1);
    assert(f2.get_id_user2() == 2);
    f2.set_id(9);
    assert(f2.get_id() == 9);
    f2.set_id_user1(9);
    assert(f2.get_id_user1() == 9);
    f2.set_id_user2(9);
    assert(f2.get_id_user2() == 9);
}

// repository tests
void test_user_repository(){
    UserRepository ur;
    assert(ur.get_size() == 0);

    User user1(1,"raul807");
    User user2(2,"coco20");
    ur.add_user(user1);
    assert(ur.search_user(user1) == true);
    assert(ur.get_size() == 1);

    ur.add_user(user2);
    assert(ur.search_user(user2) == true);
    assert(ur.get_size() == 2);

    User updated(2,"New_username");
    User old(1,"raul807");
    ur.update_user(old,updated);
    assert(ur.get_all()[0] == updated);

    ur.delete_user(user2);
    assert(ur.search_user(user2) == false);
    assert(ur.get_size() == 1);

    ur.delete_user(updated);
    assert(ur.search_user(updated) == false);
    assert(ur.get_size() == 0);
}

void test_message_repository(){
    MessageRepository mr;
    assert(mr.get_size() == 0);

    Message msg1(1,1,"Salut! Cf?",2);
    Message msg2(2,2,"Bine. Tu?",1);
    mr.add_message(msg1);
    assert(mr.search_message(msg1) == true);
    assert(mr.get_size() == 1);

    mr.add_message(msg2);
    assert(mr.search_message(msg2) == true);
    assert(mr.get_size() == 2);

    mr.delete_message(msg1);
    assert(mr.search_message(msg1) == false);
    assert(mr.get_size() == 1);

    mr.delete_message(msg2);
    assert(mr.search_message(msg2) == false);
    assert(mr.get_size() == 0);

    mr.add_message(msg1);
    assert(mr.search_message(msg1) == true);
    assert(mr.get_size() == 1);

    mr.update_message(msg1,msg2);
    assert(mr.search_message(msg1) == false);
    assert(mr.get_size() == 1);
    assert(mr.search_message(msg2) == true);
}

void test_event_repository(){
    EventRepository er;
    assert(er.get_size() == 0);
    vector<User> participants;
    User u1(1,"raul807");
    User u2(2,"coco20");
    participants.push_back(u1);
    participants.push_back(u2);
    Event e1(1,"Coachella","America", participants);
    Event e2(2,"Name","Loc", participants);

    er.add_event(e1);
    assert(er.search_event(e1) == true);
    assert(er.get_size() == 1);

    er.add_event(e2);
    assert(er.search_event(e2) == true);
    assert(er.get_size() == 2);

    er.delete_event(e1);
    assert(er.search_event(e1) == false);
    assert(er.get_size() == 1);

    er.delete_event(e2);
    assert(er.search_event(e2) == false);
    assert(er.get_size() == 0);

    er.add_event(e1);
    assert(er.search_event(e1) == true);
    assert(er.get_size() == 1);

    er.update_event(e1, e2);
    assert(er.search_event(e1) == false);
    assert(er.get_size() == 1);
    assert(er.search_event(e2) == true);
}

void test_friendship_repository(){
    FriendshipRepository fr;
    assert(fr.get_size() == 0);

    Friendship f(1,1,2);
    Friendship f2(2,1,2);
    fr.add_friendship(f);
    assert(fr.get_size() == 1);
    fr.add_friendship(f2);
    assert(fr.get_size() == 2);

    fr.delete_friendship(f2);
    assert(fr.get_size() == 1);
    fr.delete_friendship(f);
    assert(fr.get_size() == 0);
}

void test_list(){
    List<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    assert(list.size() == 3);
    assert(list.get_from_pos(0) == 1);
    assert(list.get_from_pos(1) == 2);
    assert(list.get_from_pos(2) == 3);
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);

    List<User> list2;
    User user(1,"raul807");
    list2.add(user);
    assert(list2[0].get_id() == 1);
    assert(list2[0].get_username() == "raul807");
}

//service tests
void test_user_service(){
    UserRepository ur;
    UserService us(ur);

    us.add_user(1,"raul807");
    User u(1,"raul807");
    assert(us.get_all().size() == 1);
    assert(us.get_all()[0] == u);
    assert(us.get_all()[0].get_id() == 1);
    assert(us.get_all()[0].get_username() == "raul807");
    assert(us.search_user(1) == true);

    us.add_user(2,"coco20");
    User u2(2,"coco20");
    assert(us.get_all().size() == 2);
    assert(us.get_all()[1] == u2);
    assert(us.get_all()[1].get_id() == 2);
    assert(us.get_all()[1].get_username() == "coco20");
    assert(us.search_user(2) == true);

    us.update_user(1,3,"new_username");
    User updated(3,"new_username");
    assert(us.get_all().size() == 2);
    assert(us.get_all()[0] == updated);
    assert(us.get_all()[0].get_id() == 3);
    assert(us.get_all()[0].get_username() == "new_username");
    assert(us.search_user(3) == true);

    us.delete_user(3);
    assert(us.get_all().size() == 1);
    assert(us.search_user(3) == false);
}

void test_message_service(){
    MessageRepository mr;
    MessageService ms(mr);

    ms.add_message(1, 1, "Salut", 2);
    Message m1(1,1,"Salut",2);
    assert(ms.get_all().size() == 1);
    assert(ms.get_all()[0] == m1);
    assert(ms.get_all()[0].get_id_message() == 1);
    assert(ms.get_all()[0].get_id_sender() == 1);
    assert(ms.get_all()[0].get_id_receiver() == 2);
    assert(ms.get_all()[0].get_content() == "Salut");
    assert(ms.search_message(1) == true);

    ms.add_message(2,2,"Cealut",1);
    Message m2(2,2,"Cealut",1);
    assert(ms.get_all().size() == 2);
    assert(ms.get_all()[1] == m2);
    assert(ms.get_all()[1].get_id_message() == 2);
    assert(ms.get_all()[1].get_id_sender() == 2);
    assert(ms.get_all()[1].get_id_receiver() == 1);
    assert(ms.get_all()[1].get_content() == "Cealut");
    assert(ms.search_message(2) == true);

    ms.delete_message(2);
    assert(ms.get_all().size() == 1);
    assert(ms.search_message(2) == false);

    ms.delete_message(1);
    assert(ms.get_all().size() == 0);
    assert(ms.search_message(1) == false);

    ms.add_message(1,1,"Salut",2);
    ms.update_message(1, 2,2,"Cealut",1);
    assert(ms.get_all().size() == 1);
    assert(ms.get_all()[0] == m2);
    assert(ms.get_all()[0].get_id_message() == 2);
    assert(ms.get_all()[0].get_id_sender() == 2);
    assert(ms.get_all()[0].get_id_receiver() == 1);
    assert(ms.get_all()[0].get_content() == "Cealut");
    assert(ms.search_message(2) == true);
    assert(ms.search_message(1) == false);
}

void test_event_service(){
    EventRepository er;
    UserRepository ur;
    EventService es(er,ur);

    vector<User> part;
    es.add_event(1,"name","loc",part);
    Event e1(1,"name","loc",part);
    assert(es.get_all().size() == 1);
    assert(es.get_all()[0] == e1);
    assert(es.get_all()[0].get_id() == 1);
    assert(es.get_all()[0].get_name() == "name");
    assert(es.get_all()[0].get_location() == "loc");
    assert(es.get_all()[0].get_participants().empty());
    assert(es.search_event(1) == true);

    es.add_event(2,"name2","loc2", part);
    Event e2(2,"name2","loc2", part);
    assert(es.get_all().size() == 2);
    assert(es.get_all()[1] == e2);
    assert(es.get_all()[1].get_id() == 2);
    assert(es.get_all()[1].get_name() == "name2");
    assert(es.get_all()[1].get_location() == "loc2");
    assert(es.get_all()[1].get_participants().empty());
    assert(es.search_event(2) == true);

    es.delete_event(2);
    assert(es.get_all().size() == 1);
    assert(es.search_event(2) == false);

    es.delete_event(1);
    assert(es.get_all().size() == 0);
    assert(es.search_event(1) == false);

    es.add_event(1,"name","loc",part);
    es.update_event(1,2,"name2","loc2", part);
    assert(es.get_all().size() == 1);
    assert(es.get_all()[0] == e2);
    assert(es.get_all()[0].get_id() == 2);
    assert(es.get_all()[0].get_name() == "name2");
    assert(es.get_all()[0].get_location() == "loc2");
    assert(es.get_all()[0].get_participants().empty());
    assert(es.search_event(2) == true);
    assert(es.search_event(1) == false);
}

void test_add_participant_to_event(){
    UserRepository ur;
    EventRepository er;
    vector<User> part;
    User u1(1,"raul807");
    ur.add_user(u1);
    User u2(2,"coco20");
    ur.add_user(u2);
    Event e1(1,"Joris Voorn","Form space",part);
    er.add_event(e1);
    Event e2(2,"Boris","Cluj Arena",part);
    er.add_event(e2);
    EventService es(er,ur);
    es.add_participant_to_event(1,u1);
    List<Event> events = es.get_all();
    assert(events[0].get_participants()[0].get_id() == 1);
    assert(events[0].get_participants()[0].get_username() == "raul807");
    assert(events[0].get_participants().size() == 1);
    es.add_participant_to_event(1,u2);
    assert(events[0].get_participants()[1].get_id() == 2);
    assert(events[0].get_participants()[1].get_username() == "coco20");
    assert(events[0].get_participants().size() == 2);
}

void test_delete_participant_to_event(){
    UserRepository ur;
    EventRepository er;
    vector<User> part;
    User u1(1,"raul807");
    ur.add_user(u1);
    User u2(2,"coco20");
    ur.add_user(u2);
    Event e1(1,"Joris Voorn","Form space",part);
    er.add_event(e1);
    Event e2(2,"Boris","Cluj Arena",part);
    er.add_event(e2);
    EventService es(er,ur);

    es.add_participant_to_event(1,u1);
    List<Event> events = es.get_all();
    assert(events[0].get_participants()[0].get_id() == 1);
    assert(events[0].get_participants()[0].get_username() == "raul807");
    assert(events[0].get_participants().size() == 1);

    es.add_participant_to_event(1,u2);
    assert(events[0].get_participants()[1].get_id() == 2);
    assert(events[0].get_participants()[1].get_username() == "coco20");
    assert(events[0].get_participants().size() == 2);

    es.delete_participant_to_event(1,u1);
    assert(events[0].get_participants()[0].get_id() == 2);
    assert(events[0].get_participants()[0].get_username() == "coco20");
    assert(events[0].get_participants().size() == 1);

    es.delete_participant_to_event(1,u2);
    assert(events[0].get_participants().empty());
}

void test_friendship_service(){
    FriendshipRepository fr;
    FriendshipService fs(fr);
    assert(fs.get_size() == 0);

    fs.add_friendship(1,1,2);
    assert(fs.get_size() == 2);
    fs.add_friendship(2,2,1);
    assert(fs.get_size() == 4);

    fs.delete_friendship(1);
    assert(fs.get_size() == 2);
    fs.delete_friendship(2);
    assert(fs.get_size() == 0);
}

void tests(){
    test_user();
    test_user_repository();
    test_list();
    test_user_service();
    test_message();
    test_message_repository();
    test_message_service();
    test_event();
    test_event_repository();
    test_event_service();
    test_add_participant_to_event();
    test_delete_participant_to_event();
    test_friendship();
    test_friendship_repository();
    test_friendship_service();
    cout << "Am trecut testele!";
}