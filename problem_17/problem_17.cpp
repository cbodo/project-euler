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
int get_number_letter_count (int begin, int end);

int main() {
    run_program();
    return 0;
}

int get_number_word(int n) {
    std::string lows[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string groups[] = {"hundred", "and", "thousand", "million", "billion", "trillion"};
    if (n == 0) {
        return 0;
    }
    if (n < 20) {
        // std::cout << lows[n] << " ";
        // std::cout << lows[n-10].size() << " ";
        return lows[n].size();
    }
    if (n < 100) {
        // std::cout << tens[n/10] << " " << lows[n%10] << " ";
        // std::cout << tens[n/10].size() << " " << lows[n%10].size() << " ";
        return tens[n/10].size() + lows[n%10].size();
    }
    if (n < 1000) {
        // std::cout << lows[n/100] << " " << groups[0] << " ";
        // std::cout << lows[n/100].size() << " " << groups[0].size() << " ";
        if (n % 100 != 0) {
            //  std::cout <<  groups[1] << " ";
            //  std::cout <<  groups[1].size() << " ";
             return lows[n/100].size() + groups[0].size() + groups[1].size() + get_number_word(n%100);
        }
        return lows[n/100].size() + groups[0].size() + get_number_word(n%100);
    }
    if (n < 10000) {
        // std::cout << lows[n/1000] << " " <<  groups[2] << " ";
        // std::cout << lows[n/1000].size() << " " <<  groups[2].size() << " ";
        return get_number_word(n/1000) + groups[2].size() + get_number_word(n%1000);
    }
    if (n < 100000) {
        // std::cout << groups[2] << " ";
        // std::cout << get_number_word(n/1000) << " " <<  groups[2].size() << " ";
        return get_number_word(n/1000) + groups[2].size() + get_number_word(n%1000);
    }

    return 0;
}

// Iterates through all numbers in the range, adding the sum of letters used to spell the number to the count.
int get_number_letter_count (int begin, int end) {
    int sum = 0;
    for (int i = begin; i <= end; ++i) {
        sum += get_number_word(i);
    }
    return sum;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int from_number = 1;
    int to_number = 1000;
    int result = get_number_letter_count(from_number, to_number);

    std::cout << "\nThe sum of letters used to write out the numbers " << from_number << " to " << to_number << " is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}