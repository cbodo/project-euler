/*

Craig Bodo
Project Euler

Problem 15
Lattice Paths

Description:
Starting in the top left corner of a 2 x 2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20 x 20 grid?

Link: https://projecteuler.net/problem=15

To Run:

g++ problem_15.cpp -o problem_15
./problem_15

*/
#include <iostream>
#include <chrono>

void run_program ();
long long factorial (int n);
long long lattice_paths(int n);

int main() {
    run_program();
    return 0;
}

// Function to calculate the number of lattice paths in a grid of size n x n
long long lattice_paths(int n) {
    // Number of paths for each cell in the grid
    std::vector<std::vector<long long> > path_count(n + 1, std::vector<long long>(n + 1, 0));

    // Initialize paths for cells in first row and col
    for (int i = 0; i <= n; ++i) {
        path_count[0][i] = 1;
        path_count[i][0] = 1;
    }

    // Calculate number of paths for each cell
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Paths needed to reach cell (i,j) is the sum of paths from adjacent cells above and to the left
            path_count[i][j] = path_count[i - 1][j] + path_count[i][j - 1];
        }
    }

    return path_count[n][n];
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    long long grid_size = 20;
    long long paths = lattice_paths(grid_size);

    std::cout << "\nThe number of lattice paths in a " << grid_size << " x " << grid_size << " grid is: " << paths << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}