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

// Formula to find the index of the first number in the fibonacci sequence 
// with 1000 digits. Uses the inverse of Binet's formula to calculate.
int get_index_of_fib_with_n_digits(int n) {
    if (n < 2) return 1;
    double phi = (1 + sqrt(5))/2;
    return ceil((n + log10(5) / 2 - 1) / log10(phi));
}

int main() {

    cout << endl << "Project Euler - Problem #25: 1000-digit Fibonacci Number" << endl << endl;

    int n = 1000;

    // Find the index. First run with example problem for proof, then find the index with n digits.
    cout << "The index of the first term in the Fibonacci sequence to contain " 
         << 3 
         << " digits is: " 
         << get_index_of_fib_with_n_digits(3) 
         << endl
         << "The index of the first term in the Fibonacci sequence to contain " 
         << n 
         << " digits is: " 
         << get_index_of_fib_with_n_digits(n) 
         << endl
         << endl;



    return 0;
}