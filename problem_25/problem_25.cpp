/*

Project Euler 
Problem #25: 1000-digit Fibonacci Number
Craig Bodo

Description:
The Fibonacci sequence is defined by the recurrence relation:

F_n = F_{n - 1} + F_{n - 2}, where F_1 = 1 and F_2 = 1.

Hence the first 12 terms will be:

F_1 = 1
F_2 = 1
F_3 = 2
F_4 = 3
F_5 = 5
F_6 = 8
F_7 = 13
F_8 = 21
F_9 = 34
F_{10} = 55
F_{11} = 89
F_{12} = 144

The 12th term, F_{12}, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Link: https://projecteuler.net/problem=25

To Run:

g++ problem_25.cpp -o problem_25
./problem_25

*/
#include <iostream>
#include <cmath>

using namespace std;

// Function to multiply two vectors representing large numbers
vector<int> multiply(vector<int>& num1, vector<int>& num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> result(n1 + n1, 0);

    for (int i = 0; i < n1; ++i) {
        int carry = 0;
        for (int j = 0; j < n2 || carry; ++j) {
            int temp = result[i + j] + num1[i] * (j < n2 ? num2[j] : 0) + carry;
            result[i + j] = temp % 10;
            carry = temp / 10;
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

// Uses the golden ratio to find nth Fibonacci number:
//
//      x_n = (φ^n - (1 - φ)^n) ÷ √5
//
// where:
//
//      φ = (1 + √5) ÷ 2
//
long long nth_fibonacci_digit (int n) {
    double golden_ratio = (1+sqrt(5))/2;
    double conjugate = 1 - golden_ratio;
    return (pow(golden_ratio, n) - pow((conjugate), n))/sqrt(5);
}

void get_fibonacci_sequence_to_n (int n, int i = 0) {
    if (i == n) return;
    cout << nth_fibonacci_digit(i) << endl;
    get_fibonacci_sequence_to_n(n, i+1);
}

int main() {
    
    cout << "\nProject Euler - Problem #25: 1000-digit Fibonacci Number\n";

    // fibonacci(12);

    // nth_fibonacci_digit(12);

    get_fibonacci_sequence_to_n(100);

    return 0;
}