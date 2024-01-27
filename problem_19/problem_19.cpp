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
#include <iomanip>
#include <ctime>

void run_program ();
int solution ();
bool is_leap_year(int year);
std::time_t get_time(int year, int day, int month);

int main() {
    run_program();
    return 0;
}

bool is_leap_year(int year) {
    return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}

std::time_t get_time(int year, int month, int day) {
    // Create a tm structure and populate it with user input
    std::tm date = {0};
    date.tm_year = year - 1900; // Years since 1900
    date.tm_mon = month - 1;     // Months since January (0-based)
    date.tm_mday = day;          // Day of the month

    // Convert tm structure to a time_t object
    std::time_t time = std::mktime(&date);
    return time;
}

int solution () {
    return 0;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    std::time_t start_time = get_time(1901, 1, 1);
    std::time_t end_time = get_time(2000, 12, 31);

    // Convert time_t to a readable string format
    char start_time_buffer[80];
    std::strftime(start_time_buffer, sizeof(start_time_buffer), "%A, %B %d, %Y", std::localtime(&start_time));

    // Display the formatted date
    std::cout << "\nStart date: " << start_time_buffer << std::endl;

    // Convert time_t to a readable string format
    char end_time_buffer[80];
    std::strftime(end_time_buffer, sizeof(end_time_buffer), "%A, %B %d, %Y", std::localtime(&end_time));

    // Display the formatted date
    std::cout << "\nEnd date: " << end_time_buffer << std::endl;

    // int result = solution();

    // std::cout << "\nSolution: " << result << '\n';

    // int from = 1900;
    // int to = 2024;
    // int sum = 0;
    // std::vector<int> leap_years;
    // for (int i = from; i <= to; ++i) {
    //     if (is_leap_year(i)) {
    //         sum += 1;
    //         leap_years.push_back(i);
    //     }
    // }
    // std::cout << "Number of leap years from 1900 to 2024: " << sum << '\n';

    // for (int j = 0; j < leap_years.size(); ++j) {
    //     std::cout << leap_years[j] << '\n';
    // }

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}