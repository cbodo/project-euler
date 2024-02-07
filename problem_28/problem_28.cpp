/*

Project Euler
Problem #28: Number Spiral Diagonals
Craig Bodo

Description:
Starting with the number 1 and moving to the right in a clockwise direction a 5
by 5 spiral is formed as follows:

        21 22 23 24 25
        20  7  8  9 10
        19  6  1  2 11
        18  5  4  3 12
        17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed
in the same way?

Link: https://projecteuler.net/problem=28

To Run:

g++ -std=c++11 problem_28.cpp -o problem_28
./problem_28

*/
#include <iostream>

using namespace std;

// Each round of the spiral consists of a square grid with a maximum value X,
// where X is an odd perfect square.
// The size of each round increases by 2 units on each side, starting from 1x1.
// The maximum value X for each round can be calculated using the formula
//     X = (i*2+1)^2, where i is the index of the round (0-indexed).
// The distance between adjacent corners of each round is sqrt(X) - 1.
// The sum of the four corners of each round can be calculated using the formula: sum = 4X - 6(sqrt(X)) - 6.
//
int sum_of_diagonals(int grid_size, int sum=1, int round=1) {
	// Base case: reach the last round
	if (round > grid_size/2)
		return sum;

	// Calculate size of current round
	int sqrt_x = round * 2 + 1;

	// Add the sum of the corners to the total sum
    sum += (4 * sqrt_x * sqrt_x) - (6 * sqrt_x) + 6;

    // Recursively call the function for the next round
    return sum_of_diagonals(grid_size, sum, round + 1);
}

int main() {

  cout << endl
       << "Project Euler - Problem #28: Number Spiral Diagonals" << endl
       << endl;

  int grid_size = 1001;

  int sum = sum_of_diagonals(grid_size);

  cout << "The sum of diagonals in a " << grid_size << " by " << grid_size
       << " spiral is: " << sum << endl;
  return 0;
}
