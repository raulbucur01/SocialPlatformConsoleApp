//
// Created by raulb on 5/19/2022.
//

#include <iostream>
#include "UI.h"
// parameter constructor
UI::UI(UserService & us, MessageService & ms, EventService & es, FriendshipService & fs) {
    this->user_service = us;
    this->message_service = ms;
    this->event_service = es;
    this->friend_service = fs;
}

// runs the User Interface
void UI::run_ui() {
    while (true){
        show_menu();
        cout << "Alege o optiune: ";
        string opt;
        cin >> opt;
        if (opt == "1"){
            while (true){
                show_user_crud_menu();
                cout << "Alege o optiune: ";
                string opt2;
                cin >> opt2;
                if (opt2 == "1")
                    handle_add_user();

                else if (opt2 == "2")
                    handle_update_user();

                else if (opt2 == "3")
                    handle_delete_user();

                else if (opt2 == "a")
                    handle_show_users();

                else if (opt2 == "x")
                    break;

                else
                    cout << "Optiune invalida!" << endl;
            }
        }

        else if (opt == "2"){
            while (true){
                show_message_crud_menu();
                cout << "Alege o optiune: ";
                string opt3;
                cin >> opt3;
                if (opt3 == "1")
                    handle_add_message();

                else if (opt3 == "2")
                    handle_update_message();

                else if (opt3 == "3")
                    handle_delete_message();

                else if (opt3 == "a")
                    handle_show_messages();

                else if (opt3 == "x")
                    break;

                else
                    cout << "Optiune invalida!" << endl;
            }
        }

        else if (opt == "3"){
            while (true){
                show_friendship_crud_menu();
                cout << "Alege o optiune: ";
                string opt4;
                cin >> opt4;
                if (opt4 == "1")
                    handle_add_friendship();

                else if (opt4 == "2")
                    handle_delete_friendship();

                else if (opt4 == "a")
                    handle_show_friendships();

                else if (opt4 == "x")
                    break;

                else
                    cout << "Optiune invalida!" << endl;
            }
        }

        else if (opt == "4"){
            while (true){
                show_event_crud_menu();
                cout << "Alege o optiune: ";
                string opt5;
                cin >> opt5;
                if (opt5 == "1")
                    handle_add_event();

                else if (opt5 == "2")
                    handle_update_event();

                else if (opt5 == "3")
                    handle_delete_event();

                else if (opt5 == "a")
                    handle_show_events();

                else if (opt5 == "x")
                    break;

                else
                    cout << "Optiune invalida!" << endl;
            }
        }

        else if (opt == "addpart")
            handle_add_participant_to_event();

        else if (opt == "delpart")
            handle_delete_participant_to_event();

        else if (opt == "conv")
            handle_show_conversation();

        else if (opt == "showf")
            handle_show_friends_of_user();

        else if (opt == "au")
            handle_show_users();

        else if (opt == "am")
            handle_show_messages();

        else if (opt == "ae")
            handle_show_events();

        else if (opt == "ap")
            handle_show_friendships();

        else if (opt == "x")
            break;

        else
            cout << "Optiunea aleasa este invalida!" << endl;
    }
}

// shows the CRUD operations for users
void UI::show_user_crud_menu() {
    cout << endl;
    cout << "1. Adauga utilizator" << endl;
    cout << "2. Modifica utilizator" << endl;
    cout << "3. Sterge utilizator" << endl;
    cout << "a. Afiseaza utilizatori" << endl;
    cout << "x. Iesire CRUD" << endl;
}

// shows the CRUD operations for friendships
void UI::show_friendship_crud_menu() {
    cout << endl;
    cout << "1. Adauga prietenie" << endl;
    cout << "2. Sterge prietenie" << endl;
    cout << "a. Afiseaza prietenii" << endl;
    cout << "x. Iesire CRUD" << endl;
}

// shows the CRUD operations for messages
void UI::show_message_crud_menu() {
    cout << endl;
    cout << "1. Adauga mesaj" << endl;
    cout << "2. Modifica mesaj" << endl;
    cout << "3. Sterge mesaj" << endl;
    cout << "a. Afiseaza mesaje" << endl;
    cout << "x. Iesire CRUD" << endl;
}

// shows the CRUD operations for events
void UI::show_event_crud_menu() {
    cout << endl;
    cout << "1. Adauga eveniment" << endl;
    cout << "2. Modifica eveniment" << endl;
    cout << "3. Sterge eveniment" << endl;
    cout << "a. Afiseaza evenimente" << endl;
    cout << "x. Iesire CRUD" << endl;
}

// shows the full menu
void UI::show_menu() {
    cout << endl;
    cout << "1. CRUD utilizatori" << endl;
    cout << "2. CRUD mesaje" << endl;
    cout << "3. CRUD prietenii" << endl;
    cout << "4. CRUD evenimente" << endl;
    cout << "addpart. Adauga un participant la un eveniment" << endl;
    cout << "delpart. Sterge un participant la un eveniment" << endl;
    cout << "conv. Afiseaza conversatia dintre 2 useri" << endl;
    cout << "showf. Afiseaza prietenii unui user" << endl;
    cout << "au. Afiseaza utilizatori" << endl;
    cout << "am. Afiseaza mesaje" << endl;
    cout << "ap. Afiseaza prietenii" << endl;
    cout << "ae. Afiseaza evenimente" << endl;
    cout << "x. Iesire" << endl;
}

void UI::handle_add_user() {
    cout << endl;
    cout << "Introduceti id-ul utilizatorului: ";
    int id;
    cin >> id;

    cout << "Introduceti username-ul utilizatorului: ";
    string username;
    cin >> username;

    this->user_service.add_user(id, username);
}

void UI::handle_update_user() {
    cout << endl;
    cout << "Introduceti id-ul utilizatorului pe care vreti sa il modificati: ";
    int id;
    cin >> id;

    cout << "Introduceti noul id al utilizatorului: ";
    int new_id;
    cin >> new_id;

    cout << "Introduceti noul username al utilizatorului: ";
    string new_username;
    cin >> new_username;

    this->user_service.update_user(id, new_id, new_username);
}

void UI::handle_delete_user() {
    cout << endl;
    cout << "Introduceti id-ul utilizatorului pe care vreti sa il stergeti: ";
    int id;
    cin >> id;

    this->user_service.delete_user(id);
}

void UI::handle_show_users() {
    cout << endl;
    List<User> list = this->user_service.get_all();
    for (int i = 0; i < list.size(); i++) {
        User user;
        user = list[i];
        cout << user <<endl;
    }
}

void UI::handle_add_message() {
    cout << endl;
    cout << "Introduceti id-ul mesajului: ";
    int id_msg;
    cin >> id_msg;

    cout << "Introduceti id-ul expeditorului: ";
    int sender;
    cin >> sender;

    string msg;
    cin.ignore();
    cout << "Introduceti mesajul: ";
    getline(cin, msg);

    cout << "Introduceti id-ul destinatarului: ";
    int receiver;
    cin >> receiver;

    this->message_service.add_message(id_msg, sender, msg, receiver);
}

void UI::handle_delete_message() {
    cout << endl;
    cout << "Introduceti id-ul mesajului pe care vreti sa il stergeti: ";
    int id_msg;
    cin >> id_msg;

    this->message_service.delete_message(id_msg);
}

void UI::handle_show_messages() {
    cout << endl;
    List<Message> list = this->message_service.get_all();
    for (int i = 0; i < list.size(); i++) {
        Message msg;
        msg = list[i];
        cout << msg << endl;
    }
}

void UI::handle_update_message() {
    cout << endl;
    cout << "Introduceti id-ul mesajului pe care vreti sa il modificati: ";
    int id_msg;
    cin >> id_msg;

    cout << endl;
    cout << "Introduceti id-ul noului mesaj: ";
    int id_msg_new;
    cin >> id_msg_new;

    cout << "Introduceti id-ul noului expeditor: ";
    int sender_new;
    cin >> sender_new;

    string msg_new;
    cin.ignore();
    cout << "Introduceti noul mesaj: ";
    getline(cin, msg_new);

    cout << "Introduceti id-ul noului destinatar: ";
    int receiver_new;
    cin >> receiver_new;

    this->message_service.update_message(id_msg, id_msg_new,
                                         sender_new, msg_new, receiver_new);
}

void UI::handle_add_event() {
    cout << endl;
    cout << "Introduceti id-ul evenimentului: ";
    int id_event;
    cin >> id_event;

    string name;
    cin.ignore();
    cout << "Introduceti numele evenimentului: ";
    getline(cin, name);

    string loc;
    cin.ignore();
    cout << "Introduceti locatia evenimentului: ";
    getline(cin, loc);

    vector<User> part;
    this->event_service.add_event(id_event, name, loc, part);
}

void UI::handle_update_event() {
    cout << endl;
    cout << "Introduceti id-ul evenimentului pe care vreti sa il modificati: ";
    int id_event;
    cin >> id_event;

    cout << "Introduceti noul id: ";
    int id_event_new;
    cin >> id_event_new;

    string name;
    cin.ignore();
    cout << "Introduceti noul nume: ";
    getline(cin,name);

    string loc;
    cin.ignore();
    cout << "Introduceti noua locatie: ";
    getline(cin,loc);

    vector<User> part;
    this->event_service.update_event(id_event,id_event_new,name,loc,part);
}

void UI::handle_delete_event() {
    cout << endl;
    cout << "Introduceti id-ul evenimentului pe care vreti sa il stergeti: ";
    int id_event;
    cin >> id_event;

    this->event_service.delete_event(id_event);
}

void UI::handle_show_events() {
    cout << endl;
    List<Event> event_list = this->event_service.get_all();
    for (int i = 0; i < event_list.size(); i++) {
        Event ev;
        ev = event_list[i];
        cout << ev << endl;
        cout << "Participanti: ";
        vector<User> participants = ev.get_participants();
        if (participants.empty())
            cout << "Nu sunt inca participanti la acest eveniment." << endl;
        else {
            for (int j = 0; j < participants.size(); j++) {
                cout << participants[j] << " ; ";
            }
            cout << endl;
        }
    }
}

void UI::handle_add_participant_to_event() {
    cout << endl;

    cout << "Introduceti id-ul evenimentului la care doriti sa adaugati un participant: ";
    int id_event;
    cin >> id_event;

    cout << "Introduceti id-ul user-ului care va participa la eveniment: ";
    int id_participant;
    cin >> id_participant;

    List<User> users = this->user_service.get_all();
    for (int i = 0; i < users.size(); i++)
        if (users[i].get_id() == id_participant) {
            User participant_to_add = users[i];
            this->event_service.add_participant_to_event(id_event, participant_to_add);
        }
}

void UI::handle_delete_participant_to_event() {
    cout << endl;

    cout << "Introduceti id-ul evenimentului caruia doriti sa ii stergeti un participant: ";
    int id_event;
    cin >> id_event;

    cout << "Introduceti id-ul user-ului care nu va mai participa la eveniment: ";
    int id_participant;
    cin >> id_participant;

    List<User> users = this->user_service.get_all();
    for (int i = 0; i < users.size(); i++)
        if (users[i].get_id() == id_participant) {
            User participant_to_delete = users[i];
            this->event_service.delete_participant_to_event(id_event, participant_to_delete);
        }

}

void UI::handle_add_friendship() {
    cout << endl;
    cout << "Introduceti id-ul prieteniei: ";
    int id;
    cin >> id;

    cout << "Introduceti id-ul primului user: ";
    int id_user1;
    cin >> id_user1;

    cout << "Introduceti id-ul celui de-al doilea user: ";
    int id_user2;
    cin >> id_user2;

    this->friend_service.add_friendship(id, id_user1, id_user2);
    //this->friend_service.add_friendship(id,user2,user1);
}

void UI::handle_delete_friendship() {
    cout << endl;
    cout << "Introduceti id-ul prieteniei pe care vreti sa o stergeti: ";
    int id;
    cin >> id;
    this->friend_service.delete_friendship(id);
}

void UI::handle_show_friendships() {
    cout << endl;
    cout << "Prieteniile retelei sunt: " << endl;
    vector<vector<Friendship>> friendships = this->friend_service.get_all();
    for (auto &t: friendships)
        for (auto &elem: t)
            cout << elem << endl;
}

void UI::handle_show_conversation() {
    cout << endl;
    cout << "Introduceti id-ul primului user: ";
    int id_user1;
    cin >> id_user1;

    cout << "Introduceti id-ul celui de-al doilea user: ";
    int id_user2;
    cin >> id_user2;

    vector<Message> result = this->message_service.get_conversation(id_user1,id_user2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].get_id_sender() << ": " << result[i].get_content() << endl;
    }
}

void UI::handle_show_friends_of_user() {
    cout << endl;
    cout << "Introduceti id-ul userului caruia vreti sa ii vedeti prietenii: ";
    int id_user;
    cin >> id_user;

    User user = this->user_service.get_user_by_id(id_user);
    vector<string> result;
    vector<vector<Friendship>> friends = this->friend_service.get_all();
    for (auto &t: friends)
        for (auto &elem: t)
            if (elem.get_id_user1() == user.get_id()){
                User friend_to_add = this->user_service.get_user_by_id(elem.get_id_user2());
                result.push_back(friend_to_add.get_username());
            }

    cout << endl;
    cout << "Prietenii userului " << user.get_username() << " sunt:" << endl;
    if (result.empty())
        cout << "Userul ales nu are prieteni inca" << endl;
    else {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}

// destructor
UI::~UI() = default;
