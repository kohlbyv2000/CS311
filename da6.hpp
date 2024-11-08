// da6.hpp
// Kohlby V. & Adam B.
// 2024/11/07
// Header file for linked lists

#ifndef FILE_DA6_HPP_INCLUDED
#define FILE_DA6_HPP_INCLUDED

#include "llnode2.hpp" // For linked lists
#include <memory> // For std::unique_ptr

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

#endif