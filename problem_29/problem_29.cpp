/*

Project Euler
Problem #29: Distinct Powers
Craig Bodo

Description:
Consider all integer combinations of a^b for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

2^2=4, 2^3=8, 2^4=16, 2^5=32
3^2=9, 3^3=27, 3^4=81, 3^5=243
4^2=16, 4^3=64, 4^4=256, 4^5=1024
5^2=25, 5^3=125, 5^4=625, 5^5=3125

If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:
4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125.

How many distinct terms are in the sequence generated by a^b for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?


Link: https://projecteuler.net/problem=29

To Run:

g++ problem_29.cpp -o problem_29
./problem_29

*/
#include <iostream>
#include <set>

using namespace std;

int main() {
    const int lower_limit = 2;
    const int upper_limit = 100;

    set<double> distinct_terms;

    for (int a = lower_limit; a <= upper_limit; ++a) {
        for (int b = lower_limit; b <= upper_limit; ++b) {
            double result = pow(a, b);
            distinct_terms.insert(result);
        }
    }

    cout << "Number of distinct terms: " << distinct_terms.size() << endl;

    return 0;
}
