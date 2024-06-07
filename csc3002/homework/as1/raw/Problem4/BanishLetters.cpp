/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
//#include "CSC3002OJActive/assignment1/lib.h"
using namespace std;

bool contains(const string & s, char ch) {
    char loweredCh = tolower(ch);
    for (char c : s) {
        if (tolower(c) == loweredCh) {
            return true;
        }
    }
    return false;
}

int banishLetters() {
    string lettersToBanish;
    string line;

    cout << "Input the letters to be eliminated: ";
    cin >> lettersToBanish;

    // Consume the newline left in the buffer
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter lines of text (CTRL+D or CTRL+Z to end):\n";
    while (getline(cin, line)) {
        string result = "";
        for (char ch : line) {
            if (!contains(lettersToBanish, ch)) {
                result += ch;
            }
        }
        cout << result << endl;
    }
    return 0;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
