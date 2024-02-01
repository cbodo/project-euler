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

int find_longest_recurring_cycle(int n) {
    int longest_cycle = 0;

    for (int d = 2; d < n; ++d) {
        vector<int> remainders(d, -1);
        int numerator = 1;
        int position = 0;

        while (numerator != 0 && remainders[numerator] == -1) {
            remainders[numerator] = position++;
            numerator *= 10;
            numerator %= d;
        }

        if (numerator != 0) {
            int cycle_length = position - remainders[numerator];
            if (cycle_length > longest_cycle) {
                longest_cycle = cycle_length;
            }
        }
    }
    return longest_cycle;
}

int main() {
    
    cout << endl << "Project Euler - Problem #26: Reciprocal Cycles" << endl << endl;


    cout << "The value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part is: "
         << endl;

    int n = 10;

    for (int i = 2; i < n; ++i) {
        double q = 1.0 / i;
        int r = i % 1;
        cout << "1/" << i << " = " << q << ", Remainder = " << r << endl;

    }

    return 0;
}