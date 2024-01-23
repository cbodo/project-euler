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
    // Start run timestamp
    auto start = std::chrono::high_resolution_clock::now();
    int x = 100;
    int square_sum = square_of_sum(x);
    int sum_square = sum_of_squares(x);
    int result = sum_square_difference(square_sum, sum_square);

    std::cout << "\nSquare of the sum of the first " << x << " natural numbers: " << square_sum << '\n'
              << "Sum of the squares of the first " << x << " natural numbers: " << sum_square << '\n'
              << "Difference between the sum of the squares of the first " << x << " natural numbers and the square of the sum: " << result << '\n';

    // End run timestamp
    auto end = std::chrono::high_resolution_clock::now();
    // Calculates runtime
    std::chrono::duration<double> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " seconds\n\n";

    return 0;
}

int sum_square_difference (int square_of_sum, int sum_of_square) {
    return square_of_sum - sum_of_square;
}

int square_of_sum (int x) {
    int sum = 0;

    for(int i = 0; i < x + 1; ++i) {
        sum += i;
    }

    return sum*sum;
}

int sum_of_squares (int x) {
    int sum = 0;

    for(int i = 0; i < x + 1; ++i) {
        sum += (i*i);
    }

    return sum;
}