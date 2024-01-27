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

void run_program ();
int solution ();
int date_counter(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
bool is_leap_year(int year);
std::time_t get_time(int year, int day, int month);

int main() {
    run_program();
    return 0;
}

int date_counter(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day) {
    int sunday_count = 1;
    int current_year = start_year;
    int current_month = start_month;
    int current_day = start_day;

    while (current_year <= end_year) {
        std::cout << current_year << '\n';
        for (int i = 0; i < 12; ++i) {
            if (i == 1) {
                if (is_leap_year(current_year)) {
                    std::cout << (i+1 < 10 ? '0' : '\0') << i+1 << ": 29 days" << '\n';
                }
                std::cout << (i+1 < 10 ? '0' : '\0') << i+1 << ": 28 days" << '\n';
            }
            else if (i == 3 || i == 5 || i == 8 || i == 10 ) {
                std::cout << (i+1 < 10 ? '0' : '\0')<< i+1 << ": 30 days" << '\n';
            }
            else {
                std::cout << (i+1 < 10 ? '0' : '\0')<< i+1 << ": 31 days" << '\n';
            }
            
        }
        current_year++;
    }
}

bool is_leap_year(int year) {
    return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}

int solution () {
    return 0;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    date_counter(1901, 1, 1, 2000, 12, 31);

    // int result = solution();

    // std::cout << "\nSolution: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}