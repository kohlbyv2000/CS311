// treesort.hpp
// Kohlby V. & Adam B.
// 2024/11/11
// Header file for trees

#ifndef FILE_TREESORT_HPP_INCLUDED
#define FILE_TREESORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits;

#include <memory>
// For std::unique_ptr
using std::unique_ptr;


// BSTreeNode struct template
template<typename Value>
struct BSTreeNode {

    Value _data;
    unique_ptr _left = nullptr;
    unique_ptr _right = nullptr;
    
    BSTreeNode(Value &item, unique_ptr left, unique_ptr right) {
        _data = item;
        _left = left;
        _right = right;
    }
};

// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template <typename FDIter>
void treesort(FDIter first, FDIter last) {

    using Value = typename std::iterator_traits<FDIter>::value_type;

    // check if range is empty
    if (first == last) {
        return first;
    }
    
    for (int i = first; i <= last; i++) {
       // insert(i, );
       // traverse();
    }
}

// insert
// Inserts a given item into the BSTree.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template<typename Value>
void insert(unique_ptr<BSTreeNode<Value>> &head, 
const Value &item) {

    // Create new node if range is empty
    if (head == nullptr) {
        head = std::make_unique<BSTreeNode<Value>>(item, nullptr, nullptr);
        //auto p = std::make_unique<BSTreeNode<Value>>(item, nullptr, nullptr);

    // Recurse to find the correct insertion position
    } else {

        if (head->_data < item) {

            insert(head->_left, item);
            
        } else {

            insert(head->_right, item);
        }
    }
}

// traversal
// Traverses the BSTree using inorder.
// Pre:
//     ???
// Exception safety guarantee:
//     ???
template<typename Value>
void traversal(const unique_ptr<BSTreeNode<Value>> &node, 
Value &iter) {

}

#endif