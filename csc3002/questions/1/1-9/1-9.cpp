#include <iostream>

/** Checks if a number is a prime. */
bool isPrime(int num) {
    // Checks the primary conditions for numbers 1, 2, 3.
    if (num <= 1) return false;
    if (num <= 3) return true;

    // If factor 2 or 3 is included then the number is not prime.
    if (num % 2 == 0 || num % 3 == 0) return false;

    /* Checks other factors. It follows:
        FACT: All prime numbers, except 2 and 3, could be written in the form of 6k+-1.
        We thus only check i and i+2, with i starting from 5, iteratively adding 6 each time.
        
        Also, any factors of a number could never exceed its square root, thus we have the condition i * i <= num.
    */
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

/** Finds the prime factorization of a number. */
int factorize(int num) {
    bool firstOutput = true; // Checks if is the first output s.t. x could be omitted.
    
    // Handles the case where the factor is 2, seperately.
    while (num % 2 == 0) {
        if (!firstOutput) std::cout << "x";
        std::cout << "2 ";
        num = num /2;
    }

    // Handles the case for odd factors.
    for (int i = 3; i * i <= num; i+= 2) {
        while (num % i == 0) {
            if (!firstOutput) std::cout << "x ";
            std::cout << i << " ";
            num = num / i;
            firstOutput = false;
        }
    }
    return 0;
}

int main() {
    int inputNum;
    std::cout << "This program factors a number. " << std::endl;
    std::cout << "Enter a number to be factorized: ";
    std::cin >> inputNum;
    
    // Handles the case of prime input, seperately.
    if (isPrime(inputNum)) {
        std::cout << inputNum << " is a prime number such that it could not be factorized. ";
    }
    else factorize(inputNum);
}
