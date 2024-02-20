//
// Created by raulb on 5/21/2022.
//

#include "Event.h"

#include <utility>
#include <iostream>
using namespace std;

// default constructor

Event::Event(){
    this->id = 0;
    this->location = "";
    this->name = "";
}

// destructor
Event::~Event() = default;

// param constructor
Event::Event(int id, string name, string location, vector<User> participants) {
    this->id = id;
    this->name = std::move(name);
    this->location = std::move(location);
    this->participants = std::move(participants);
}

// returns the name of the event
string Event::get_name() {
    return this->name;
}

// returns the location of the event
string Event::get_location() {
    return this->location;
}

// returns the list of participants
vector<User> Event::get_participants() {
    return this->participants;
}

// sets the name of the event
void Event::set_name(string new_name) {
    this->name = std::move(new_name);
}

// sets the name of the location
void Event::set_location(string new_location) {
    this->location = std::move(new_location);
}

// sets the list of participants
void Event::set_participants(vector<User> new_part) {
    this->participants = std::move(new_part);
}

// overloaded "=" operator
Event &Event::operator=(const Event &e) {
    this->id = e.id;
    this->name = e.name;
    this->location = e.location;
    this->participants = e.participants;
    return *this;
}

ostream &operator<<(ostream &os, Event &e) {
    os << "Id eveniment: " << e.id << " // Nume eveniment: " << e.name << " // Locatie: " << e.location;
    return os;
}

// returns the id of the event
int Event::get_id() {
    return this->id;
}

// sets the id of the event
void Event::set_id(int new_id) {
    this->id = new_id;
}

// returns true if the attributes of 2 events match
bool Event::operator==(const Event &e) {
    return (this->name == e.name && this->location == e.location && this->id == e.id);
}
