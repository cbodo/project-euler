/*

Project Euler 
Problem #26: Reciprocal Cycles
Craig Bodo

Description:
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

     1/2 = 0.5
	 1/3 = 0.(3)
	 1/4 = 0.25
	 1/5 = 0.2
	 1/6 = 0.1(6)
	 1/7 = 0.(142857)
	 1/8 = 0.125
	 1/9 = 0.(1)
	1/10 = 0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.


Link: https://projecteuler.net/problem=26

To Run:

g++ problem_26.cpp -o problem_26
./problem_26

*/
#include <iostream>
#include <vector>

using namespace std;

// Function to find the denominator (d) with the longest recurring cycle where d < n
int find_longest_recurring_cycle(int n) {
    int longest_cycle = 0;
    int d_with_longest_cycle = 0;

    // Iterate all denominators from 2 to n-1
    for (int d = 2; d < n; ++d) {
        // Vector to store remainders 
        vector<int> remainders(d);
        int numerator = 1;
        // Position of current remainder
        int position = 0;

        // Divide until numerator = 0 or repeating remainder is found
        while (numerator != 0 && remainders[numerator] == 0) {
            // Store current remainder's position
            remainders[numerator] = position++;
            // Multiply numerator by 10 for next division step
            numerator *= 10;
            // Calculate next remainder
            numerator %= d;
        }

        if (numerator != 0) {
            // Calculate length of recurring cycle
            int cycle_length = position - remainders[numerator] + 1;

            // If repeating remainder is found and cycle length > longest cycle,
            if (cycle_length > longest_cycle) {
                // Update longest cycle with current cycle
                longest_cycle = cycle_length;
                // Update d with current denominator
                d_with_longest_cycle = d;
            }
        }
    }
    return d_with_longest_cycle;
}

int main() {
    
    cout << endl << "Project Euler - Problem #26: Reciprocal Cycles" << endl << endl;

    int n = 1000;

    // Run function with n = 10 to show proof in example, then run with n = 1000.
    cout << "Longest recurring cycle for 1/d where d < " << 10 << " is: " << find_longest_recurring_cycle(10) 
         << endl
         << "Longest recurring cycle for 1/d where d < " << n << " is: " << find_longest_recurring_cycle(n) 
         << endl
         << endl;

    return 0;
}