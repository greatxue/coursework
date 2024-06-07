/* P1:
 * File: WildcardMatch.cpp
 * -----------------------
 * This program tests the wildcardMatch method, which
 * matches a filename against a pattern containing the wildcard
 * characters * and ?.
 */

#include <iostream>
#include <string>
// #include "CSC3002OJActive/assignment4/WildcardMatch.h" //for OJ test
// #include "WildcardMatch.h" // for local test
using namespace std;

/*
 * Method: wildcardMatch
 * Usage: if (wildcardMatch(filename, pattern)) . . .
 * --------------------------------------------------
 * This method checks to see whether filename matches the pattern,
 * which consists of three types of characters:
 *
 * 1. The character ?, which matches any single character
 * 2. The character *, which matches any string of characters
 * 3. Any other character, which matches only that character
 */

bool wildcardMatch(string filename, string pattern) {
    int n = filename.size();
    int m = pattern.size();
    int i = 0, j = 0;
    int starIndex = -1, matchIndex = -1;

    while (i < n) {
        if (j < m && (filename[i] == pattern[j] || pattern[j] == '?')) {
            // Characters match or pattern character is '?'
            i++;
            j++;
        } else if (j < m && pattern[j] == '*') {
            // Pattern character is '*', check for any sequence
            starIndex = j;
            matchIndex = i;
            j++;
        } else if (starIndex != -1) {
            // Last pattern character was '*', but current characters don't match
            // Try next position in string for '*'
            j = starIndex + 1;
            matchIndex++;
            i = matchIndex;
        } else {
            // Characters don't match and no '*' to adjust positions
            return false;
        }
    }

    // Check for remaining characters in pattern
    while (j < m && pattern[j] == '*') {
        j++;
    }

    // If we have reached the end of both strings, they match
    return j == m;
}


/* DO NOT modify the main() part */

int main() {
   string in_pair, filename, pattern;
   bool matchResult;
   while(getline(cin,in_pair)){
      int sp = in_pair.find(' ');
      filename = in_pair.substr(0, sp);
      pattern = in_pair.substr(sp+1, in_pair.size());
      matchResult = wildcardMatch(filename, pattern);
      cout << boolalpha  << matchResult << endl;
    }
   return 0;
}

