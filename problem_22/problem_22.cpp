/*

Project Euler 
#22 Names Scores - Project Euler
Solution by Craig Bodo

Description:
Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Link: https://projecteuler.net/problem=22

To Run:

g++ -std=c++11 problem_22.cpp list.cpp name.cpp -o problem_22
./problem_22

*/
#include "name.h"
#include "list.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

void run_program ();
void get_file_contents(std::vector<std::string>& dest, std::string src);

int main() {
    run_program();
    return 0;
}

// Takes in names from file and store in a vector
void get_file_contents(LinkedList& dest, std::string src) {
    std::ifstream file(src);

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << '\n';
        return;
    }

    std::string line;
    int i = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string str;
        // Read each string, separated by comma
        while (std::getline(ss, str, ',')) {
            str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));  // Remove leading whitespace
            str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);  // Remove trailing whitespace
            // Remove quotes
            if (!str.empty()) {
                if (str.front() == '"') str.erase(0, 1);
                if (str.back() == '"') str.pop_back();
            }
            
            Name new_name(str, i++);
            dest.insert(new_name);
        }
    }
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    
    long long sum = 0;

    LinkedList names;
    get_file_contents(names, "names.txt");
    names.display();
    sum = names.sum_scores();

    std::cout << "The total of all the name scores in the file is: " << sum << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}

