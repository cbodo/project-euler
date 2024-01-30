/*

Project Euler 
#23 Non-Abundant Sums - Project Euler
Solution by Craig Bodo

Description:
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.


Link: https://projecteuler.net/problem=23

To Run:

g++ problem_23.cpp -o problem_23
./problem_23

*/
#include <iostream>
#include <chrono>

void run_program ();
bool is_abundant(int n);
int calculate_divisor_sum_recursive(int n, int divisor=1, int sum=0);
int calculate_divisor_sum(int n);

int main() {
    run_program();
    return 0;
}

bool is_deficient(int n) {
    return n > calculate_divisor_sum(n);
}

int calculate_divisor_sum_recursive(int n, int divisor, int sum) {
    if (divisor > n /2) {
        return sum;
    }
    if (n % divisor == 0) {
        sum += divisor;
    }
    return calculate_divisor_sum_recursive(n, divisor+1, sum);
}

int calculate_divisor_sum(int n) {
    return calculate_divisor_sum_recursive(n);
}

int solution () {
    return 0;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int limit = 28123;

    std::cout << calculate_divisor_sum(28);

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}