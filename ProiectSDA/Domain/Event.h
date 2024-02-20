//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_EVENT_H
#define PROIECTSDA_EVENT_H
#include <string>
#include "User.h"
#include <vector>
using namespace std;

class Event {
private:
    int id;
    string name;
    string location;
    vector<User> participants;
public:
    Event();
    ~Event();
    Event(int id, string name, string location, vector<User> participants);
    int get_id();
    string get_name();
    string get_location();
    vector<User> get_participants();
    void set_name(string new_name);
    void set_location(string new_location);
    void set_participants(vector<User> new_part);
    void set_id(int new_id);
    Event& operator=(const Event& e);
    bool operator==(const Event& e);
    friend ostream& operator<<(ostream& os, Event& e);
};


#endif //PROIECTSDA_EVENT_H
