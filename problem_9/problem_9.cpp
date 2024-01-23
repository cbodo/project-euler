/*

Craig Bodo
Project Euler

Problem 10
Summation of Primes

Description:
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

To Run:

g++ problem_9.cpp -o problem_9
./problem_9

*/
#include <iostream>
#include <chrono>

bool is_prime (int n);
long long sum_primes (int n);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int n = 2000000;
    long long result = sum_primes(n);

    std::cout << "\nThe sum of all primes below " << n << " is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Checks the primeness of a number.
bool is_prime (int n) {
    // n is 1, so it is not prime.
    if (n < 2) { 
        return false; 
    }

    // n is 2, so it is prime.
    if (n == 2) { 
        return true; 
    }

    // n is divisible by 2, so it is not prime.
    if (n % 2 == 0) {
        return false;
    }

    // Check divisibility of n for odd numbers
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) {
            // n is divisble by i, so it is not prime.
            return false;
        }
    }
    return true;
}

// Sums all prime numbers under n.
long long sum_primes (int n) {
    long long sum = 2;    // Start sum at 2, the first prime number

    // Iterate through all numbers below n, skipping odd numbers
    // The count starts at 3 since we have already counted 1 and 2.
    for (long long count = 3; count < n; count += 2) {
        if(is_prime(count)) {
            sum += count;
        }
    }

    return sum; 
}