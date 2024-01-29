/*

Project Euler 
#21 - #21 Amicable Numbers - Project Euler
Solution by Craig Bodo

Description:
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.


Link: https://projecteuler.net/problem=21

To Run:

g++ problem_21.cpp -o problem_21
./problem_21

*/
#include <iostream>
#include <chrono>
#include <vector>

void run_program ();
std::vector<int> get_divisors(int n);
int get_divisor_sum(int n);
int sum_all_amicable_numbers(int n);

int main() {
    run_program();
    return 0;
}

int sum_all_amicable_numbers(int n) {
    int sum = 0;
    std::vector<int> amicable_numbers;
    for (int i = 0; i < n; ++i) {
        int num = get_divisor_sum(i);
        auto found_num = std::find(amicable_numbers.begin(), amicable_numbers.end(), num);

        if (found_num == amicable_numbers.end()) {
            int amicable_num = get_divisor_sum(num);
            // auto found_amicable = std::find(amicable_numbers.begin(), amicable_numbers.end(), amicable_divisor);
            if (i == amicable_num && num != amicable_num) {
                sum += num;
                amicable_numbers.push_back(num);
                sum += amicable_num;
                amicable_numbers.push_back(amicable_num);
                std::cout << "\nAmicable Pair: (" << num << ", " << amicable_num << ")\tSum: " << num+amicable_num;
            }
        }
    }
    return sum;
}

int get_divisor_sum(int n) {
    int sum = 0;
    std::vector<int> divisors = get_divisors(n);
    for (int i = 0; i < divisors.size(); ++i) {
        sum += divisors[i];
    }
    return sum;
}

std::vector<int> get_divisors(int n) {
    std::vector<int> divisors;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n/i != n) {
                divisors.push_back(n/i);
            }
        }
    }
    std::sort(divisors.begin(), divisors.end());
    return divisors;
}

void run_program () {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    int n = 10000;

    std::cout << "\nAmicable Numbers under " << n << ":\n";
    int result = sum_all_amicable_numbers(n);

    std::cout << "\n\nThe sum of all Amicable Numbers under " << n << " is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;
}