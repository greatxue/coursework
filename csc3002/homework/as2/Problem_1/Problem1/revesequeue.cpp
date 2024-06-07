/* P1:
 * File: reversequeue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
//#include "CSC3002OJActive/assignment2/reversequeue.h" // For OJ test
//#include "reversequeue.h" // For local test
#include <stack>
#include <queue>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
    stack<string> strstack;
    // Deque all elements from the queue to push onto the stack.
    while (!queue.empty()){
        strstack.push(queue.front());
        queue.pop();
    }

    // Pop all the elements from the stack out and enque them back into the deque.
    while (!strstack.empty()) {
        queue.push(strstack.top());
        strstack.pop();
    }
}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & queue) {
    int size = queue.size();
    cout << "The queue contains:" << " ";
    // put the front of the queue backward, iterally
    for (int i = 0; i < size; i++) {
        string front = queue.front();
        cout << front << " ";
        queue.pop();
        queue.push(front);
    }
    cout << endl;
}



/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}

