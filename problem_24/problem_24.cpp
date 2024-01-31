/*

Project Euler 
Problem #24: Lexicographic Permutations
Craig Bodo

Description:
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


Link: https://projecteuler.net/problem=24

To Run:

g++ -std=c++11 problem_24.cpp -o problem_24
./problem_24

*/
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

unsigned long long factorial(unsigned int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

void get_nth_lexicographic_permutation(vector<int> digits, int nth_index, int i = 0) {
    if (digits.empty()) return;
    int f = factorial(digits.size() - 1);
    int k = nth_index/f;
    nth_index %= f;
    cout << digits[k];
    digits.erase(digits.begin() + k);
    get_nth_lexicographic_permutation(digits, nth_index, i + 1);
}

int main() {
    cout << "\nProject Euler - Problem #24: Lexicographic Permutations\n";

    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int nth_index = 1000000;

    cout << "\nThe " << nth_index << "th lexicographic permutation of the digits (";

    for (int i = 0; i < digits.size(); ++i) {
        cout << digits[i] << (i == digits.size() - 1 ? ") " : ", ");
    }

    cout << "is: ";

    get_nth_lexicographic_permutation(digits, nth_index);

    cout << endl << endl;

    return 0;
}