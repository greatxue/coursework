#include <iostream>

int roundToNearestInt(float floatNum) {
    // Adds 0.5 such that it will convert to the nearest integer.
    if (floatNum > 0 || floatNum == 0) {
        floatNum += 0.5;
    }
    else if (floatNum < 0) {
        floatNum -= 0.5;
    }

    floatNum = int(floatNum);
    
    return floatNum;
}

int main() {
    float num;
    std::cout << "This program converts the floating-point number to the nearest integer." << std::endl;
    std::cout << "Please enter the floating-point number: ";
    std::cin >> num;
    std::cout << "The nearest integer is " << roundToNearestInt(num);

    return 0;
}