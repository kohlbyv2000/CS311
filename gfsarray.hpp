// gfsarray.hpp
// Kohlby Vierthaler
// 2024/1q/31
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
        :_data(new value_type[other._size]), _size(other._size) {

            try {
                GFSArray temp(other);
                temp = std::copy(other._data, 
                other._data + other._size, 
                _data);
            } catch (...) {
                //delete GFSArray temp;
                throw;
            }
        }

    // Move ctor
    // No-Throw Guarantee
    GFSArray(GFSArray && other) noexcept
        :_data(std::move(other._data)), _size(other._size) {
            other._size = 0;
            other._data = nullptr;
    }

    // Copy assignment operator
    // No-Throw Guarantee
    GFSArray &operator=(const GFSArray &other) noexcept {
        auto other_copy = other;
        swap(other_copy);
        return *this;
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

    // resize
    // Strong Guarantee
    void resize(size_type newsize) {
        //TODO
    }

    // insert
    // Pre:
    //    0 <= pos < _size
    // Strong Guarantee
    iterator insert(iterator pos, const value_type &item) {

        if (pos < 0 || pos > _size - 1) {
            throw std::out_of_range();
        }

        try {

            // Shift elements beyond insertion up by one position
            for (size_type i = pos; i < _size; ++i) {
                _data[i] = _data[i + 1];
            }

            _data[pos] = item;
            ++_size;

        } catch (std::out_of_range) {

            std::cerr << "Index out of range";

        } catch (...) {

            // If insert fails, cleanup
            delete _data[pos];
            for (size_type i = pos; i < _size; ++i) {
                _data[i] = _data[i - 1];
            }
        }

        
    }
    

    // erase
    // Pre:
    //    0 <= pos < _size
    // Strong Guarantee
    iterator erase(iterator pos) {
        
        if (pos < 0 || pos > _size - 1) {
            throw std::out_of_range();
        }

        try {

            for (size_type i = _size - 1; i > pos; --i) {
                _data[i] = _data[i - 1];
            }

            --_size;

        } catch (...) {

            
        }
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
        if (end() > 0) {
            erase(end()-1);
        }
    }

    // swap
    // No-Throw Guarantee
    void swap(GFSArray &other) noexcept {
        
        std::swap(_data, other._data);
        std::swap(_size, other._size);
    }

// ***** GFSArray: data members *****
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class GFSArray


#endif  //#ifndef FILE_GFSARRAY_HPP_INCLUDED
