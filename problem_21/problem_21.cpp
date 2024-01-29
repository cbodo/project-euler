/*

Project Euler 
#21 - #21 Amicable Numbers - Project Euler
Solution by Craig Bodo

Description:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.


For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.


Evaluate the sum of all the amicable numbers under 10000.


Link: https://projecteuler.net/problem=21

To Run:

g++ problem_21.cpp -o problem_21
./problem_21

*/
#include <iostream>
#include <chrono>

void run_program ();
int solution ();

int main() {
    run_program();
    return 0;
}

int solution () {
    return 0;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int result = solution();

    std::cout << "\nSolution: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}