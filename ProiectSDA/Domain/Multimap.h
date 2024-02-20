//
// Created by raulb on 5/21/2022.
//

#ifndef PROIECTSDA_MULTIMAP_H
#define PROIECTSDA_MULTIMAP_H

#include <vector>

template<class T, class U>
class Multimap {
private:
    struct ListNode {
        U value;
        ListNode* next;
    };

    struct DictNode {
        T key;
        ListNode* value;
        DictNode* next;
    };

    DictNode* searchAddress(T key);
public:
    Multimap();
    ~Multimap();

    void put(T key, U value);
    std::vector<U> remove(T key);
    void remove(T key, U value);
    std::vector<U> get(T key);
    bool contains(T key);
    bool contains(T key, U value);

    std::vector<std::vector<U>> get_all();
    int get_size();

private:
    DictNode* head;
};

template<class T, class U>
inline typename Multimap<T, U>::DictNode* Multimap<T, U>::searchAddress(T key) {
    DictNode* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T, class U>
inline Multimap<T, U>::Multimap()
        : head(nullptr)
{}

template<class T, class U>
inline Multimap<T, U>::~Multimap()
{
    DictNode* curr = head;
    while (curr != nullptr) {
        DictNode* next = curr->next;
        delete curr->value;
        delete curr;
        curr = next;
    }
}

// adds a key-value combo
template<class T, class U>
inline void Multimap<T, U>::put(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        DictNode* newNode = new DictNode;
        newNode->key = key;
        newNode->value = new ListNode;
        newNode->value->value = value;
        newNode->value->next = nullptr;
        newNode->next = head;
        head = newNode;
    }
    else {
        ListNode* newNode = new ListNode;
        newNode->value = value;
        newNode->next = current->value;
        current->value = newNode;
    }
}

// removes a specified key from the multimap
template<class T, class U>
inline std::vector<U> Multimap<T, U>::remove(T key) {
    std::vector<U> values;
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return values;
    }
    else {
        ListNode* prev = nullptr;
        ListNode* curr = current->value;
        while (curr != nullptr) {
            values.push_back(curr->value);
            prev = curr;
            curr = curr->next;
            delete prev;
        }
    }

    if (current->next == nullptr) {
        delete current;
        head = nullptr;
    }

    return values;
}

// removes the specified key-value combo
template<class T, class U>
inline void Multimap<T, U>::remove(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return;
    }
    else {
        ListNode* curr = current->value;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            if (curr->value == value) {
                if (prev == nullptr) {
                    current->value = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

// gets the element at specified key
template<class T, class U>
inline std::vector<U> Multimap<T, U>::get(T key) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return std::vector<U>();
    }
    else {
        ListNode* curr = current->value;
        std::vector<U> result;
        while (curr != nullptr) {
            result.push_back(curr->value);
            curr = curr->next;
        }

        return result;
    }
}

// checks if the multimap contains a key
template<class T, class U>
inline bool Multimap<T, U>::contains(T key) {
    return searchAddress(key) != nullptr;
}

// checks if the multimap contains a key-value combo
template<class T, class U>
inline bool Multimap<T, U>::contains(T key, U value) {
    DictNode* current = searchAddress(key);
    if (current == nullptr) {
        return false;
    }
    else {
        ListNode* curr = current->value;
        while (curr != nullptr) {
            if (curr->value == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
}

// gets the values in the multimap
template<class T, class U>
inline std::vector<std::vector<U>> Multimap<T, U>::get_all() {
    std::vector<std::vector<U>> result;
    DictNode* current = head;
    while (current != nullptr) {
        result.push_back(get(current->key));
        current = current->next;
    }

    return result;
}

// returns the size of the multimap
template<class T, class U>
int Multimap<T,U>::get_size(){
    int nr = 0;
    for(auto& t: get_all())
        for(auto& elem: t)
            nr++;
    return nr;
}

#endif //PROIECTSDA_MULTIMAP_H
