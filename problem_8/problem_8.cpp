/*

Craig Bodo
Project Euler

Problem 8
Largest Product in a Series

Description:
The four adjacent digits in the 1000-digit number that have the greatest product are 9 x 9 x 8 x 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

To Run:

g++ problem_8.cpp -o problem_8
./problem_8

*/
#include <iostream>
#include <chrono>
#include <string>

// Global variable to store the adjacent digits once the largest product is found.
int ADJACENT_DIGITS[13];

int largest_product_in_series (std::string number, int num_adjacent);
void print_array (int arr[], int size, char delimiter);

int main() {
    // Start timestamp
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    // The number of adjacent digits to find
    int num_adjacent = 13;

    // The 1000-digit number
    std::string number =
        "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";
 
    int result = largest_product_in_series(number, num_adjacent);
    
    // Prints the number in rows
    std::cout << '\n';
    for (int i = 0; i < number.length(); i += 50) {
        std::cout << number.substr(i, 50) << '\n';
    }

    std::cout << "\nThe " << num_adjacent <<  " adjacent digits in the 1000-digit number that have the greatest product are: ";
    print_array(ADJACENT_DIGITS, num_adjacent, ',');
    std::cout << "\nThe value of this product is: " << result << '\n';

    // End timestamp
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    // Calculate runtime in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "\nExecution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}

// Prints an integer array with a char delimiter
void print_array (int arr[], int size, char delimiter) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << delimiter << " ";
        }
    }
}

// Finds the largest product made up of num_adjacent-digit arrays
int largest_product_in_series (std::string number, int num_adjacent) {
    int product = 0;        // Stores product
    int temp_product = 1;   // Temp variable to calculate product
    int temp_digits[13];    // Temp array to store adjacent digits

    // Iterate through all numbers in array to find all num_adjacent-digit arrays
    for (int i = 0; i < number.length() - num_adjacent + 1; ++i) {
        int count = 0;      // Tracks index for current temp_digits array
        temp_product = 1;   // Resets temp product for each new array
        
        // Iterate through current num_adjacent digits to calculate product
        for (int j = i; j < i + num_adjacent; ++j) {
            int current = number[j] - '0';  // Convert char to int
            temp_product *= current;        // Multiply into product
            temp_digits[count] = current;   // Store current digit in temp array
            count += 1;                     // Increment index count
        }

        // If the temp_product is larger than the previous product, temp_product becomes the new product
        if (temp_product > product) {
            product = temp_product;
            // Update global array to store the correct adjacent digits
            for (int k = 0; k < num_adjacent; ++k) {
                ADJACENT_DIGITS[k] = temp_digits[k];
            }
        }
    }
    
    return product;
}
