// wordcount.cpp
// Kohlby Vierthaler
// 2024/12/05
// Source code for wordcount

#include <iostream> // For std::cout, std::cerr, and std::endl
#include <fstream> // For std::ifstream
#include <sstream> // For std::istringstream
#include <map> // For std::map
#include <string> // For std::string and std::getline
#include <set> // For std::set

// Main function
// Pre: File must be valid
// Basic Guarantee
int main() {

    std::string filename;
    std::cout << "Please enter a filename: ";
    
    std::getline(std::cin, filename);
    
    if (filename.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream infile(filename);
    
    if (!infile) {
        std::cerr << "Error: Could not open the file \"" << filename << "\"." << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line;

    // Read the file line by line
    while (std::getline(infile, line)) {

        std::istringstream stream(line);
        std::string word;

        // Read individual words
        while (stream >> word) {
            wordCount[word]++;
        }
    }

    // File error check
    if (infile.bad()) {
        std::cerr << "An error occurred while reading the file." << std::endl;
        return 1;
    }

    std::cout << "Number of distinct words: " << wordCount.size() << std::endl;

    // Sort words lexicographically
    std::set<std::string> sortedWords;
    for (const auto &pair : wordCount) {
        sortedWords.insert(pair.first);
    }

    for (const auto &word : sortedWords) {
        std::cout << word << ": " << wordCount[word] << std::endl;
    }

    return 0;
}