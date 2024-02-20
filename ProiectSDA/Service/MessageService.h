//
// Created by raulb on 5/20/2022.
//

#ifndef PROIECTSDA_MESSAGESERVICE_H
#define PROIECTSDA_MESSAGESERVICE_H
#include "../Repository/MessageRepository.h"
#include <vector>

class MessageService {
private:
    MessageRepository message_repo;
public:
    MessageService();
    explicit MessageService(MessageRepository&);
    void add_message(int id_message, int id_sender, const string& content, int id_receiver);
    void update_message(int id_message, int new_id_message, int new_id_sender, const string& new_content, int new_id_receiver);
    void delete_message(int id_message);
    bool search_message(int id_message);
    vector<Message> get_conversation(int id_sender, int id_receiver);
    List<Message> get_all();
    ~MessageService();
};


#endif //PROIECTSDA_MESSAGESERVICE_H
