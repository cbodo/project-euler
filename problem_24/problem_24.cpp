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

int rand_between(int min, int max) {
    return min + rand() % (max - min + 1);
}

int get_random(const vector<int>& src) {
    return src[rand_between(0, src.size()-1)];
}

bool is_in_set(const std::set<long long>& s, long long val) {
    return s.find(val) != s.end();
}

long long get_permutation (const vector<int>& digits) {
    vector<int> temp = digits;
    long long result = 0;
    long long multiplier = 1;
    
    while (!temp.empty()) {
        int digit = get_random(temp);
        long long multiplied = digit * multiplier;
        result += multiplied;
        temp.erase(remove(temp.begin(), temp.end(), digit), temp.end());
        multiplier *= 10;
    }

    return result;
}

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
    set<long long> permutations;
    const int limit = 1000000;

    while (permutations.size() < factorial(digits.size())) {
        long long permutation = get_permutation(digits);
        if (!is_in_set(permutations, permutation)) {
            permutations.insert(permutation);
        }
    }


    cout << "\nProject Euler - Problem #24: Permutations\n";

    cout << permutations.size();
    

    return 0;
}