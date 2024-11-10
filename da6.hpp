// da6.hpp
// Kohlby V. & Adam B.
// 2024/11/10
// Header file for linked lists

#ifndef FILE_DA6_HPP_INCLUDED
#define FILE_DA6_HPP_INCLUDED

#include "llnode2.hpp" // For linked lists
#include <memory> // For std::unique_ptr
#include <utility> // For std::pair

// Function to reverse a linked list
template <typename ValType>
void reverseList(unique_ptr<LLNode2<ValType>> & head) {
    std::unique_ptr<LLNode2<ValType>> prev = nullptr;
    std::unique_ptr<LLNode2<ValType>> node = head;
    std::unique_ptr<LLNode2<ValType>> next = nullptr;

    while (node != nullptr) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

// Start of SLLMap class template
template <string, int>
class SLLMap {

public:

// Default ctor
SLLMap() {

}

// Dctor
~SLLMap() {
    delete *this;
}

// Delete copy and move ctors and assignment operators
SLLMap(const SLLMap&) = delete;
SLLMap(SLLMap&&) = delete;
SLLMap &operator=(const SLLMap&) = delete;
SLLMap &operator=(SLLMap&&) = delete;

// Returns linked list size
int size() {
    return;
}

bool empty() {
    return size() > 0;
}

bool present(std::pair key) {
    return key == ;
}

// get() {
    //return 
//}

void set(int key, ValType value) {
    return std::pair<key, value>;
}

void erase(int key) {
    if (key == ) {

    }
    return;
}

void traverse() {
    return;
}

private:

    std::unique_ptr<LLNode2<std::pair>>
};


#endif