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
  if (i > sqrt(n)) {
    return true;
  }
  if (n % i == 0) {
    return false;
  }
  return is_prime(n, i + 1);
}

int main() {

  cout << endl
       << "Project Euler - Problem #27: Quadratic Primes" << endl
       << endl
       << boolalpha << " 1: " << is_prime(1) << endl
       << " 2: " << is_prime(2) << endl
       << " 3: " << is_prime(3) << endl
       << " 4: " << is_prime(4) << endl
       << " 5: " << is_prime(5) << endl
       << " 6: " << is_prime(6) << endl
       << "17: " << is_prime(17) << endl
       << "18: " << is_prime(18) << endl
       << "19: " << is_prime(19) << endl
       << "20: " << is_prime(20) << endl;

  return 0;
}
