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
#include <vector>

void run_program ();
void find_collatz_sequence (std::vector<long long>& sequence, long long starting_number);
std::vector<long long> find_longest_collatz_sequence (int limit);

int main() {
    run_program();
    return 0;
}

// Function to find the longest Collatz sequence with the given limit.
std::vector<long long> find_longest_collatz_sequence (int limit) {
    std::vector<long long> longest;

    for (long long i = 1; i < limit; ++i) {
        std::vector<long long> current;
        find_collatz_sequence(current, i);
        if (current.size() > longest.size()) {
            longest = current;
        }
    }

    return longest;
} 

// Recursive function to build the Collatz sequece.
void find_collatz_sequence (std::vector<long long>& sequence, long long curr) {
    sequence.push_back(curr);
    if (curr == 1) { return; }
    long long prev = curr;
    find_collatz_sequence(sequence, ((prev % 2 == 0) ? prev / 2 : (3 * prev + 1)));
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int limit = 1000000;
    std::vector<long long> longest_sequence = find_longest_collatz_sequence(limit);

    std::cout << "\nThe Collatz sequence is:\n";

    if (!longest_sequence.empty()) {
        for (long long number : longest_sequence) {
            std::cout << number << " ";
        }
        std::cout << "\nStarting number: " << longest_sequence[0] << std::endl;
    } else {
        std::cout << "No sequence found." << std::endl;
    }

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}