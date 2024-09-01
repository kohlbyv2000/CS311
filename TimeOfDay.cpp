// TimeOfDay.cpp
// Kohlby Vierthaler
// 2024/08/30
// Code for TimeOfDay package

#include <ostream>
#include "TimeOfDay.hpp"

std::ostream &operator<<(std::ostream &out, const TimeOfDay &t) {
    int h, m, s;
    t.getTime(h, m, s);
    out << h << ":" << m << ":" << s;
    return out;
}