/*

Project Euler
Problem #32: Pandigital Products
Craig Bodo

Description:
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

Link: https://projecteuler.net/problem=32

To Run:

g++ problem_32.cpp -o problem_32
./problem_32

*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Function to check if a product is pandigital
bool is_pandigital_product(int multiplicand, int multiplier, int product, int n) {
    int digits = (1 << (n + 1)) - 2; // Represents 1 through n pandigital
    while (multiplicand > 0) {
        digits &= ~(1 << (multiplicand % 10));
        multiplicand /= 10;
    }
    while (multiplier > 0) {
        digits &= ~(1 << (multiplier % 10));
        multiplier /= 10;
    }
    while (product > 0) {
        digits &= ~(1 << (product % 10));
        product /= 10;
    }
    return digits == 0;
}

void add_unique(vector<int>& vec, int num) {
    // Check if the number already exists in the vector
    auto it = find(vec.begin(), vec.end(), num);
    if (it == vec.end()) {
        // Number does not exist, add it to the vector
        vec.push_back(num);
    }
}

int get_n_digit_pandigitals(int n) {
    vector<int> products;
    vector<int> digits(n);
    iota(digits.begin(), digits.end(), 1);

    do {
        vector<int> permutation(n);
        for (int digit : digits) {
            permutation.push_back(digit);
        }

        int pandigital_int = 0;
        for (int digit : permutation) {
            pandigital_int = pandigital_int * 10 + digit;

            // Check for pandigital products
            for (int i = 1; i <= n / 2; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int multiplicand = pandigital_int / static_cast<int>(pow(10, j)) % static_cast<int>(pow(10, i));
                    int multiplier = pandigital_int / static_cast<int>(pow(10, n)) % static_cast<int>(pow(10, j - i));
                    int product = pandigital_int % static_cast<int>(pow(10, i));
                    if (is_pandigital_product(multiplicand, multiplier, product, n)) {
                        cout << "Found pandigital product: " << multiplicand << " x " << multiplier << " = " << product << endl;
                        add_unique(products, product);
                    }
                }
            }
        }
    } while (next_permutation(digits.begin(), digits.end()));

    // Sum the unique products
    int product_sum = 0;

    for (int num : products) {
        product_sum += num;
    }

    return product_sum;
}

int main() {

    cout << endl << "Project Euler - Problem #32: Pandigital Products" << endl << endl;

    int n = 9;

    cout << "Sum of all unique products in every " << n << "-digit pandigital number: " << get_n_digit_pandigitals(n) << endl;

    return 0;
}
