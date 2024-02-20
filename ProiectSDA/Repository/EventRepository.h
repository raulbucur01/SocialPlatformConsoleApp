//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_EVENTREPOSITORY_H
#define PROIECTSDA_EVENTREPOSITORY_H
#include "../Domain/Event.h"
#include "../Domain/List.h"

class EventRepository {
private:
    List<Event> events;
public:
    EventRepository();
    ~EventRepository();
    void add_event(Event& e);
    bool search_event(Event& e);
    void update_event(Event& old_e, Event& new_e);
    void delete_event(Event& e);
    int get_size();
    List<Event> get_all();
};


#endif //PROIECTSDA_EVENTREPOSITORY_H
