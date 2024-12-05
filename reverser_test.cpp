// reverser_test.cpp
// Kohlby Vierthaler
// 2024/12/05
// Test program for reverser

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h" // Includes for the "doctest" unit-testing framework
#include "reverser.hpp" // Includes for code to be tested
#include <vector> // For std::vector
#include <deque> // For std::deque
#include <list> // For std::list
#include <array> // For std::array
#include <string> // For std::string
#include <numeric> // For std::iota


// Beginning of test cases
TEST_CASE("Reverser works with various containers and types") {
    Reverser reverser;

    // Test with std::vector
    {
        std::vector<int> vec {1, 2, 3, 4, 5};
        reverser(vec.begin(), vec.end());
        CHECK(vec == std::vector<int> {5, 4, 3, 2, 1});
    }

    // Test with std::deque
    {
        std::deque<double> dd {1.1, 2.2, 3.3};
        reverser(dd.begin(), dd.end());
        CHECK(dd == std::deque<double> {3.3, 2.2, 1.1});
    }

    // Test with a list of strings
    {
        std::list<std::string> lst {"a", "b", "c"};
        reverser(lst.begin(), lst.end());
        CHECK(lst == std::list<std::string> {"c", "b", "a"});
    }

    // Test with std::array
    {
        std::array<float, 4> arr {1.0f, 2.0f, 3.0f, 4.0f};
        reverser(arr.begin(), arr.end());
        CHECK(arr == std::array<float, 4> {4.0f, 3.0f, 2.0f, 1.0f});
    }

    // Test with std::string
    {
        std::string str = "abcd";
        reverser(str.begin(), str.end());
        CHECK(str == "dcba");
    }
}

TEST_CASE("Reverser handles edge cases") {
    Reverser reverser;

    // Test empty ranges
    {
        std::vector<int> emptyVec;
        reverser(emptyVec.begin(), emptyVec.end());
        CHECK(emptyVec.empty());
    }

    // Test ranges with only one element
    {
        std::vector<int> singleElementVec {42};
        reverser(singleElementVec.begin(), singleElementVec.end());
        CHECK(singleElementVec == std::vector<int> {42});
    }
}

// Test for modification of elements outside of range
TEST_CASE("Reverser does not modify items outside the range") {
    Reverser reverser;

    std::vector<int> vec {10, 20, 30, 40, 50};
    reverser(vec.begin() + 1, vec.end() - 1); // Reversing the middle part {20, 30, 40}

    CHECK(vec[0] == 10); // Must remain 10
    CHECK(vec[1] == 40); // 20 should become 40
    CHECK(vec[2] == 30); // 30 remains 30
    CHECK(vec[3] == 20); // 40 should become 20
    CHECK(vec[4] == 50); // Must remain 50
}

// This test checks large range
TEST_CASE("Reverser works with large ranges") {
    Reverser reverser;

    std::vector<int> largeVec(1000000);
    std::iota(largeVec.begin(), largeVec.end(), 1); // Fill with 1, 2, ..., 1000000
    reverser(largeVec.begin(), largeVec.end());

    // Check that the first element becomes 1000000 and the last becomes 1
    CHECK(largeVec[0] == 1000000);
    CHECK(largeVec[largeVec.size() - 1] == 1);
}