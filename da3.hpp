// da3.hpp
// Kohlby Vierthaler
// 2024/09/24
// Header file for Potpourri

#ifndef FILE_DA3_HPP_INCLUDED
#define FILE_DA3_HPP_INCLUDED

#include "llnode.hpp"  // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range
#include <iostream>    // For std::cerr and std::endl


// Looks up a linked list
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> *head, std::size_t index) {
    
    // Find size of linked list
    auto h = head;
    std::size_t size = 0;
    while (h != nullptr) {
        h = h->_next;
        ++size;
    }

    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    // Find node to index
    const LLNode<ValueType> *node = head; 
    for (std::size_t i = 0; i < index; i++) {
        node = node->_next;
    }

    try {
        return node->_data;
    } catch (const std::out_of_range& e) {
        std::cerr << "Index is out of range " << e.what() << std::endl;
        throw;
    }
}


// Implementation in source file
void didItThrow(const std::function<void()> &ff, bool &threw);


// Check if elements are sorted
template <typename FDIter>
bool checkSorted(FDIter first, FDIter last) {
    
    // Empty range case
    if (first == last) {
        return true;
    }

    FDIter previous = first;
    ++first;

    // Check if elements are out of order
    while (first != last) {
        if (*first < *previous) {
            return false;
        }
        previous = first;
        ++first;
    }

    // If all elements are sorted correctly, return true
    return true;
}


// Implementation in source file
int gcd(int a, int b);


#endif  //#ifndef FILE_DA3_HPP_INCLUDED