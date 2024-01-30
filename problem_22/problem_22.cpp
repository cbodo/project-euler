/*

Project Euler 
#22 - #22 Names Scores - Project Euler
Solution by Craig Bodo

Description:
Using names.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Link: https://projecteuler.net/problem=22

To Run:

g++ problem_22.cpp -o problem_22
./problem_22

*/
#include <iostream>
#include <chrono>

void run_program ();
int solution ();

int main() {
    run_program();
    return 0;
}

int solution () {
    return 0;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int result = solution();

    std::cout << "\nSolution: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}