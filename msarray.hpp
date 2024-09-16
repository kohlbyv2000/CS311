// msarray.hpp
// Kohlby Vierthaler
// 2024/09/15
// Header file for moderately smart array

#ifndef FILE_MSARRAY_HPP_INCLUDED
#define FILE_MSARRAY_HPP_INCLUDED

#include <cstddef>
#include <iterator>
#include <algorithm>


////**** MSARRAY CLASS TEMPLATE ****////


template <typename ValType>

class MSArray {

    public:

    // 
    using size_type = std::size_t;
    using value_type = ValType;


    //** Ctor Functions and Big Five **//

    // Default ctor
    explicit MSArray(size_type size)
        :_arrayptr(new value_type[8]) {}

    // Dctor
    ~MSArray() {
        delete [] _arrayptr;
    }

    // Copy ctor
    MSArray(const MSArray &other)
        :_arrayptr(new value_type[8]) {
            std::copy(other._arrayptr.begin(), 
            other._arrayptr.end(), 
            other._arrayptr.begin());
        }

    // Copy assignment operator
    MSArray &operator=(const MSArray &rhs) {
        auto rhs_copy = rhs;
        arrayswap(rhs_copy);
        return *this;
    }

    // Move ctor
    MSArray(MSArray && other) noexcept 
        :_arrayptr(std::move(other._arrayptr)) {
            delete [] other._arrayptr;
        }

    // Move assignment operator
    MSArray &operator=(MSArray &rhs) noexcept {
        arrayswap(rhs);
        return *this;
    }


    //** Operators **/
    

    //** Private data members/functions **/
    private:

    void arrayswap(MSArray &other) noexcept {
        std::swap(_arrayptr, other._arrayptr);
    }

    value_type *_arrayptr;
    
}; // End of MSArray class template

#endif