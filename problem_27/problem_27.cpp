/*

Project Euler
Problem #27: Quadratic Primes
Craig Bodo

Description:
Euler discovered the remarkable quadratic formula:

    n^2 + n + 41

It turns out that the formula will produce 40 primes for the consecutive integer
values 0 ≤ n ≤ 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is
divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible
by 41.

The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes
for the consecutive values 0 ≤ n ≤ 79. The product of the coefficients, -79 and
1601, is -126479.

Considering quadratics of the form:

    n^2 + an + b, where |a| < 1000 and |b| ≤ 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that
produces the maximum number of primes for consecutive values of n, starting with
n = 0.

Link: https://projecteuler.net/problem=27

To Run:

g++ problem_27.cpp -o problem_27
./problem_27

*/
#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int n, int i = 2) {
  if (n <= 1 || n % i == 0) {
    return false;
  }
  if (i > sqrt(n)) {
    return true;
  }
  return is_prime(n, i + 1);
}

int main() {

  cout << endl
       << "Project Euler - Problem #27: Quadratic Primes" << endl
       << endl
       << "Find the product of the coefficients, a and b, for the quadratic expression "
       << endl
       << endl
       << "  n^2 + an + b, where |a| < 1000 and |b| ≤ 1000" << endl
       << "  where |n| is the modulus/absolute value of n (e.g. |11| = 11 and |-4| = 4)"
       << endl
       << endl
       << "that produces the maximum number of primes for consecutive values of n, starting with n = 0."
       << endl
       << endl;

  int max_primes = 0;
  int product_ab = 0;

  // Iterate through all ints |a| < 1000 and |b| <= 1000
  for (int a = -999; a < 1000; ++a) {
    for (int b = -1000; b < 1001; ++b) {
      int n = 0;

      // Check primeness of n^2 + an + b for current a, b and n
      while (is_prime((n * n) + (a * n) + b)) {
        n += 1;
      }

      // Update max_primes and product_ab if current values are greater
      if (n > max_primes) {
        max_primes = n;
        product_ab = a * b;
      }
    }
  }

  cout << "The product of coefficients that produces the max number of primes for consecutive values of n is: "
       << product_ab << endl;

  return 0;
}
