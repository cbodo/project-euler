/*

Project Euler 
Problem #25: 1000-digit Fibonacci Number
Craig Bodo

Description:
The Fibonacci sequence is defined by the recurrence relation:

F_n = F_{n - 1} + F_{n - 2}, where F_1 = 1 and F_2 = 1.

Hence the first 12 terms will be:

F_1 = 1
F_2 = 1
F_3 = 2
F_4 = 3
F_5 = 5
F_6 = 8
F_7 = 13
F_8 = 21
F_9 = 34
F_{10} = 55
F_{11} = 89
F_{12} = 144

The 12th term, F_{12}, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

Link: https://projecteuler.net/problem=25

To Run:

g++ problem_25.cpp -o problem_25
./problem_25

*/
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    public:
        vector<vector<long long>> data;

        // Constructor to initialize the matrix with a vector
        Matrix(const vector<vector<long long>>& values) : data(values) {}

        // Function for matrix multiplication, e.g.:
        //
        //      |1 1|*|1 1|
        //      |1 0| |1 0|
        //
        Matrix operator*(const Matrix& other) {
            int n = data.size();
            int m = other.data[0].size();
            int p = other.data.size();
            Matrix result(vector<vector<long long>>(n, vector<long long>(m, 0)));

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < p; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }

            return result;
        }
};

// Calculates exponentiation of a matrix
Matrix matrix_power(const Matrix& base, int exp) {
    if (exp == 0) {
        // Get the identity matrix
        int n = base.data.size();
        Matrix identity(vector<vector<long long>>(n, vector<long long>(n, 0)));

        for (int i = 0; i < n; ++i) {
            identity.data[i][i] = 1;
        }
        return identity;
    }

    Matrix result = matrix_power(base, exp/2);
    result = result * result;
    
    if (exp % 2 == 1) {
        result = result * base;
    }

    return result;
}

int count_digits(long long num, int digits = 0) {
    if (num == 0) return digits;
    return count_digits(num /= 10, digits + 1);
}

// Gets the index of the first Fibonacci number with n digits
int index_of_fibonacci_number_with_n_digits(int n) {
    // Initialize matrix
    vector<long long> fibonacci = {0, 1};

    int index = 2;

    while (true) {
        fibonacci.push_back(fibonacci[index - 1] + fibonacci[index - 2]);
        if (fibonacci[index] >= pow(10, n - 1)) {
            return index;
        }
        ++index;
    }

    return -1;
}


int main() {

    cout << endl << "Project Euler - Problem #25: 1000-digit Fibonacci Number" << endl << endl;

    int n = 3;

    cout << "The index of the first term in the Fibonacci sequence to contain " 
         << n 
         << " digits is: " 
         << index_of_fibonacci_number_with_n_digits(n) 
         << endl
         << endl;



    return 0;
}