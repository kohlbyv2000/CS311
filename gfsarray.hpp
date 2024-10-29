// gfsarray.hpp
// Adam Bishop and Kohlby Vierthaler
// 2024/10/27
// Header file for frightfully smart array


#ifndef FILE_GFSARRAY_HPP_INCLUDED
#define FILE_GFSARRAY_HPP_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max


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
    GFSArray(const GFSArray &other) {
        :_data(new value_type[other._size]), _size(other._size) {

            try {
                std::copy(other._data, 
                other._data + other._size, 
                _data);
            } catch (...) {
                // Cleanup
            }
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
    // Strong Guarantee
    GFSArray & operator=(const GFSArray & other) {
        //TODO
    }

    // Move assignment operator
    // No-Throw Guarantee
    GFSArray & operator=(GFSArray && other) noexcept {
        //TODO
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
    //     ???
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
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
    //     ???
    // Strong Guarantee
    iterator insert(iterator pos, const value_type &item) {
        //TODO
    }
        // Above, passing by value is appropriate, since our value type
        // is int. However, if the value type is changed, then a
        // different parameter-passing method may need to be used.

    // erase
    // Pre:
    //     ???
    // Strong Guarantee
    iterator erase(iterator pos) {
        //TODO
    }

    // push_back
    // Strong Guarantee
    void push_back(const value_type &item)
        // Above, passing by value is appropriate, since our value type
        // is int. However, if the value type is changed, then a
        // different parameter-passing method may need to be used.
    {
        insert(end(), item);
    }

    // pop_back
    // Pre:
    //     ???
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(GFSArray & other) noexcept {
        //TODO
    }

// ***** GFSArray: data members *****
private:

    // Below, _capacity must be declared before _data
    size_type    _capacity;  // Size of our allocated array
    size_type    _size;      // Size of client's data
    value_type * _data;      // Pointer to our array

};  // End class GFSArray


#endif  //#ifndef FILE_GFSARRAY_HPP_INCLUDED
