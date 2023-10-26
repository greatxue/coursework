#include <iostream>

int reverseNumber(int originNumber) {
    int reversedNumber = 0, lastDigitOfN = 0;
    
    // The loop will not pause until we have processed every digit of N.
    while (originNumber != 0) {

        lastDigitOfN =  originNumber % 10;   // Gets the last digit of N.
        reversedNumber = reversedNumber * 10 + lastDigitOfN;   // Circulates the digits.
        originNumber /= 10;   // Removes the last processed digit of N.
    }
    
    return reversedNumber;
}

int main() {
    int num;
    
    std::cout << "This program reverses the digits in an integer." << std::endl;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    
    int reversedNum = reverseNumber(num);
    
    std::cout << "The reversed integer is " << reversedNum << std::endl;
    std::cin >> num;
    return 0;
    
}
