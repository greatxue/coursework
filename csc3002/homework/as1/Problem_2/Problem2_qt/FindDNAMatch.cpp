/* Q2:
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <iostream>
#include <string>
//#include "CSC3002OJActive/assignment1/FindDNAMatch.h" //for OJ
#include "FindDNAMatch.h" //for local test
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
    // The .h file already defaults the start = 0.
    // The instruction defaluts the strand s1 to be shorter than s2.
    string s1_inverse = matchingStrand(s1);
    int position = s2.find(s1_inverse, start);
    return (s2.npos == position) ? -1 : position;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
    string match;
    char c_match;
    for (char c: strand) {
        if (c == 'A') c_match = 'T';
        else if (c == 'T') c_match = 'A';
        else if (c == 'C') c_match = 'G';
        else if (c == 'G') c_match = 'C';
        else c_match = 'X';
        match += c_match;
    }
    return match;
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
    int pos = 0;
    bool hasMatch = false;
    while ((pos = findDNAMatch(s1, s2, pos)) != -1) {
        cout << s1 << " matches " << s2 << " at position " << pos << endl;
        hasMatch = true;
        pos++;
    }
    if (!hasMatch) {
        cout << s1 << " has no matches in " << s2 << endl;
    }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/

/*
 * This part is for the unit-test intentionally left in the annotation.

int main() {
    // Unit_Test1: matchingStrand()
    string s1, s2, s3, s4;
    bool result1, result2, result3, result4;
    s1 = "ATCGGCCT";
    s2 = "GGCGGATT";
    s3 = "HJHHXDDCT";
    s4 = "AAAAA";

    result1 = matchingStrand(s1) == "TAGCCGGA";
    result2 = matchingStrand(s2) == "CCGCCTAA";
    result3 = matchingStrand(s3) == "XXXXXXXGA";
    result4 = matchingStrand(s4) == "TTTTT";

    // Expected: 1111
    std::cout << "Unit_Test1:" << result1 << result2 << result3 << result4 << endl;

    // Unit_Test2:
    bool result5, result6, result7, result8, result9;
    result5 = 7 == findDNAMatch("ATTATTGC", "GCGCGCGTAATAACGAAAAA");
    result6 = 10 == findDNAMatch("TAATAC", "ATTATGCGCGATTATGGCG", 3);
    result7 = -1 == findDNAMatch("SSXGSGCCATT", "XXXXXXXXXXXGGTAAXXXXXXXX", 1);
    result8 = -1 == findDNAMatch("ATTATTGC", "TAATAAGAAA");
    result9 = 2 == findDNAMatch("ATTA", "GCTAATGTAATGTAAT");
    // Expected: 11111
    std::cout << "Unit_Test2:" << result5 << result6 << result7 << result8 << result9 << endl;

    return 0;
}
*/


int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2;
    findAllMatches(s1, s2);
    return 0;
}

