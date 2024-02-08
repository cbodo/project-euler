/*

Project Euler
Problem #31: Coin Sums
Craig Bodo

Description:
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?

Link: https://projecteuler.net/problem=31

To Run:

g++ std=c++11 -o problem_31 problem_31.cpp
./problem_31

*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << endl << "Project Euler - Problem #31: Coin Sums" << endl << endl;

    int n = 200;
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    vector<int> ways(n + 1, 0);

    ways[0] = 1; // Base case: 1 way to make change for 0

    for (int coin : coins) {
        for (int i = coin; i <= n; ++i) {
            ways[i] += ways[i - coin];
        }
    }

    cout << "Minimum number of coins required to make " << n << " is: " << ways[n] << endl;

    return 0;
}
