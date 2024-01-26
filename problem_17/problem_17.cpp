/*

Craig Bodo
Project Euler

Problem 17
Number Letter Counts

Description:
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used? 

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

Link: https://projecteuler.net/problem=17

To Run:

g++ problem_17.cpp -o problem_17
./problem_17

*/
#include <iostream>
#include <chrono>

void run_program ();
int number_letter_counts (int begin, int end);
int get_count_iterative (int begin, int end);
int get_count_recursive (int curr, int end);

int main() {
    run_program();
    return 0;
}

// Function to get the sum of all letters in a number recursively.
int get_number_word(int n) {
    std::string lows[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string groups[] = {"hundred", "and", "thousand", "million", "billion", "trillion"};

    // Handle cases up to 19
    if (n < 20) {
        return lows[n].size();
    }

    // Handle cases up to 99
    if (n < 100) {
        // Return the number if it is an even "ten" (i.e. 10, 20, etc.)
        if (n % 10 == 0) {
            return tens[n/10].size();
        }
        return tens[n/10].size() + get_number_word(n%10);
    }

    // Handle cases up to 999
    if (n < 1000) {
        // If n is an even "hundred" return count for number and "hundred" (i.e. 100, 200, etc.)
        if (n % 100 == 0) { 
            return lows[n/100].size() + groups[0].size();
        }
        // Add count for "and" if number is not an even "hundred" (i.e. one hundred and two)
        return lows[n/100].size() + groups[0].size() + groups[1].size() + get_number_word(n%100);
    }

    // Handle cases up to 999,999
    if (n < 1000000) {
        return get_number_word(n/1000) + groups[2].size() + get_number_word(n%1000);
    }
 
    // TODO Implement cases for n > 1000000

    return 0;
}

// Iterates through all numbers in the range, adding the sum of letters used to spell the number to the count.
int get_count_iterative (int begin, int end) {
    int sum = 0;
    for (int i = begin; i <= end; ++i) {
        sum += get_number_word(i);
    }
    return sum;
}

// Recursive approach
int get_count_recursive(int curr, int end) {
    if (curr > end) {
        return 0;
    }
    return get_number_word(curr) + get_count_recursive(curr+1, end);
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // Test cases:
    // std::cout << "0 = zero (4): " << get_number_word(0) << '\n'
    //           << "40 = forty (5): " << get_number_word(40) << '\n'
    //           << "42 = forty two (8): " << get_number_word(42) << '\n'
    //           << "300 = three hundred (12): " << get_number_word(300) << '\n'
    //           << "420 = forty hundred and twenty (20): " << get_number_word(420) << '\n'
    //           << "425 = forty hundred and twenty five (24): " << get_number_word(425) << '\n'
    //           << "4253 = four thousand two hundred and fifty three (35): " << get_number_word(4253) << '\n'
    //           << "42540 = forty two thousand five hundred and forty (35): " << get_number_word(42540) << '\n'
    //           << "425403 = four hundred and twenty five thousand four hundred and three (51): " << get_number_word(425403) << '\n';

    int from_number = 1;
    int to_number = 1000;
    int result = get_count_iterative(from_number, to_number);
    // int result = get_count_recursive(from_number, to_number);

    std::cout << "\nThe sum of letters used to write out the numbers " << from_number << " to " << to_number << " is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}