/*

Craig Bodo
Project Euler

Problem 9
Special Pythagorean Triplet

Description:
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

To Run:

g++ problem_9.cpp -o problem_9
./problem_9

*/
#include <iostream>
#include <chrono>
#include <cmath>

int A = 0,  B = 0, C = 0;

bool has_real_square_root (int n);
bool find_pythagorean_triplet (int sum);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int sum = 1000;
    bool result = find_pythagorean_triplet(sum);

    if (result) {
        std::cout << "\na = " << A << "\nb = " << B << "\nc = " << C << '\n';
        std::cout << "\nThe product of the Pythagorean triplet abc, where a + b + c = 1000, is: " 
                << A << " x " << B << " x " << C << " = " << A*B*C << '\n';
    } else {
        std::cout << "\nResult not found.\n";
    }

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Finds the product abc of the Pythagorean triplet for which a + b + c = sum.
bool find_pythagorean_triplet (int sum) {
    for (int a = 1; a < sum; ++a) {
        for (int b = a; b < sum - a; ++b) {
            int c = sum - a - b;
            
            // If all values have a real square root, save the result to corresponding global variables.
            if (has_real_square_root(a) && has_real_square_root(b) && has_real_square_root(c)) {
                A = a;
                B = b;
                C = c;
                return true;
            }
        }
    }
    return false;
}

// Check if the value of n has a real square root
bool has_real_square_root (int n) {
    if (n < 0) { 
        return false;   // Case when n is negative
    }

    double root = std::sqrt(n);
    return std::floor(root) == root;
}