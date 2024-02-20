//
// Created by raulb on 5/20/2022.
//

#include "MessageRepository.h"

// default constructor
MessageRepository::MessageRepository() = default;

// destructor
MessageRepository::~MessageRepository() = default;

// adds a message to the message list
void MessageRepository::add_message(Message &m) {
    this->messages.add(m);
}

// returns true if a specified message exists in the message list, false otherwise
bool MessageRepository::search_message(Message &m) {
    return this->messages.search(m);
}

// replaces the specified old message with a new one
void MessageRepository::update_message(Message &old_m, Message &new_m) {
    this->messages.update(old_m, new_m);
}

// deletes a message from the message list
void MessageRepository::delete_message(Message &m) {
    this->messages.remove(m);
}

// returns the number of elements in the message list
int MessageRepository::get_size() {
    return this->messages.size();
}

// returns the list of messages
List<Message> MessageRepository::get_all() {
    return this->messages;
}
