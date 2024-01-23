/*

Craig Bodo
Project Euler

Problem 6
Sum Square Difference

Description:
The sum of the squares of the first ten natural numbers is,
        1^2 + 2^2 + ... + 10^2 = 385.

The square of the sum of the first ten natural numbers is,
        (1 + 2 + ... + 10)^2 = 55^2 = 3025.

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

To Run:

g++ problem_6.cpp -o problem_6
./problem_6

*/
#include <iostream>
#include <chrono>

int sum_square_difference (int square_of_sum, int sum_of_squares);
int square_of_sum (int x);
int sum_of_squares (int x);


int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    
    int x = 100;
    int square_sum = square_of_sum(x);
    int sum_square = sum_of_squares(x);
    int result = sum_square_difference(square_sum, sum_square);

    std::cout << "\nSquare of the sum of the first " << x << " natural numbers: " << square_sum << '\n'
              << "Sum of the squares of the first " << x << " natural numbers: " << sum_square << '\n'
              << "Difference between the sum of the squares of the first " << x << " natural numbers and the square of the sum: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Calculates the difference between the square of the sums and the sum of the squares.
int sum_square_difference (int square_of_sum, int sum_of_square) {
    return square_of_sum - sum_of_square;
}

// Calculates the square of the sum of x natural numbers.
int square_of_sum (int x) {
    int sum = 0;

    for(int i = 0; i < x + 1; ++i) {
        sum += i;
    }

    return sum*sum;
}

// Calculates the sum of x natural squares.
int sum_of_squares (int x) {
    int sum = 0;

    for(int i = 0; i < x + 1; ++i) {
        sum += (i*i);
    }

    return sum;
}