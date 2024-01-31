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

using namespace std;

int rand_between(int min, int max) {
    return min + rand() % (max - min + 1);
}

int get_random(const vector<int>& src) {
    return src[rand_between(0, src.size()-1)];
}

long long get_permutation (const vector<int>& digits) {
    vector<int> temp = digits;
    long long result = 0;
    long long multiplier = 1;
    int n = temp.size();
    
    while (temp.size() > 0) {
        long long digit = get_random(temp);
        long long multiplied = digit * multiplier;
        result += multiplied;
        cout << "temp: ";
        for (int item : temp) {
            cout << item << ' ';
        }
        cout << " digit: " << digit << " multiplier: " << multiplier << " multiplied: " << multiplied << " result: " << result << endl;
        temp.erase(remove(temp.begin(), temp.end(), digit), temp.end());
        multiplier *= 10;
    }

    return result;
}

bool is_in_vec(const vector<long long>& vec, int item, int i = 0) {
    if (i == vec.size()) return false;
    if (item == vec[i]) return true;
    return is_in_vec(vec, item, i+1);
}

int main() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long digit_size = 1000000000;

    vector<long long> permutations;

    int limit = 10;

    while (permutations.size() < limit) {
        long long permutation = get_permutation(digits);
        if (!is_in_vec(permutations, permutation)) {
            cout << endl;
            permutations.push_back(permutation);
            cout << endl;
        }
    }


    cout << "\nProject Euler - Problem #24: Permutations\n";

    for (int i = 0; i < permutations.size(); ++i) {
        cout << permutations[i] << '\n';
    }

    return 0;
}