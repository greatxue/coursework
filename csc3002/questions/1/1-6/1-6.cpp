#include <iostream>

int main() {
    int inputNumber, largest, secondLargest;

    std::cout << "This program finds the largest and the second largest integers in a list" << std::endl;
    std::cout << "Enter 0 to signal the end of the list." << std:: endl;
    
    largest = secondLargest = 0;

    while (true) {
        std::cout << "? ";
        std::cin >> inputNumber;

        if (inputNumber > largest) {
            secondLargest = largest;
            largest = inputNumber;
        }

        else if (inputNumber > secondLargest) {
            secondLargest = inputNumber;
        }

        if (inputNumber == 0) {
            break;
        }
    }

    std::cout << "The largest number was " << largest << std::endl;
    std::cout << "The second largest number was " << secondLargest << std::endl;

    return 0;
}