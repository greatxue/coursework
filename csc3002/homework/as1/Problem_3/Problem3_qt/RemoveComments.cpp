/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
//#include "CSC3002OJActive/assignment1/RemoveComments.h" //for OJ
//#include "RemoveComments.h" //for local test
using namespace std;


/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */
void removeComments(istream & is, ostream & os) {
    char c, next;
    bool inBlockComment = false;
    bool inLineComment = false;

    // This loop reads from the stream character by character.
    while (is.get(c)) {
        // Cases inside the loop
        if (inBlockComment) {
            if (c == '*' && is.peek() == '/') { // the end of the block comment
                is.get(next); // disposes '/' from the stream
                inBlockComment = false;
            }
            else;
        }
        else if (inLineComment) {
            if (c == '\n') { // line break: alse the end of the line comment
                inLineComment = false;
                os << c; // preserves the line break
            }
            else;
        }

        // Cases outside the loop
        else {
            if (c == '/' && is.peek() == '*') { // Subcases for the start of a block comment
                is.get(next); // dispose '*' from the stream
                inBlockComment = true;
            }
            else if (c == '/' && is.peek() == '/') { // Subcases for the start of a line comment
                is.get(next); // dispose the second '/'
                inLineComment = true;
            }
            else os << c; // output normal code blocks
        }
    }
}

void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}


