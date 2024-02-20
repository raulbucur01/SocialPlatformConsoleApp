#include "Tests/Tests.h"
#include "Repository/UserRepository.h"
#include "Service/UserService.h"
#include "Repository/FriendshipRepository.h"
#include "Service/FriendshipService.h"
#include "UserInterface/UI.h"


int main() {
    tests();
    UserRepository ur;
    UserService us(ur);
    us.add_user(1,"raul807");
    us.add_user(2,"coco20");
    us.add_user(3,"alina79");
    us.add_user(4,"george");
    us.add_user(5,"cosmin2");
    us.add_user(6,"notorious_big");
    us.add_user(7,"ShabbaRico");
    us.add_user(8,"FotoMoroton");
    us.add_user(9,"Escanorr");
    us.add_user(10,"Cocoracio");
    us.add_user(11,"Sergiu21");
    us.add_user(12,"Darsius.own");
    us.add_user(13,"cristiano");
    us.add_user(14,"caPs");
    us.add_user(15,"Bwipo");

    MessageRepository mr;
    MessageService ms(mr);
    ms.add_message(1,1,"Salut! Cf?",2);
    ms.add_message(2,1,"Salut! Cf?",3);
    ms.add_message(3,1,"Salut! Cf?",4);
    ms.add_message(4,1,"Salut! Cf?",5);
    ms.add_message(5,1,"Salut! Cf?",6);
    ms.add_message(6,1,"Salut! Cf?",7);
    ms.add_message(7,1,"Salut! Cf?",8);
    ms.add_message(8,1,"Salut! Cf?",9);
    ms.add_message(9,1,"Salut! Cf?",10);
    ms.add_message(10,1,"Salut! Cf?",11);
    ms.add_message(11,1,"Salut! Cf?",12);
    ms.add_message(12,1,"Salut! Cf?",13);
    ms.add_message(13,1,"Salut! Cf?",14);
    ms.add_message(14,1,"Salut! Cf?",15);
    ms.add_message(15,2,"Bine tu?",1);
    ms.add_message(16,3,"Bine tu?",1);
    ms.add_message(17,4,"Bine tu?",1);
    ms.add_message(18,5,"Bine tu?",1);
    ms.add_message(19,6,"Bine tu?",1);
    ms.add_message(20,7,"Bine tu?",1);
    ms.add_message(21,8,"Bine tu?",1);
    ms.add_message(22,9,"Bine tu?",1);
    ms.add_message(23,10,"Bine tu?",1);
    ms.add_message(24,11,"Bine tu?",1);
    ms.add_message(25,12,"Bine tu?",1);
    ms.add_message(26,13,"Bine tu?",1);
    ms.add_message(27,14,"Bine tu?",1);
    ms.add_message(28,15,"Bine tu?",1);

    ms.add_message(29,3,"Salut! Cf?",1);
    ms.add_message(30,3,"Salut! Cf?",2);
    ms.add_message(31,3,"Salut! Cf?",4);
    ms.add_message(32,3,"Salut! Cf?",5);
    ms.add_message(33,3,"Salut! Cf?",6);
    ms.add_message(34,3,"Salut! Cf?",7);
    ms.add_message(35,3,"Salut! Cf?",8);
    ms.add_message(36,3,"Salut! Cf?",9);
    ms.add_message(37,3,"Salut! Cf?",10);
    ms.add_message(38,3,"Salut! Cf?",11);
    ms.add_message(39,3,"Salut! Cf?",12);
    ms.add_message(40,3,"Salut! Cf?",13);
    ms.add_message(41,3,"Salut! Cf?",14);
    ms.add_message(42,3,"Salut! Cf?",15);
    ms.add_message(43,1,"Bine tu?",3);
    ms.add_message(44,2,"Bine tu?",3);
    ms.add_message(45,4,"Bine tu?",3);
    ms.add_message(46,5,"Bine tu?",3);
    ms.add_message(47,6,"Bine tu?",3);
    ms.add_message(48,7,"Bine tu?",3);
    ms.add_message(49,8,"Bine tu?",3);
    ms.add_message(50,9,"Bine tu?",3);
    ms.add_message(51,10,"Bine tu?",3);
    ms.add_message(52,11,"Bine tu?",3);
    ms.add_message(53,12,"Bine tu?",3);
    ms.add_message(54,13,"Bine tu?",3);
    ms.add_message(56,14,"Bine tu?",3);
    ms.add_message(57,15,"Bine tu?",3);

    EventRepository er;
    EventService es(er,ur);
    vector<User> part;
    es.add_event(1,"Joris Voorn","Form Space",part);
    es.add_event(2,"Untold","Cluj Arena",part);

    FriendshipRepository fr;
    FriendshipService fs(fr);
    fs.add_friendship(1,1,2);
    fs.add_friendship(2,1,3);
    fs.add_friendship(3,1,4);
    fs.add_friendship(4,1,5);
    fs.add_friendship(5,1,6);
    fs.add_friendship(6,1,7);
    fs.add_friendship(7,1,8);
    fs.add_friendship(8,1,9);
    fs.add_friendship(9,1,10);
    fs.add_friendship(10,1,11);
    fs.add_friendship(11,1,12);
    fs.add_friendship(12,1,13);
    fs.add_friendship(13,1,14);
    fs.add_friendship(14,1,15);
    fs.add_friendship(16,3,2);
    fs.add_friendship(18,3,4);
    fs.add_friendship(19,3,5);
    fs.add_friendship(20,3,6);
    fs.add_friendship(21,3,7);
    fs.add_friendship(22,3,8);
    fs.add_friendship(23,3,9);
    fs.add_friendship(24,3,10);
    fs.add_friendship(25,3,11);
    fs.add_friendship(26,3,12);
    fs.add_friendship(27,3,13);
    fs.add_friendship(28,3,14);
    fs.add_friendship(29,3,15);
    UI ui(us,ms,es,fs);
    ui.run_ui();
    return 0;
}
