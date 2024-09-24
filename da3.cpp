// da3.cpp
// Kohlby Vierthaler
// 2024/09/24
// Source file for Potpourri

#include "da3.hpp"     // For Assignment 3 prototypes & templates
#include <functional>
using std::function;


// Exception throwing function
void didItThrow(const function<void()> &ff, bool &threw) {
    
    try {
        ff();
        threw = false;
        return;
    }

    catch (...) {
        threw = true;
        throw;
    }
}

// Recursive function
int gcd(int a, int b) {

    // base case
    if (a == 0) {
        return b;
    }

    // recursive case
    if (a > b) {
        return gcd(b, a);
    }

    return gcd(b % a, a);
}