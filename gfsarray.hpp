// gfsarray.hpp
// Kohlby V. & Adam B.
// 2024/10/31
// Header file for frightfully smart array


#ifndef FILE_GFSARRAY_HPP_INCLUDED
#define FILE_GFSARRAY_HPP_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max, std::copy, std::move
#include <iostream>
// For std::cerr
#include <stdexcept>
// For std::out_of_range


// *********************************************************************
// class GFSArray - Class definition
// *********************************************************************


// class GFSArray
// Generic Frightfully Smart Array
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
template <typename ValType>
class GFSArray {

// ***** GFSArray: types *****
public:

    // value_type: type of data items
    using value_type = ValType;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** GFSArray: internal-use constants *****
private:

    // Capacity of default-constructed object
    enum { DEFAULT_CAP = 42 };

// ***** GFSArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit GFSArray(size_type thesize=0)
        :_capacity(std::max(thesize, size_type(DEFAULT_CAP))),
            // _capacity must be declared before _data
         _size(thesize),
         _data(_capacity == 0 ? nullptr
                              : new value_type[_capacity])
    {}

    // Copy ctor
    // Strong Guarantee
    GFSArray(const GFSArray &other)
        :_capacity(other._capacity),
        _size(0),  // Initialize size to 0 initially
        _data(nullptr)  // Initialize data to nullptr
    {
        if (_capacity > 0) {
            _data = new value_type[_capacity];  // Allocate new array
            try {
                std::copy(other._data, other._data + other._size, _data);  // Copy elements
                _size = other._size;  // Only set size after successful copy
            }
            catch (...) {
                delete[] _data;  // Clean up if copy throws
                throw;           // Re-throw the exception
            }
        }
    }

    // Move ctor
    // No-Throw Guarantee
    GFSArray(GFSArray && other) noexcept
        :_capacity(other._capacity),
        _size(other._size),
        _data(other._data) {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    // Copy assignment operator
    // Strong Guarantee (not noexcept)
    GFSArray &operator=(const GFSArray &other) {
        GFSArray temp(other);    // Copy construct a temporary
        swap(temp);              // Swap contents with temporary
        return *this;            // Return *this, temp gets destroyed
    }

    // Move assignment operator
    // No-Throw Guarantee
    GFSArray &operator=(GFSArray && other) noexcept {
        swap(other);
        return *this;
    }

    // Dctor
    // No-Throw Guarantee
    ~GFSArray()
    {
        delete [] _data;
    }

// ***** GFSArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //     index >= 0
    // No-Throw Guarantee
    value_type &operator[](size_type index)
    {
        return _data[index];
    }
    const value_type &operator[](size_type index) const
    {
        return _data[index];
    }

// ***** GFSArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    void resize(size_type newsize) {
        if (newsize > _capacity) {
            size_type new_capacity = std::max(newsize, 2 * _capacity);
            value_type *new_data = new value_type[new_capacity];
            try {
                std::copy(_data, _data + _size, new_data);
            } catch (...) {
                delete[] new_data;
                throw;
            }
            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }
        _size = newsize;
    }

    // insert
    // Pre:
    //    0 <= pos < _size
    // Strong Guarantee
    iterator insert(iterator pos, const value_type &item) {
        
        size_type offset = pos - begin();
        if (offset > _size) {
            throw std::out_of_range("Insert position out of range");
        }

        if (_size == _capacity) {
            size_type newcap = (_capacity == 0) ? 1 : 2 * _capacity;
            value_type* newdata = new value_type[newcap];
            
            // Copy elements before insertion point
            std::copy(begin(), pos, newdata);
            
            // Insert new element
            newdata[offset] = item;
            
            // Copy remaining elements
            std::copy(pos, end(), newdata + offset + 1);
            
            delete[] _data;
            _data = newdata;
            _capacity = newcap;
        } else {
            // Shift elements to make room
            for (iterator it = end(); it != pos; --it) {
                *it = *(it - 1);
            }
            *pos = item;
        }
        
        ++_size;
        return begin() + offset;
    }

    // erase
    // Pre:
    //    0 <= pos < _size
    // Strong Guarantee
    iterator erase(iterator pos) {

        size_type offset = pos - begin();
        if (offset >= _size) {
            throw std::out_of_range("Erase position out of range");
        }

        // Shift elements
        std::copy(pos + 1, end(), pos);
        --_size;
        
        return begin() + offset;
    }

    // push_back
    // Strong Guarantee
    void push_back(const value_type &item)
    {
        insert(end(), item);
    }

    // pop_back
    // Pre:
    //     end != 0
    // Strong Guarantee
    void pop_back()
    {
        if (!empty()) {
            erase(end()-1);
        }
    }

    // swap
    // No-Throw Guarantee
    void swap(GFSArray &other) noexcept {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }

// ***** GFSArray: data members *****
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class GFSArray


#endif  //#ifndef FILE_GFSARRAY_HPP_INCLUDED