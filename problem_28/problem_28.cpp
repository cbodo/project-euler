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

g++ -std=c++11 problem_28.cpp -o problem_28
./problem_28

*/
#include <iostream>
#include <vector>

using namespace std;

void right(int row, int col) {
	row += 0;
	col += 1;
}

void down(int row, int col) {
	row += 1;
	col += 0;
}

void left(int row, int col) {
	row += 0;
	col -= 1;
}

void up(int row, int col) {
	row -= 1;
	col += 0;
}

void initialize_grid(vector<vector<int>> &grid, int side_len) {
	for (int rows = 0; rows < side_len; ++rows) {
    	vector<int> r;
    	for (int cols = 0; cols < side_len; ++ cols) {
     		r.push_back(0);
     	}
      	grid.push_back(r);
    }
}

void print_grid(const vector<vector<int>> grid, int side_len) {
	for (int r = 0; r < grid.size(); ++r) {
    	for (int c = 0; c < grid.size(); ++ c) {
       		cout << (grid[r][c] < 10 ? ' ' : '\0')
         		 << grid[r][c]
            	 << (((c + 1) % side_len) == 0 ? '\n' : ' ');
     	}
    }
    cout << endl;
}

int main() {

    cout << endl << "Project Euler - Problem #28: Number Spiral Diagonals" << endl << endl;

    int sum = 0;
    int side_len = 5;

    vector<vector<int>> grid;
    initialize_grid(grid, side_len);

    int row = side_len/2;
    int col = side_len/2;
    grid[row][col] = 1;

    print_grid(grid, side_len);

    cout << "The sum of diagonals in a 1001 by 1001 spiral is: " << sum << endl;
    return 0;
}
