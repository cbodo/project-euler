/*

Craig Bodo
Project Euler

Problem 7
10001st Prime

Description:
By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

To Run:

g++ problem_7.cpp -o problem_7
./problem_7

*/
#include <iostream>
#include <chrono>
#include <string>

bool is_prime (int n);
int find_nth_prime (int n);
std::string get_cardinality(int n);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int n = 10001;
    int result = find_nth_prime(n);

    std::cout << "\nThe: " << n << get_cardinality(n) << " prime number is: " << result << '\n';

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

// Finds the nth prime number.
int find_nth_prime (int n) {
    if (n == 1) {
        return 2;
    }

    int count = 1;
    int nth_prime = 3;

    while(count < n) {
        if(is_prime(nth_prime)) {
            ++count; 
        }
        nth_prime += 2; // skip even numbers
    }

    return nth_prime - 2; // subtract 2 to get correct number
}

// Gets the cardinality of a number.
std:: string get_cardinality(int n) {
    if((n % 100 >= 11) && (n % 100 <= 13)) {
        return "th";
    } else {
        switch (n % 10) {
            case 1: return "st";
            case 2: return "nd";
            case 3: return "rd";
            default: return "th";
        }
    }
}
