/*

Project Euler
Problem #30: Digit Fifth Powers
Craig Bodo

Description:
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.
Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

Link: https://projecteuler.net/problem=30

To Run:

g++ problem_30.cpp -o problem_30
./problem_30

*/
#include <iostream>

using namespace std;

int sum_of_digit_powers (int n, int power) {
    int sum = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, power);
        temp /= 10;
    }
    return sum;
}

long long find_sum_of_powers (int power) {
    long long total = 0;
    int limit = pow(9, power) * (log10(pow(9, power)) + 1); // Determines upper limit
    for (int i = 10; i < limit; ++i) {
        int sum_of_powers = sum_of_digit_powers(i, power);
        if (i == sum_of_powers) {
            total += i;
        }
    }
    return total;
}

int main() {

    cout << endl << "Project Euler - Problem #30: Digit Fifth Powers" << endl << endl;

    int power = 5;
    long long result = find_sum_of_powers(power);

    cout << "The sum of all numbers that can be written as the sum of " << power << "th powers of their digits: "
         << result << endl;

    return 0;
}
