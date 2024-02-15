/*

Project Euler
Problem #32: Pandigital Products
Craig Bodo

Description:
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Link: https://projecteuler.net/problem=32

To Run:

g++ problem_32.cpp -o problem_32
./problem_32

*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print_vec(const vector<int>& vec) {
    for (int it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

void get_n_digit_permutations(int n) {
    vector<vector<int>> n_permutations;
    vector<int> digits(n);
    iota(digits.begin(), digits.end(), 1);

    do {
        for (int digit : digits) {
            cout << digit << " ";
        }
        cout << endl;
    } while (next_permutation(digits.begin(), digits.end()));
}

int main() {

    cout << endl << "Project Euler - Problem #32: Pandigital Products" << endl << endl;

    get_n_digit_permutations(9);

    return 0;
}
