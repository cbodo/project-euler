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
#include <vector>
#include <algorithm>

using namespace std;

// Add two numbers represented as vectors
vector<int> add(const std::vector<int>& num1, const std::vector<int>& num2) {
    vector<int> result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    // Iterate from least to most significant digit
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--];
        if (j >= 0) sum += num2[j--];

        // Add least significant digit to result
        result.push_back(sum % 10);
        // Set carry for next iteration
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

void print_number(const vector<int>& vec) {
    for (int it : vec) {
        cout << it;
    }
}

vector<int> nth_fibonacci (int n) {
    vector<int> prev = {1};
    vector<int> curr = {1};

    if (n == 0) return prev;
    if (n == 1) return curr;

    for (int i = 2; i <= n - 1; ++i) {
        vector<int> next = add(prev, curr);
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int digits = 1000;
    vector<int> fib;
    int i = 0;
    while (fib.size() != digits) {
        i++;
        fib = nth_fibonacci(i);
    }
    print_number(nth_fibonacci(i));
    
    cout << endl << i << endl;



    
    return 0;
}