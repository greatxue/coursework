#include <iostream>
using namespace std;

int main() {
    double celsius, fahrenheit;

    // Inputs temperature in Celsius.
    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = (9.0 / 5.0) * celsius + 32;

    // Displays the result.
    cout << "Statement: " << celsius << "°C is " << fahrenheit << "°F" << endl;

    return 0;
}

