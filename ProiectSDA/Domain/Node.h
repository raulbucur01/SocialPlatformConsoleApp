//
// Created by raulb on 5/16/2022.
//

#ifndef PROIECTSDA_NODE_H
#define PROIECTSDA_NODE_H

template <typename T>
class List;

template <class T>
class Node {
private:
    T info;
    Node<T>* next;
public:
    // parameter constructor
    explicit Node(T info){
        this->info = info;
        this->next = nullptr;
    }

    // returns the information in the node
    T get_info(){
        return this->info;
    }

    // returns a pointer to the next node
    Node<T>* get_next(){
        return next;
    }

    friend class List<T>;
};

#endif //PROIECTSDA_NODE_H
