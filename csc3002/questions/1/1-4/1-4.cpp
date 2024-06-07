#include <iostream>

int main() {
    int N, k, sum = 0;
    // Inputs a positive iteger.
    std::cout << "Enter a positive integer: ";
    std::cin >> N;

    // Calculates the sum of first N odd integers.
    for (k = 0; k < N; k++) {

        sum += 2 * k + 1;
    }

    // Displays the result.
    std::cout << "The sum of first N odd integers is: " << sum;
    return 0;
}