/*

Craig Bodo
Project Euler

Problem 20
Factorial Digit Sum

Description:
n! means n x (n - 1) x ... x 3 x 2 x 1.

For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!.


Link: https://projecteuler.net/problem=20

To Run:

g++ problem_20.cpp -o problem_20
./problem_20

*/
#include <iostream>
#include <chrono>

void run_program ();
std::vector<int> factorial (int n);
void multiply (std::vector<int>& num, int multiplier);
int vector_sum (std::vector<int>& to_sum);
void solution (int n);

int main() {
    run_program();
    return 0;
}

// Sums all digits in the factorial vector.
int vector_sum (std::vector<int>& to_sum) {
    int sum = 0;
    for (int i = 0; i < to_sum.size(); ++i) {
        sum += to_sum[i];
    }

    return sum;
}

// Factorial function returns a vector with the result of the large-scale factorial multiplication.
std::vector<int> factorial (int n) {
    std::vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= n; ++i) {
        multiply(result, i);
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// Function to handle large-scale multiplication
void multiply (std::vector<int>& num, int multiplier) {
    int carry = 0;
    for (int i = 0; i < num.size(); ++i) {
        int product = num[i] * multiplier + carry;
        num[i] = product % 10;
        carry = product / 10;
    }

    // Add leftover remainder as a new digit
    while (carry) {
        num.push_back(carry % 10);
        carry /= 10;
    }
}

// Outputs the solution.
void solution (int input) {
    std::vector<int> f = factorial(input);
    int result = vector_sum(f);

    std::cout << "\nSum of digits in " << input << "!: ";

    for (int i = 0; i < f.size(); ++i) {
        std::cout << f[i] << (i == f.size() - 1 ? " = " : " + " );
    }

    std::cout << result << '\n';
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Solution for example of 10! for proof
    solution(10);

    // Solution for 100!
    solution(100);

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}