//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_EVENTSERVICE_H
#define PROIECTSDA_EVENTSERVICE_H
#include "../Domain/Event.h"
#include "../Repository/EventRepository.h"
#include "../Repository/UserRepository.h"

class EventService {
private:
    EventRepository event_repo;
    UserRepository user_repo;
public:
    EventService();
    explicit EventService(EventRepository&, UserRepository&);
    void add_event(int id_event, const string& name, const string& location, vector<User> participants);
    void update_event(int id_event, int new_id_event, const string& new_name, const string& new_location, vector<User> new_participants);
    void delete_event(int id_event);
    bool search_event(int id_event);
    void add_participant_to_event(int id_event, User& participant_to_add);
    void delete_participant_to_event(int id_event, User& participant_to_delete);
    List<Event> get_all();
    ~EventService();
};


#endif //PROIECTSDA_EVENTSERVICE_H
