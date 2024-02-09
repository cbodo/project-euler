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
#include <vector>

using namespace std;

// Recursive function to build the Collatz sequece.
void find_collatz_sequence (vector<long long>& sequence, long long curr) {
    sequence.push_back(curr);
    if (curr == 1) { return; }
    long long prev = curr;
    find_collatz_sequence(sequence, ((prev % 2 == 0) ? prev / 2 : (3 * prev + 1)));
}

// Function to find the longest Collatz sequence with the given limit.
vector<long long> find_longest_collatz_sequence (int limit) {
    vector<long long> longest;

    for (long long i = 1; i < limit; ++i) {
        vector<long long> current;
        find_collatz_sequence(current, i);
        if (current.size() > longest.size()) {
            longest = current;
        }
    }

    return longest;
}

int main() {

    int limit = 1000000;
    vector<long long> longest_sequence = find_longest_collatz_sequence(limit);

    cout << "\nThe starting number < "
         << limit
         << " that produces the longest Collatz chain is: "
         << longest_sequence[0]
         << endl;


    return 0;
}
