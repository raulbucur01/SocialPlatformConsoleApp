//
// Created by raulb on 5/21/2022.
//

#include "EventService.h"
#include <utility>

// default constructor
EventService::EventService() = default;

// destructor
EventService::~EventService() = default;

// adds an event to the event repo
void EventService::add_event(int id_event, const string &name, const string &location, vector<User> participants) {
    Event event_to_add(id_event, name, location, std::move(participants));
    this->event_repo.add_event(event_to_add);
}

// updates an event with the specified id
void EventService::update_event(int id_event, int new_id_event, const string &new_name, const string &new_location,
                                vector<User> new_participants) {
    List<Event> events = this->event_repo.get_all();
    Event new_event(new_id_event, new_name, new_location, std::move(new_participants));
    for (int i = 0; i < this->event_repo.get_size(); i++)
        if (events[i].get_id() == id_event) {
            Event old_event = events[i];
            this->event_repo.update_event(old_event, new_event);
        }
    }

// deletes an event from the repo
void EventService::delete_event(int id_event) {
    List<Event> events = this->event_repo.get_all();
    for (int i = 0; i < this->event_repo.get_size(); i++)
        if (events[i].get_id() == id_event) {
            Event event_to_delete = events[i];
            this->event_repo.delete_event(event_to_delete);
        }
    }

// true if specified by id event is found, false otherwise
bool EventService::search_event(int id_event) {
    List<Event> events = this->event_repo.get_all();
    for (int i = 0; i < this->event_repo.get_size(); i++)
        if (events[i].get_id() == id_event){
            //Event event_to_search = events[i];
            //return this->event_repo.search_event(event_to_search);
            return true;
        }
    return false;
}

// returns the list of events from the repo
List<Event> EventService::get_all() {
    return this->event_repo.get_all();
}

// adds participant_to_add to the specified by id event
void EventService::add_participant_to_event(int id_event, User& participant_to_add) {
    List<Event> events = this->event_repo.get_all();
    for (int i = 0; i < events.size(); i++)
        if (events[i].get_id() == id_event) {
            Event old_e = events[i];
            Event new_e = events[i];
            vector<User> part = new_e.get_participants();
            part.push_back(participant_to_add);
            new_e.set_participants(part);
            this->event_repo.update_event(old_e, new_e);
        }
}


// deletes participant_to_delete from the specified by id event
void EventService::delete_participant_to_event(int id_event, User& participant_to_delete) {
    List<Event> events = this->event_repo.get_all();
    for (int i = 0; i < events.size(); i++)
        if (events[i].get_id() == id_event){
            Event old_e = events[i];
            Event new_e = events[i];

            vector<User> part = new_e.get_participants();
            int pos = 0;
            for (int j = 0; j < part.size(); j++)
                if (part[j] == participant_to_delete)
                    pos = j;

            part.erase(part.begin() + pos);
            new_e.set_participants(part);
            this->event_repo.update_event(old_e,new_e);
        }
}

// param constructor
EventService::EventService(EventRepository& er, UserRepository& ur) {
    this->event_repo = er;
    this->user_repo = ur;
}
