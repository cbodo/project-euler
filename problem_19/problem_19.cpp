/*

Craig Bodo
Project Euler

Problem 19
Counting Sundays

Description:
You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Link: https://projecteuler.net/problem=19

To Run:

g++ problem_19.cpp -o problem_19
./problem_19

*/
#include <iostream>
#include <chrono>
#include <cmath>

void run_program ();
int sunday_counter(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
int get_day_of_week(int day_of_week, int month, int year_of_century, int zero_century);

int main() {
    run_program();
    return 0;
}

// Zeller's Congruence to determine the day of week based on given day, month, and year:
// h = (q + floor((13(m+1))/5) + k + floor(k/4) + floor(j/4) - 2j ) % 7
// where:
//   h = day of week (0 = Sat, 1 = Sun, ..., 6 = Fri)
//   q = day of the month
//   m = month (3 = Mar, 4 = Apr, ..., 12 = Dec, 13 = Jan, 14 = Feb)
//   k = year of century (year mod 100)
//   j = zero-based century (year // 100)
int get_day_of_week(int q, int m, int k, int j) {
    return ((q + static_cast<int>(std::floor((13 * (m + 1)) / 5)) + k + static_cast<int>(std::floor(k / 4)) + static_cast<int>(std::floor(j / 4)) - (2 * j)) % 7);
}

int sunday_counter(int start_year, int end_year) {
    int sunday_count = 1;
    int current_year = start_year;

    while (current_year <= end_year) {
        for (int i = 0; i < 12; ++i) {
            if (i < 2) {
                if(get_day_of_week(1, i+13, current_year%100, current_year/100) == 1) {
                    sunday_count += 1;
                }
            }
            else {
                if(get_day_of_week(1, i+1, current_year%100, current_year/100) == 1) {
                    sunday_count += 1;
                }
            }
        }
        current_year++;
    }

    return sunday_count;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int result = sunday_counter(1901, 2000);

    std::cout << "\nThe number of Sundays the fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000) is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}