#include <iostream>
using namespace std;

const int SENTINEL = -1;

int main() {
    cout << "This program adds a list of numbers and prints out the average." << endl;
    cout << "Use " << SENTINEL << " to signal the end." << endl;
    int total = 0, num = 0, avg = 0;
    while (true) {
        int value;
        cout << "? ",
        cin >> value;
        if (value == SENTINEL) break;
        total += value;
        num += 1;
    }
    avg = float(total) / float(num);

    cout << "The average number is " << avg << endl;
    return 0;
}