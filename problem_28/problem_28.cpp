/*

Project Euler
Problem #28: Number Spiral Diagonals
Craig Bodo

Description:
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Link: https://projecteuler.net/problem=28

To Run:

g++ problem_28.cpp -o problem_28
./problem_28

*/
#include <iostream>

using namespace std;


int main() {

    cout << endl << "Project Euler - Problem #28: Number Spiral Diagonals" << endl << endl;

    int sum = 0;

    cout << "The sum of diagonals in a 1001 by 1001 spiral is: " << sum << endl;
    return 0;
}
