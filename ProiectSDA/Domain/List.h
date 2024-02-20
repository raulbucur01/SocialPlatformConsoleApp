//
// Created by raulb on 5/16/2022.
//

#ifndef PROIECTSDA_LIST_H
#define PROIECTSDA_LIST_H
#include "Node.h"

template <class T>
class List {
private:
    Node<T>* first;
public:
    // default constructor
    List(){
        first = nullptr;
    }

    // checks if list is empty
    bool empty(){
        return (this->first == nullptr);
    }

    // adds an element to the list
    void add(T elem){
        if (first == nullptr)
        {
            first = new Node<T>(elem);
        }
        else
        {
            Node<T>* p = first;
            while (p->next != nullptr)
                p = p->next;
            p->next = new Node<T>(elem);
        }
    }

    // replaces element old_e with new element new_e
    void update(T& old_e, T& new_e){
        auto* oldE = new Node<T>(old_e);
        auto* newE = new Node<T>(new_e);
        Node<T>* crt = first;
        while (crt != nullptr){
            if (crt->info == oldE->info)
                crt->info = newE->info;
            crt = crt->next;
        }
    }

    // removes an element from the list
    void remove(T elem){
        Node<T> *nodeToDelete = nullptr;

        if (first != nullptr) {
            if (first->info == elem) {
                nodeToDelete = first;
                first = first->next;
            }
            else {
                Node<T> *p = first->next;
                Node<T> *q = first;
                while (p != nullptr)
                    if (p->info == elem) {
                        nodeToDelete = p;
                        p = nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next = nodeToDelete->next;
            }
        }
        delete nodeToDelete;

    }

    // searches an element in the list and returns true if it exists and false otherwise
    bool search(T elem){
        auto* e = new Node<T>(elem);
        Node<T>* crt = first;
        while (crt != nullptr) {
            if (crt->info == e->get_info())
                return true;
            crt = crt->next;
        }
        return false;
    }

    // returns the size of the list
    int size(){
        int nr = 0;
        Node<T>* crt = first;
        while (crt != nullptr) {
            crt = crt->next;
            nr++;
        }
        return nr;
    }

    // returns the element located on the specified index position
    T get_from_pos(int index){
        //if (no_elements() == 0)
            //throw
        int i = 0;
        Node<T>* crt = first;
        while (i < index && crt != nullptr){
            i++;
            crt = crt->next;
        }
        return crt->info;
    }

    // returns the element on the specified index position like in a vector
    T operator[](int index){
        return get_from_pos(index);
    }
};

#endif //PROIECTSDA_LIST_H
