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

using namespace std;

void fibonacci(int n) {
    vector<int> fibonacci_sequence;
    fibonacci_sequence.insert(fibonacci_sequence.end(), 1);
    fibonacci_sequence.insert(fibonacci_sequence.end(), 1);  
    int i = 2;

    while (i < n) {
        if (fibonacci_sequence.size() >= 2) {
            int next = fibonacci_sequence[i-1] + fibonacci_sequence[i-2];
            fibonacci_sequence.insert(fibonacci_sequence.end(), next);
            cout << "next: " << next << endl;
        }
        i++;
    }

    for (int digit : fibonacci_sequence) {
        cout << digit << endl;
    }
}

int main() {

    // double golden_ratio = (1+sqrt(5))/2;
    // double conjugate_of_golden_ratio = -(1/golden_ratio);
    
    cout << "\nProject Euler - Problem #25: 1000-digit Fibonacci Number\n";

    fibonacci(12);

    return 0;
}