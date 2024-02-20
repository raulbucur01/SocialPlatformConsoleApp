//
// Created by raulb on 5/20/2022.
//

#ifndef PROIECTSDA_MESSAGE_H
#define PROIECTSDA_MESSAGE_H
#include <iostream>
using namespace std;

class Message {
private:
    int id_message;
    int id_sender;
    string content;
    int id_receiver;
public:
    Message();
    Message(int id_message, int id_sender, string content, int id_receiver);
    int get_id_message();
    int get_id_sender();
    string get_content();
    int get_id_receiver();
    void set_id_message(int new_id_message);
    void set_id_sender(int new_id_receiver);
    void set_content(string new_content);
    void set_id_receiver(int new_id_receiver);
    Message& operator=(const Message& f);
    bool operator==(const Message& f);
    friend ostream& operator<<(ostream& os, Message& f);
    friend istream& operator>>(istream& is, Message& f);
    ~Message();
};


#endif //PROIECTSDA_MESSAGE_H
