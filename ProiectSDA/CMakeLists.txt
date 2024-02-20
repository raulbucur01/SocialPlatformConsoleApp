cmake_minimum_required(VERSION 3.21)
project(ProiectSDA)

set(CMAKE_CXX_STANDARD 23)

add_executable(ProiectSDA main.cpp Domain/User.cpp Domain/User.h Repository/UserRepository.cpp Repository/UserRepository.h Service/UserService.cpp Service/UserService.h Tests/Tests.cpp Tests/Tests.h UserInterface/UI.cpp UserInterface/UI.h Domain/Message.cpp Domain/Message.h Repository/MessageRepository.cpp Repository/MessageRepository.h Service/MessageService.cpp Service/MessageService.h Domain/Event.cpp Domain/Event.h Repository/EventRepository.cpp Repository/EventRepository.h Service/EventService.cpp Service/EventService.h Domain/Multimap.h Domain/Friendship.cpp Domain/Friendship.h Repository/FriendshipRepository.cpp Repository/FriendshipRepository.h Service/FriendshipService.cpp Service/FriendshipService.h)
