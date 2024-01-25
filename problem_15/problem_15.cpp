/*

Craig Bodo
Project Euler

Problem 15
Lattice Paths

Description:
Starting in the top left corner of a 2 x 2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20 x 20 grid?

Link: https://projecteuler.net/problem=15

To Run:

g++ problem_15.cpp -o problem_15
./problem_15

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