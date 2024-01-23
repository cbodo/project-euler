/*

Craig Bodo
Project Euler

Problem 4
Largest Palindrome Product

Description:
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.

To Run:

g++ problem_4.cpp -o problem_4
./problem_4

*/
#include <iostream>
#include <chrono>

bool is_palindrome (int n);
int largest_palindrome (int min, int max);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int result = largest_palindrome(99, 1000);

    std::cout << "\nThe largest palindrome made from the product of two 3-digit numbers is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Function to find the largest palindrome that is the product of two integers within a range.
// Call method with parameters min = 99 and max == 1000 to compare only palindromes with 3-digit numbers.
int largest_palindrome (int min, int max) {
    int largest = 0;

    // Iterate within range to find the largest palindrome made using two integers within the range.
    for(int i = max; i >= min; --i) {
        for(int j = max; j >= min; --j) {
            if(is_palindrome(i*j) && i*j > largest) {
                largest = i*j;
            }
        }
    }
    return largest;
}

// Checks if integer is a palindrome.
bool is_palindrome (int n) {
    // Convert integer to string
    std::string str = std::to_string(n);

    // Reverse string
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());

    // Check if the strings are equal
    return str == reversed;
}
