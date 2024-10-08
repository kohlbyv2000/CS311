// msarray.hpp
// Kohlby Vierthaler
// 2024/09/18
// Header file for moderately smart array

#ifndef FILE_MSARRAY_HPP_INCLUDED
#define FILE_MSARRAY_HPP_INCLUDED

#include <cstddef>
#include <algorithm>


////**** MSARRAY CLASS TEMPLATE ****////


// MSArray class invariants: _arrayptr and _size
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
        for (size_type i = 0; i < size; ++i) {
            _arrayptr[i] = item;
        }
    }

    // Dctor
    ~MSArray() {
        delete [] _arrayptr;
    }

    // Copy ctor
    MSArray(const MSArray &other)
        :_arrayptr(new value_type[other.size()]), _size(other.size()) {
            std::copy(other._arrayptr, 
            other._arrayptr + other._size, 
            _arrayptr);
        }

    // Copy assignment operator
    MSArray &operator=(const MSArray &rhs) {
        auto rhs_copy = rhs;
        arrayswap(rhs_copy);
        return *this;
    }

    // Move ctor
    MSArray(MSArray&& other) noexcept 
        :_arrayptr(std::move(other._arrayptr)), _size(other.size()) {
            other._size = 0;
            other._arrayptr = nullptr;
        }

    // Move assignment operator
    MSArray &operator=(MSArray &&rhs) noexcept {
        arrayswap(rhs);
        return *this;
    }


    //** General member functions **//

    size_type size() const {
        return _size;
    }

    value_type* begin() {
        return _arrayptr;
    }

    const value_type* begin() const {
        return _arrayptr;
    }

    value_type* end() {
        return begin() + size();
    }

    const value_type* end() const {
        return begin() + size();
    }


    //** Member operators **//
    
    
    // operator[] precondition: index must be non-negative
    // Non-const array index
    value_type &operator[](size_type index) {
            return _arrayptr[index];
    }
    
    // Const array index
    const value_type &operator[](size_type index) const {
            return _arrayptr[index];
    }


    //** Private data members/functions **/
    private:

    void arrayswap(MSArray &other) noexcept {
        std::swap(_arrayptr, other._arrayptr);
        std::swap(_size, other._size);
    }

    value_type *_arrayptr;
    size_type _size;
    
}; // End of MSArray class template


//** Definitions of associated global operators **//


// Less than
template <typename ValType>
bool operator<(const MSArray<ValType> &first, const MSArray<ValType> &other) {
    for (std::size_t i = 0; i < first.size() && i < other.size(); ++i) {
        if (first[i] < other[i]) {
            return true;
        } else if (other[i] < first[i]) {
            return false;
        }
    }
    return first.size() < other.size();
}

// operator> precondition: first and other must be valid objects of the same type
// Greater than
template <typename ValType>
bool operator>(const MSArray<ValType> &first, const MSArray<ValType> &other) {
        return other < first;
}

// Less than or equal to
template <typename ValType>
bool operator<=(const MSArray<ValType> &first, const MSArray<ValType> &other) {
    return !(first > other);
}

// Greater than or equal to
template <typename ValType>
bool operator>=(const MSArray<ValType> &first, const MSArray<ValType> &other) {
    return !(first < other);
}

// Equal
template <typename ValType>
bool operator==(const MSArray<ValType> &first, const MSArray<ValType> &other) {
    return first.size() == other.size() &&
    std::equal(first.begin(), first.end(), other.begin());
}

// Not-equal
template <typename ValType>
bool operator!=(const MSArray<ValType> &first, const MSArray<ValType> &other) {
    return !(first == other);
}

#endif