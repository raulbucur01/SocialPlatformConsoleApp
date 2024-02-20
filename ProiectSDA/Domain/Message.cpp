//
// Created by raulb on 5/20/2022.
//

#include "Message.h"

#include <utility>

// default constructor
Message::Message(){
    this->id_message = 0;
    this->id_sender = 0;
    this->content = "";
    this->id_receiver = 0;
};

// parameter constructor
Message::Message(int id_message, int id_sender, string msg, int id_receiver) {
    this->id_message = id_message;
    this->id_sender = id_sender;
    this->content = std::move(msg);
    this->id_receiver = id_receiver;
}

// returns the id of the message
int Message::get_id_message() {
    return this->id_message;
}

// returns the id of the sender
int Message::get_id_sender() {
    return this->id_sender;
}

// returns the content of the message
string Message::get_content() {
    return this->content;
}

// returns the id of the receiver
int Message::get_id_receiver() {
    return this->id_receiver;
}

// sets the id of the message
void Message::set_id_message(int new_id_message) {
    this->id_message = new_id_message;
}

// sets the id of the sender
void Message::set_id_sender(int new_id_sender) {
    this->id_sender = new_id_sender;
}

// sets the content of the message
void Message::set_content(string new_content) {
    this->content = std::move(new_content);
}

// sets the id of the receiver
void Message::set_id_receiver(int new_id_receiver) {
    this->id_receiver = new_id_receiver;
}

// overloaded "=" operator
Message &Message::operator=(const Message &m) {
    this->id_message = m.id_message;
    this->id_sender = m.id_sender;
    this->content = m.content;
    this->id_receiver = m.id_receiver;
    return *this;
}

// returns true if the attributes of 2 messages are equal, false otherwise
bool Message::operator==(const Message &m) {
    return (this->id_message == m.id_message &&
    this->id_sender == m.id_sender && this->id_receiver == m.id_receiver && this->content == m.content);
}

ostream &operator<<(ostream &os, Message &m) {
    os << "Id: " << m.id_message << " // Id expeditor: " << m.id_sender << " // Mesaj: " << m.content << " // Id destinatar: " << m.id_receiver;
    return os;
}

istream &operator>>(istream &is, Message &m) {
    is >> m.id_message >> m.id_sender >> m.content >> m.id_receiver;
    return is;
}

// destructor
Message::~Message() = default;