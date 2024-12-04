// wordcount.cpp
// Kohlby Vierthaler
// 2024/12/03
// source code for wordcount

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <set>
#include <cctype>

//void sanitizeInput(std::string &word) {
    //word.erase(remove_if(word.begin(), word.end(), isspace), word.end());
//}

// Main function
// Pre: 
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
            //sanitizeInput(word);
            wordCount[word]++;
        }
    }

    // Error check
    if (infile.bad()) {
        std::cerr << "Error: An error occurred while reading the file." << std::endl;
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