// da6.hpp
// Kohlby V. & Adam B.
// 2024/11/12
// Header file for linked lists

#ifndef FILE_DA6_HPP_INCLUDED
#define FILE_DA6_HPP_INCLUDED

#include "llnode2.hpp" // For linked lists
#include <memory> // For std::unique_ptr
#include <utility> // For std::pair and std::move
#include <stdexcept> // For std::out_of_range

// Function to reverse a linked list
template <typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>> & head) {
    std::unique_ptr<LLNode2<ValType>> prev = nullptr;
    std::unique_ptr<LLNode2<ValType>> node = std::move(head);
    std::unique_ptr<LLNode2<ValType>> next = nullptr;

    while (node != nullptr) {
        next = std::move(node->_next);
        node->_next = std::move(prev);
        prev = std::move(node);
        node = std::move(next);
    }
    
    head = std::move(prev);

    return;
}

// Forward declaration of the LLNode2 struct from llnode2.hpp
template <typename ValType>
struct LLNode2;

// Start of SLLMap class template
template <typename K, typename V>
class SLLMap {

public:

    // Key-value pair
    using KVType = std::pair<K, V>;

private:

    // Head pointer
    std::unique_ptr<LLNode2<KVType>> head;

    // Number of elements in the linked list
    size_t count;

public:

    // Strong Guarantee
    // Default ctor
    SLLMap() : head(nullptr), count(0) {}

    // Dctor
    ~SLLMap() = default;

    // Delete move ctor, move assignment operator
    // copy ctor, and copy assignment operator
    SLLMap(const SLLMap&) = delete;
    SLLMap &operator=(const SLLMap&) = delete;
    SLLMap(SLLMap&&) = delete;
    SLLMap &operator=(SLLMap&&) = delete;

    // Strong Guarantee
    // Return the size of the linked list
    size_t size() const noexcept {
        return count;
    }

    // Strong Guarantee
    // Check if the list is empty
    bool empty() const noexcept {
        return count == 0;
    }

    // Pre: key must be valid
    // Basic Guarantee
    // Check if a key is present in the list
    bool present(const K &key) const {
        auto *current = head.get();
        while (current) {
            if (current->_data.first == key) {
                return true;
            }
            current = current->_next.get();
        }
        return false;
    }

    // Pre: key must be valid,
    // must be present in list
    // Basic Guarantee (both versions)
    // Retrieves the value associated with the given key
    V &get(const K &key) {
        auto *current = head.get();
        while (current) {
            if (current->_data.first == key) {
                return current->_data.second;
            }
            current = current->_next.get();
        }
        throw std::out_of_range("Key not found");
    }

    const V &get(const K &key) const {
        auto *current = head.get();
        while (current) {
            if (current->_data.first == key) {
                return current->_data.second;
            }
            current = current->_next.get();
        }
        throw std::out_of_range("Key not found");
    }

    // Pre: key and value must be valid
    // Basic Guarantee
    // Inserts or updates the key-value pair in the dataset
    void set(const K &key, const V &value) {
        auto *current = head.get();
        while (current) {
            if (current->_data.first == key) {
                current->_data.second = value; // Update existing value
                return;
            }
            current = current->_next.get();
        }

        // Insert a new key-value pair if a key is not found
        push_front(head, std::make_pair(key, value));
        ++count;
    }

    // Pre: key must be valid
    // Basic Guarantee
    // Erases the key-value pair associated with the given key
    void erase(const K &key) {
        std::unique_ptr<LLNode2<KVType>> *current = &head;
        while (*current) {
            if ((*current)->_data.first == key) {
                pop_front(*current);
                --count;
                return;
            }
            current = &(*current)->_next;
        }
    }

    // Pre: function f must be a valid function
    // Basic Guarantee
    // Traverse the linked list with the provided function
    template<typename Func>
    void traverse(Func f) const {
        auto *current = head.get();
        while (current) {
            f(current->_data.first, current->_data.second);
            current = current->_next.get();
        }
    }
}; // End of SLLMap class template

#endif