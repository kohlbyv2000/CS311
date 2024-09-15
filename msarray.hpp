// msarray.hpp
// Kohlby Vierthaler
// 2024/09/15
// Header file for moderately smart array

#ifndef FILE_MSARRAY_HPP_INCLUDED
#define FILE_MSARRAY_HPP_INCLUDED

#include <cstddef>
#include <iterator>


////**** MSARRAY CLASS TEMPLATE ****////


template <typename ValType>

class MSArray {

    public:

    using size_type = std::size_t;
    using value_type = ValType;

    //** Ctor Functions and Big Five **//

    // Default ctor
    explicit MSArray(size_type size) {
        :_arrayptr(new value_type 8);
    }

    // Dctor
    ~MSArray() {
        delete [] _arrayptr;
    }

    // Copy ctor
    MSArray(const MSArray &other) {
        
    }

    // Copy assignment operator
    MSArray &operator=(const MSArray &rhs) {
        
    }

    // Move ctor
    MSArray(MSArray && other) {
        
    }

    // Move assignment operator
    MSArray &operator=(MSArray &rhs) {

    }
    
}; // End of MSArray class template

#endif