/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
//#include "CSC3002OJActive/assignment1/lib.h"
using namespace std;

/* A helper function indicating whether the character (capital insensitive) is contained. */
bool contains(const string & s, char ch) {
    char loweredCh = tolower(ch); // transverb to lower capital, anyway
    for (char c : s) {
        if (tolower(c) == loweredCh) {
            return true;
        }
    }
    return false;
}

/* Function to process lines of files. */
int banishLetters() {
    string lettersToBanish;
    string line;

    cin >> lettersToBanish;
    cin.ignore();

    while (getline(cin, line)) {
        string result = "";
        // If not banished, add the character to the end
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
