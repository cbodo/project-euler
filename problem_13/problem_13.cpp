/*

Craig Bodo
Project Euler

Problem 13
Large Sum

Description:
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
...
53503534226472524250874054075591789781264330331690

Link: https://projecteuler.net/problem=13

To Run:

g++ problem_13.cpp -o problem_13
./problem_13

*/
#include <iostream>
#include <chrono>
#include <array>
#include <fstream>
#include <sstream>

std::vector<int> calculate_sum(const std::array<std::array<int, 50>, 100>& input);
std::array<std::array<int, 50>, 100> read_file(const std::string& filename);
void run_program();

int main() {
    run_program();
    return 0;
}

// Returns a vector containing the sum one hundred 50-digit numbers stored in a 2d array.
std::vector<int> calculate_sum(const std::array<std::array<int, 50>, 100>& input) {
    std::vector<int> sum;

    // Iterate over the columns of the 2d array
    for (int col = 0; col < 50; ++col) {
        int column_sum = 0;

        // Add all digits in current column for each row
        for (const auto& row : input) {
            column_sum += row[col];
        }

        // Add to result vector
        sum.push_back(column_sum % 10);

        // Add remainder to next column
        int remainder = column_sum / 10;
        while (remainder > 0) {
            col++;

            // Add a new digit when the end of vector is reached
            if (col == sum.size()) {
                sum.push_back(0);
            }
            column_sum = sum[col] + remainder;
            sum[col] = column_sum % 10;
            remainder = column_sum / 10;
        }
    }

    // Reverse vector to get correct order
    std::reverse(sum.begin(), sum.end());

    return sum;
}

// Read the numbers in from external txt file into a 2d array
std::array<std::array<int, 50>, 100> read_file(const std::string& filename) {
    std::array<std::array<int, 50>, 100> result;
    
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << '\n';
        return result;
    }
    // Read each line from file
    for (int i = 0; i < 100; ++i) {
        std::string line;
        std::getline(file, line);

        // Convert each character to an int and insert into array
        for (int j = 0; j < 50; ++j) {
            if (isdigit(line[j])) {
                result[i][j] = line[j] - '0'; // char to int
            }
        }

    }

    file.close();

    return result;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    auto numbers = read_file("./numbers.txt");
    auto result = calculate_sum(numbers);

    for (int digit : result) {
        std::cout << digit;
    }

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}
