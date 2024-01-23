/*

Craig Bodo
Project Euler

Problem 5
Smallest Multiple

Description:
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

To Run:

g++ problem_5.cpp -o problem_5
./problem_5

*/
#include <iostream>
#include <chrono>

int smallest_multiple (int n);
int gcd(int a, int b);
int lcm(int a, int b);
void print_proof(int result, int n);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Upper limit for finding the smallest positive number divisible by all number 1 to n.
    int n = 20;
    int result = smallest_multiple(n);
    
    print_proof(result, n);
    std::cout << "\nThe smallest positive number that is evenly divisible by all numbers from 1 to " << n << " is: " << result << '\n';
    

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Finds the smallest number divisible by all numbers from 1 to n.
int smallest_multiple (int n) {
    int result = 1;

    for(int i = 2; i < n; ++i) {
        result = lcm(result, i);
    }

    return result;
}

// Calculates greatest common divisor.
int gcd (int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Calculates least common multiple.
int lcm (int a, int b) {
    return (a * b) / gcd(a, b);
}

// Prints proof that each number divides evenly into the result.
void print_proof(int result, int n) {
    std::cout << "\nProof: \n";
    for(int i = n; i > 0; --i) {
        std::cout << result << " / " << (i < 10 ? " " : "") << i << " = " << result/i << '\n';
    }
}