/*

Craig Bodo
Project Euler

Problem 18
Maximum Path Sum I

Description:
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
     3
    7 4
   2 4 6
  8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

               75
              95 64
            17 47 82
           18 35 87 10
          20 04 82 47 65
         19 01 23 75 03 34
        88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
      41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67 (https://projecteuler.net/problem=67), is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)

Link: https://projecteuler.net/problem=18

To Run:

g++ problem_18.cpp -o problem_18
./problem_18

*/
#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

void run_program ();
int solution (const std::vector<std::vector<int> >& triangle, std::vector<int>& path);
int get_max_value_in_vector (const std::vector<int>& vector);
std::vector<std::vector<int> > make_triangle(const int* numbers, int size);

int main() {
    run_program();
    return 0;
}

// Finds the max value for each row in a 2d vector, and saves the resulting path
// into a vector. Returns the sum of the values that make up the path.
int solution (const std::vector<std::vector<int> >& triangle, std::vector<int>& path) {
    int sum = 0;
    path.clear();
    for (int i = 0; i < triangle.size(); ++i) {
        int max = get_max_value_in_vector(triangle[i]);
        sum += max;
        path.push_back(max);
    }
    return sum;
}

// Gets the max value in a vector
int get_max_value_in_vector (const std::vector<int>& vector) {
    int max = 0;
    for (int value : vector) {
        if (value > max) {
            max = value;
        }
    }
    return max;
}

// Converts an array of ints into a triangle-shaped vector of vectors
std::vector<std::vector<int> > make_triangle(const int* numbers, int size) {
    int levels = std::ceil((std::sqrt(8 * size + 1) - 1) / 2);
    std::vector<std::vector<int> > triangle(levels);
    int current_index = 0;

    for (int current_level = 0; current_level < levels; ++current_level) {
        triangle[current_level].resize(current_level + 1);

        for (int i = 0; i <= current_level; ++i) {
            triangle[current_level][i] = numbers[current_index++];
        }
    }

    return triangle;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int numbers[] = {75, 95, 64, 17, 47, 82, 18, 35, 87, 10, 20, 4, 82, 47, 65, 19, 1, 23, 75, 3, 34, 88, 2, 77, 73, 7, 63, 67, 99, 65, 4, 28, 6, 16, 70, 92, 41, 41, 26, 56, 83, 40, 80, 70, 33, 41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
    
    int size = sizeof(numbers) / sizeof(numbers[0]);
    std::vector<std::vector<int> > triangle = make_triangle(numbers, size);

    // Print the vector with indentation for triangle shape.
    for (int i = 0; i < triangle.size(); ++i) {
        // Add indentation
        for (int j = 0; j < triangle.size() - i - 1; ++j) {
            std::cout << " ";
        }

        // Print current level
        for (int value : triangle[i]) {
            std::cout << (value < 10 ? '0' : '\0') << value << " ";
        }

        std::cout << '\n';
    }

    std::vector<int> path;
    int result = solution(triangle, path);

    std::cout << "\nThe maximum total from top to bottom is made from the path that contains the values: \n\n";

    for (int i = 0; i < path.size(); ++i) {
        std::cout << (i == path.size() - 1 ? "and " : "\0") << path[i] << (i < path.size() - 1 ? ", " : "\0");
    }

    std::cout << ",\n\nwhich sum to " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}
