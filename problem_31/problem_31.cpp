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
#include <limits>

using namespace std;

vector<vector<int>> get_change_matrix(const vector<int>& coin_set, int r) {
    vector<vector<int>> m(coin_set.size() + 1, vector<int>(r + 1, 0));

    for (int i = 1; i <= r; ++i) {
        m[0][i] = numeric_limits<int>::max();
    }
    return m;
}

int make_change(const vector<int>& coins, int n) {
    vector<vector<int>> m = get_change_matrix(coins, n);

    for (int c = 1; c <= coins.size(); ++c) {
        int coin = coins[c - 1];
        for (int r = 1; r <= n; ++r) {
            // Use coin
            if (coin == r) {
                m[c][r] = 1;
            }
            // Coin can't be used--use previous combination and exclude coin
            else if (coin > r) {
                m[c][r] = m[c - 1][r];
            }
            // Coin can be used
            else {
                m[c][r] = min(m[c-1][r], 1 + m[c][r - coin]);
            }
        }
    }
    return m.back().back();
}

int main() {

    cout << endl << "Project Euler - Problem #31: Coin Sums" << endl << endl;

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    int n = 200;

    int result = make_change(coins, n);

    cout << "Minimum number of coins required to make " << n << " is: " << result << endl;

    return 0;
}
