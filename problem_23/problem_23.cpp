/*

Project Euler 
#23 Non-Abundant Sums - Project Euler
Solution by Craig Bodo

Description:
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.


Link: https://projecteuler.net/problem=23

To Run:

g++ problem_23.cpp -o problem_23
./problem_23

*/
#include <iostream>
#include <vector>

using namespace std;

int calculate_divisor_sum(int n) {
    int sum = 1; // Start with 1 since every number is divisible by 1
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) // Avoid counting the square root twice
                sum += n / i;
        }
    }
    return sum;
}

bool is_abundant(int n) {
    return calculate_divisor_sum(n) > n;
}

int sum_non_abundants(int limit) {
    vector<int> abundant_numbers;
    for (int i = 1; i < limit; ++i) {
        if (is_abundant(i))
            abundant_numbers.push_back(i);
    }

    vector<bool> is_abundant_sum(limit + 1, false);
    for (int i = 0; i < abundant_numbers.size(); ++i) {
        for (int j = i; j < abundant_numbers.size(); ++j) {
            int sum = abundant_numbers[i] + abundant_numbers[j];
            if (sum <= limit)
                is_abundant_sum[sum] = true;
            else
                break;
        }
    }

    int sum = 0;
    for (int i = 1; i <= limit; ++i) {
        if (!is_abundant_sum[i])
            sum += i;
    }
    return sum;
}

int main() {
    
    int limit = 28123;

    cout << "\nProject Euler - Problem #23: Non-Abundant Sums\n"
         << "\nThe sum of all positive integers which cannot be written as the sum of two abundant numbers is : "
              << sum_non_abundants(limit);

    return 0;
}