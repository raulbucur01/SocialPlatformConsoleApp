//
// Created by raulb on 5/21/2022.
//

#include "EventRepository.h"

// default constructor
EventRepository::EventRepository() = default;

// destructor
EventRepository::~EventRepository() = default;

// adds an event to the event list
void EventRepository::add_event(Event &e) {
    this->events.add(e);
}

// returns true if the specified event exists in the event list
bool EventRepository::search_event(Event &e) {
    return this->events.search(e);
}

// replaces an old event with a new one
void EventRepository::update_event(Event &old_e, Event &new_e) {
    this->events.update(old_e,new_e);
}

// deletes an event from the event list
void EventRepository::delete_event(Event &e) {
    this->events.remove(e);
}

// returns the number of elements in the event list
int EventRepository::get_size() {
    return this->events.size();
}

// returns the event list
List<Event> EventRepository::get_all() {
    return this->events;
}




