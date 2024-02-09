/*

Craig Bodo
Project Euler

Problem 13
Large Sum

Description:
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
...
53503534226472524250874054075591789781264330331690

Link: https://projecteuler.net/problem=13

To Run:

g++ -std=c++11 problem_13.cpp -o problem_13
./problem_13

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<long long> read_numbers(const string& filename) {
    vector<long long> numbers;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return numbers;
    }

    string line;
    while (getline(file, line)) {
        // Extract the first 11 digits and convert string to integer
        long long number = stoll(line.substr(0, 11));
        numbers.push_back(number);
    }

    file.close();
    return numbers;
}

int main() {
    vector<long long> numbers = read_numbers("numbers.txt");

    long long sum = 0;
    for (long long num : numbers) {
        sum += num;
    }

    // Extract the first 10 digits of the sum
    string first_10_digits = to_string(sum).substr(0, 10);
    cout << "First 10 digits of the sum: " << first_10_digits << endl;

    return 0;
}
