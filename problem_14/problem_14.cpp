/*

Craig Bodo
Project Euler

Problem 14
Longest Collatz Sequence

Description:
The following iterative sequence is defined for the set of positive integers:

    n -> n/2 (n is even)
    n -> 3m + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

    13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1.

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Link: https://projecteuler.net/problem=14

To Run:

g++ problem_14.cpp -o problem_14
./problem_14

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