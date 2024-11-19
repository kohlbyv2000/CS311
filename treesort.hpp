// treesort.hpp
// Kohlby Vierthaler
// 2024/11/18
// Header file for trees

#ifndef FILE_TREESORT_HPP_INCLUDED
#define FILE_TREESORT_HPP_INCLUDED

#include <iterator>
// For std::iterator_traits;
#include <utility>
// For std::move
#include <memory>
// For std::unique_ptr
using std::unique_ptr;


// BSTreeNode struct template
template<typename Value>
struct BSTreeNode {

    Value _data;
    unique_ptr<BSTreeNode<Value>> _left;
    unique_ptr<BSTreeNode<Value>> _right;

    BSTreeNode(Value item, 
    unique_ptr<BSTreeNode<Value>> left, 
    unique_ptr<BSTreeNode<Value>> right) 
        : _data(item)
        , _left(std::move(left))
        , _right(std::move(right))
    {}
};

// insert
// Inserts a given item into the BSTree.
// Pre:
//     ???
// Exception safety guarantee:
//     Basic Guarantee
template<typename Value>
void insert(unique_ptr<BSTreeNode<Value>> &head, 
const Value &item) {

    // Create new node if range is empty
    if (head == nullptr) {
        head = std::make_unique<BSTreeNode<Value>>(item, nullptr, nullptr);

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
//     Basic Guarantee
template<typename FDIter, typename Value>
void traversal(const unique_ptr<BSTreeNode<Value>> &node, 
FDIter &iter) {

    //using Value = typename std::iterator_traits<FDIter>::value_type;

    if (node == nullptr) {
        return;
    }

    traversal(node->_left, iter);
    *iter++ = node->_data;
    traversal(node->_right, iter);
}

// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Exception safety guarantee:
//     Basic Guarantee
template <typename FDIter>
void treesort(FDIter first, FDIter last) {

    using Value = typename std::iterator_traits<FDIter>::value_type;

    // check if range is empty
    if (first == last) {
        return;
    }
    
    // create a root node
    unique_ptr<BSTreeNode<Value>> root = nullptr;

    for (FDIter i = first; i != last; i++) {
        
        insert(root, *i);
    }

    traversal(root, first);
}

#endif