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


    using size_type = std::size_t;
    using value_type = ValType;


    //** Ctor Functions and Big Five **//

    // Default ctor
    MSArray()
        : _arrayptr(new value_type[8]), _size(8) {}
    
    // 1-parameter ctor
    explicit MSArray(size_type size) : _arrayptr(new value_type[size]), _size(size) {}
    
    // 2-parameter ctor
    explicit MSArray(size_type size, const value_type &item) 
    : _arrayptr(new value_type[size]), _size(size)
    {
        //for (auto b : _arrayptr) {
        //    _arrayptr[b];
        //}
    }

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


    //** General member functions **//

    size_type size() {
        return _arrayptr.size();
    }

    size_type begin() {
        return *_arrayptr[0];
    }

    size_type begin() const {
        return *_arrayptr[0];
    }

    size_type end() {
        return *_arrayptr[8];
    }

    size_type end() const {
        return *_arrayptr[8];
    }


    //** Operators **//
    
    // Non-const array index
    value_type &operator[](size_type index) {
        if (index >= 0 && index < 8) {
            return _arrayptr[index];
        }
    }
    
    // Const array index
    const value_type &operator[](size_type index) const {
        if (index >= 0 && index < 8) {
            return _arrayptr[index];
        }
    }
    
    // Equal
    bool &operator==(const MSArray &other) {
        return _arrayptr.size() == other._arrayptr.size() &&
        std::equal(_arrayptr.begin(), _arrayptr.end(), other._arrayptr.begin());
    }

    // Not-equal
    bool &operator!=(const MSArray &other) {
        return !(*this == other);
    }

    // Less than
    bool operator<(const MSArray &other) const {
        return *this < other._arrayptr;
    }

    // Less than or equal to
    bool operator<=(const MSArray &other) const {
        return *this < other || *this == other;
    }

    // Greater than
    bool operator>(const MSArray &other) const {
        return other < *this;
    }

    // Greater than or equal to
    bool operator>=(const MSArray &other) const {
        return *this > other || *this == other;
    }


    //** Private data members/functions **/
    private:

    void arrayswap(MSArray &other) noexcept {
        std::swap(_arrayptr, other._arrayptr);
    }

    value_type *_arrayptr;
    size_type _size;
    
}; // End of MSArray class template

#endif