//
// Created by raulb on 5/20/2022.
//

#ifndef PROIECTSDA_MESSAGEREPOSITORY_H
#define PROIECTSDA_MESSAGEREPOSITORY_H
#include "../Domain/List.h"
#include "../Domain/Message.h"
using namespace std;

class MessageRepository {
private:
    List<Message> messages;
public:
    MessageRepository();
    ~MessageRepository();
    void add_message(Message& m);
    bool search_message(Message& m);
    void update_message(Message& old_m, Message& new_m);
    void delete_message(Message& m);
    int get_size();
    List<Message> get_all();
};


#endif //PROIECTSDA_MESSAGEREPOSITORY_H
