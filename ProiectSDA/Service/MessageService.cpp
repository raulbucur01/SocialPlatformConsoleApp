//
// Created by raulb on 5/20/2022.
//

#include "MessageService.h"

// default constructor
MessageService::MessageService() = default;

// destructor
MessageService::~MessageService() = default;

// parameter constructor
MessageService::MessageService(MessageRepository &m_repo) {
    this->message_repo = m_repo;
}

// adds a message to the repo
void MessageService::add_message(int id_message, int id1, const string &content, int id2) {
    Message message_to_add(id_message,id1,content,id2);
    this->message_repo.add_message(message_to_add);
}

// deletes the message with the specified id from the repo
void MessageService::delete_message(int id_message) {
    List<Message> messages = this->message_repo.get_all();
    for (int i = 0; i < this->message_repo.get_size(); i++)
        if (messages[i].get_id_message() == id_message){
            Message message_to_delete = messages[i];
            this->message_repo.delete_message(message_to_delete);
        }
}

// returns true if the message with the specified id exists in the repo, false otherwise
bool MessageService::search_message(int id_message) {
    List<Message> messages = this->message_repo.get_all();
    for (int i = 0; i < this->message_repo.get_size(); i++)
        if (messages[i].get_id_message() == id_message){
            //Message message_to_search = messages[i];
            //return this->message_repo.search_message(message_to_search);
            return true;
        }
    return false;
}

// returns the list of messages in the repo
List<Message> MessageService::get_all() {
    return this->message_repo.get_all();
}

// replaces the message with the specified id with a new message
void MessageService::update_message(int id_message, int new_id_message, int new_id_sender, const string& new_content, int new_id_receiver) {
    List<Message> messages = this->message_repo.get_all();
    Message new_message(new_id_message,new_id_sender,new_content,new_id_receiver);
    for (int i = 0; i < this->message_repo.get_size(); i++)
        if (messages[i].get_id_message() == id_message){
            Message old_message = messages[i];
            this->message_repo.update_message(old_message,new_message);
        }
}

// returns a vector containing the messages between two users
vector<Message> MessageService::get_conversation(int id_sender, int id_receiver) {
    List<Message> messages = this->message_repo.get_all();
    vector<Message> result;
    for (int i = 0; i < messages.size(); i++)
        if ((messages[i].get_id_sender() == id_sender && messages[i].get_id_receiver() == id_receiver) ||
                (messages[i].get_id_sender() == id_receiver && messages[i].get_id_receiver() == id_sender))
            result.push_back(messages[i]);
    return result;
}
