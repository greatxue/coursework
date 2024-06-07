#include <iostream>

int main() {
    int inputNumber, Comparator;

    std::cout << "This program finds the largest integer in a list" << std::endl;
    std::cout << "Enter 0 to signal the end of the list." << std:: endl;
    
    Comparator = 0;

    while (true) {
        std::cout << "? ";
        std::cin >> inputNumber;
        if (inputNumber > Comparator) {
            Comparator = inputNumber;
        }
        if (inputNumber == 0) {
            break;
        }
    }
    std::cout << "The larget value was " << Comparator << std::endl;
    
    return 0;
}