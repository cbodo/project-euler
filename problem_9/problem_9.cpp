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

using namespace std;

int main() {

    int sum = 1000;

    cout << "\nThe product of the Pythagorean triplet abc, where a + b + c = 1000, is: ";

    for (int a = 1; a < sum / 3 + 1; ++a) {
        for (int b = a; b < sum - a; ++b) {
            int c = sum - a - b;

            if (a*a + b*b == c*c) {
                cout << a << " x " << b << " x " << c << " = "
                     << a * b * c;
                break;
            }
        }
    }

    cout << endl;

    return 0;
}
