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
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int make_change_greedy(vector<int>& coins, int n) {
    // Sort coins in descending order by denomination
    reverse(coins.begin(), coins.end());

    int num_coins = 0;

    for (int i = 0; i < coins.size(); ++i) {
        while (coins[i] <= n) {
            n -= coins[i];      // Subtract coin denomination from remaining amount
            num_coins++;    // Increment number of coins used
        }
    }
    return num_coins;
}

int main() {

    cout << endl << "Project Euler - Problem #31: Coin Sums" << endl << endl;

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    int n = 200;

    int result = make_change_greedy(coins, n);

    cout << "Minimum number of coins required to make " << n << " is: " << result << endl;

    return 0;
}
