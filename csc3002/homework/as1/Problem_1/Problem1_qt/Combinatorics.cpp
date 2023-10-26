/* assignment1 Q1:
 * File: combinatorics.cpp
 * -----------------------
 * This file implements the combinatorics.h interface.
 */

/*
 * header file for OJ system
 */
// #include <iostream>
// #include <iomanip>
// using namespace std;


/*
 * header file for local test
 */
#include <iostream>
//#include "CSC3002OJActive/assignment1/Combinatorics.h" // Uncomment this line if you submit it to OJ and need to use the headerfile
//#include "Combinatorics.h" // Uncomment this line, for local test
using namespace std;


/* Function prototypes */

int fact(int n);

/*
 * Implementation notes: permutations
 * ----------------------------------
 * This function takes advantage of the property that n! divided by (n - k)!
 * is simply the first k terms in the product
 *
 *     n * (n - 1) * (n - 2) * . . .
 */

int permutations(int n, int k) {
    int product = 1;
    for (int i = 0; i < k; i++) {
        product *= n - i;
    }
    return product;
}

/*
 * Implementation notes: combinations
 * ----------------------------------
 * This function returns the permutations value divided by k!, which
 * is computed by the function fact.
 */

int combinations(int n, int k) {
    return permutations(n, k) / fact(k);
}

/*
 * Function: fact(n)
 * Usage: int result = fact(n);
 * ----------------------------
 * Returns the factorial of n, which is the product of all the
 * integers between 1 and n, inclusive.
 */

int fact(int n) {
    int product = 1;
    for (int j = 1; j < n + 1; j++){
        product *= j;
    }
    return product;
}



// DO NOT modify the main() function!
// for the samplt output:
/*
  input:  3 2
  output: 6 3
 */

int main(int argc, char* argv[]) {
    int n,k;
    cin>>n>>k;
    cout <<permutations(n, k) << ' ';
    cout <<combinations(n, k);
    cout << endl;
    return 0;
}
