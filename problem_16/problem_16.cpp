/*

Craig Bodo
Project Euler

Problem 16
Power Digit Sum

Description:
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Link: https://projecteuler.net/problem=16

To Run:

g++ problem_16.cpp -o problem_16
./problem_16

*/
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

void run_program ();
void multiply(std::vector<int>& num, int multiplier);
std::vector<int> power(int base, int exponent);
std::string to_superscript(int number);

int main() {
    run_program();
    return 0;
}

// Function to handle large-scale multiplication
void multiply(std::vector<int>& num, int multiplier) {
    int carry = 0;
    for (int i = 0; i < num.size(); ++i) {
        int product = num[i] * multiplier + carry;
        num[i] = product % 10;
        carry = product / 10;
    }

    // Add leftover remainder as a new digit
    while (carry) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}

// Function to calculate large-scale exponentiation
std::vector<int> power(int base, int exponent) {
    std::vector<int> result;
    result.push_back(1);
    for (int i = 0; i < exponent; ++i) {
        multiply(result, base);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Function to convert an integer to its superscript equivalent
std::string to_superscript(int number) {
    std::string superscriptDigits[] = {"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};
    std::string result;
    while (number != 0) {
        int digit = number % 10;
        result = superscriptDigits[digit] + result;
        number /= 10;
    }
    return result;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int base = 2;
    int exp = 1000;
    // long long n = std::pow(base, exp);

    std::vector<int> result = power(base, exp);

    int sum = 0;
    // Prints the result of base^exp, while summing the numbers
    std::cout << "\nInput: " << base << to_superscript(exp) << " = \n\n";
    for (int i = 0; i < result.size(); ++i) {
        if (i % 100 == 0) {
            std::cout << '\t';
        }
        sum += result[i];
        std::cout << result[i];

        if ((i + 1) % 100 == 0 && i != result.size() -1) {
            std::cout << '\n';
        }
    }

    std::cout << "\n\nThe sum of the digits of " << base << to_superscript(exp) <<   " is " << sum << ".\n";

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}