/*

Craig Bodo
Project Euler

Problem 3
Largest Prime Factor

Description:
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143?

To Run:

g++ problem_3.cpp -o problem_3
./problem_3

*/
#include <iostream>

long largest_prime_factor (long num, long divisor=2);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    long num = 600851475143;
    long result = largest_prime_factor(num);

    std::cout << "\nThe largest prime factor of " << num << " is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Finds the largest prime factor of a number, starting with the smallest divisor possible (2).
long largest_prime_factor (long num, long divisor) {

    // Base case: return when n is 1.
    if(num == 1) { return divisor; }

    // Divide num by the current smallest prime divisor
    while(num % divisor != 0)
    {
        divisor++;
    }

    // Recursive call with updated num and divisor values.
    return largest_prime_factor(num / divisor, divisor);
}
