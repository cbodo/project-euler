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
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    
    cout << endl << "Project Euler - Problem #26: Reciprocal Cycles" << endl << endl;


    cout << "The value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part is: "
         << endl;

    int n = 1000;

    for (int i = 2; i < n; ++i) {
        double num = 1.0 / i; // Example number
        std::string numStr = std::to_string(num);
        
        // Find the position of the decimal point
        size_t decimalPos = numStr.find('.');
        
        // Calculate the number of digits after the decimal point
        size_t fractionDigits = numStr.size() - decimalPos - 1;
        
        // Detect repeating pattern in the fraction
        std::unordered_map<std::string, size_t> patternMap;
        std::string pattern;
        for (size_t i = decimalPos + 1; i < numStr.size(); ++i) {
            pattern.push_back(numStr[i]);
            if (patternMap.count(pattern)) {
                // Found repeating pattern
                fractionDigits = i - decimalPos - patternMap[pattern];
                break;
            }
            patternMap[pattern] = i - decimalPos;
        }
        
        // Set precision dynamically based on the number of digits in the fraction
        std::cout << std::setprecision(fractionDigits) << num << std::endl;

    }

    return 0;
}