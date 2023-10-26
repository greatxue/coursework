/* P2:
 * File: intArray.cpp
 * ------------------
 * This file inplements the intarray.h interface.
 */
#include <iostream>
// #include "CSC3002OJActive/assignment3/intArray.h"  // For OJ test
#include "intArray.h"  // For local test

using namespace std;

//----------------------------------------------------

#include <string>
#include <sstream>

std::string integerToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

//---------------------------------------------------

/*
 * Implementation notes: IntArray constructor and destructor
 * ---------------------------------------------------------
 * The constructor allocates an array to hold the values and initializes
 * each element to 0; the constructor must also store the effective size
 * in the variable nElements.  The destructor must take responsibility
 * for freeing the dynamic array.
 */

IntArray::IntArray(int n) {
    // TODO
    nElements = n;
    array = new int[n]; // allocate memory for an int array of size n
    for (int i = 0; i < n; i++) {
        array[i] = 0; // initialize each element to be 0
    }
}

IntArray::~IntArray() {
    // TODO
    delete[] array; // free the allocated memory

}

/*
 * Implementation notes: size, get, and set
 * ----------------------------------------
 * Given the data structure, each of these methods is straightforward.
 */

int IntArray::size() {
    // TODO
    return nElements;
}

int IntArray::get(int index) {
    // TODO
    if (index < 0 || index > nElements - 1) {
        cerr << "ERROR: Index range out of bounds!" << endl;
    }
    return array[index];
}

void IntArray::put(int index, int value) {
    // TODO
    if (index < 0 || index > nElements - 1) {
        cerr << "ERROR: Index range out of bounds!" << endl;
    }
    array[index] = value;
}

/*
 * Implementation notes: operator []
 * ---------------------------------
 * The selction operator is identical to get except for the fact that it
 * returns its result by reference.
 */

int & IntArray::operator[](int index) {
    // TODO
    if (index < 0 || index > nElements - 1) {
        cerr << "ERROR: Index range out of bounds!" << endl;
    }
    return array[index];
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a IntArray by value or
 * assign one IntArray to another.
 */

IntArray::IntArray(const IntArray & src) {
    // TODO
    deepCopy(src);
}

IntArray & IntArray::operator=(const IntArray & src) {
    // TODO
    if (this != &src) { // prevent invalid self-assignment
        delete[] array; // free crt memory
        deepCopy(src); // deep-copy approach
    }
    return * this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in
 * which the current object and the source object are independent.
 */

void IntArray::deepCopy(const IntArray & src) {
    // TODO
    nElements = src.nElements; // copy the size of src array
    array = new int[nElements]; // allocate new memory

    for (int i = 0; i < nElements; i++) {
        array[i] = src.array[i]; // copy elements one by one
    }
}

/* DO NOT modify this part*/
int main() {
    int id;
    int size_num;
    cin>>id;
    cin>>size_num;

    if(id==1){
        IntArray array(size_num);
        cout << "array.size(): " << integerToString(array.size()) << '\n' << endl;
        for (int i = 0; i < size_num; i++) {
            cout << "array.get(): " << integerToString(array.get(i)) << endl;
            cout << "array.put(" << i << ", " << i << ");" << endl;
            array.put(i, i);
            cout << "array.get(): " << integerToString(array.get(i))<< '\n' << endl;
        }
        array.get(-1);
        array.put(size_num+1, size_num+1);
    }
    if(id == 2){
        IntArray array(size_num);
        cout << "array.size(): " << integerToString(array.size()) << '\n' << endl;
        for (int i = 0; i < size_num; i++) {
            cout << "array.get(): " << integerToString(array.get(i)) << endl;
            cout << "array[" << i << "] = " << i << ";" << endl;
            array[i] = i;
            cout << "array.get(): " << integerToString(array.get(i))<< '\n' << endl;
        }
    }
    if(id == 3){
        IntArray v1(size_num);
        cout << "v1.size(): " << integerToString(v1.size()) << '\n' << endl;
        for (int i = 0; i < size_num; i++) {
            cout << "v1.get(): " << integerToString(v1.get(i)) << endl;
            cout << "v1[" << i << "] = " << i << ";" << endl;
            v1[i] = i;
            cout << "v1.get(): " << integerToString(v1.get(i))<< '\n' << endl;
        }
        IntArray v2;
        v2 = v1;
        cout << "v2.size(): " << integerToString(v2.size()) << '\n' << endl;
        for (int i = 0; i < v2.size(); i++) {
            cout << "v2.get(): " << integerToString(v2.get(i)) << endl;
        }
        IntArray v3;
        v3 = IntArray(v1);
        cout << '\n' << "v3.size(): " << integerToString(v3.size()) << '\n' << endl;
        for (int i = 0; i < v3.size(); i++) {
            cout << "v3.get(): " << integerToString(v3.get(i)) << endl;
        }
    }
    return 0;
}

