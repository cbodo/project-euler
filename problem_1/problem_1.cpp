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
    auto start = std::chrono::high_resolution_clock::now();

    int sum = 0;

    sum = sum_multiples_3_or_5(1000);

    std::cout << "\nThe sum of all multiples of 3 or 5 below 1000 is: " << sum << '\n';

    // End timestamp
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate runtime
    std::chrono::duration<double> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " seconds\n\n";

    return 0;
}

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
