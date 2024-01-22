/* 

Project Euler

Problem 1
Multiples of 3 or 5

Description:
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

To Run:
g++ your_program.cpp -o your_program
./your_program

*/

#include <iostream>

int sum_multiples_3_or_5 (int max) {
    if(max == 0) return 0;

    int sum = 0;
    int i = 0;

    // Use case i < max since instructions state program should sum all multiples /below/ 1000.
    while(i < max)
    {
        if (i % 3 == 0 || i % 5 == 0) sum += i;
        ++i;
    }

    return sum;
}

int main() {

    int sum = 0;

    sum = sum_multiples_3_or_5(1000);

    std::cout << std::endl << "Project Euler" << std::endl << std::endl
              << "Problem 1" << std::endl
              << "Multiples of 3 or 5" << std::endl << std::endl
              << "Description:" << std::endl << std::endl
              << "If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23." << std::endl
              << "Find the sum of all the multiples of 3 or 5 below 1000." << std::endl
              << std::endl;

    std::cout << "The sum of all multiples of 3 or 5 below 1000 is: " << sum << std::endl;

    return 0;
}
