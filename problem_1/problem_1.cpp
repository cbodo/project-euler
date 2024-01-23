/* 

Craig Bodo
Project Euler

Problem 1
Multiples of 3 or 5

Description:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

To Run:
g++ problem_1.cpp -o problem_1
./problem_1

*/

#include <iostream>

int sum_multiples_3_or_5 (int max);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int result = sum_multiples_3_or_5(1000);

    std::cout << "\nThe sum of all multiples of 3 or 5 below 1000 is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Calculates the sum of all multiples of 3 or 5 within the given range.
int sum_multiples_3_or_5 (int max) {
    if(max == 0) return 0;

    int sum = 0;
    int i = 0;

    // Use case i < max since instructions state program should sum all multiples /below/ 1000.
    while(i < max)
    {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
        ++i;
    }

    return sum;
}
