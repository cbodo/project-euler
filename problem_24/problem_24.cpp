/*

Project Euler 
Problem #24: Permutations
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
#include <set>

using namespace std;

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        unsigned long long result = 1;
        for (unsigned int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}

int main() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int millionth_index = 1000000;

    int i = 0;
    vector<int> temp = digits;
    while (!temp.empty()) {
        int f = factorial(temp.size() - 1);
        int k = millionth_index/f;
        millionth_index %= f;
        cout << temp[k];
        temp.erase(temp.begin() + k);
        i++;
    }
    cout << endl;

    return 0;
}