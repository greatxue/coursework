/*
 * File: PriorityQueue.cpp
 * ---------------------------
 * This file contains a unit test of the PriorityQueue class.
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// #include "CSC3002OJActive/assignment5/lib.h" // for OJ test
// #include "CSC3002OJActive/assignment5/priorityqueue.h" // for OJ test

// #include "lib.h" // for local test
// #include "priorityqueue.h" // for local test

using namespace std;

template <typename ValueType>
PriorityQueue<ValueType>::PriorityQueue() {
   clear();
}

/*
 * Implementation notes: ~PriorityQueue destructor
 * -----------------------------------------------
 * All of the dynamic memory is allocated in the Vector class, so no work
 * is required at this level.
 */

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue() {
   /* Empty */
}

template <typename ValueType>
int PriorityQueue<ValueType>::size() const {
   return count;
}

template <typename ValueType>
bool PriorityQueue<ValueType>::isEmpty() const {
   return count == 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear() {
   heap.clear();
   count = 0;
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, double priority) {
   // TODO
}

/*
 * Implementation notes: dequeue, peek, peekPriority
 * -------------------------------------------------
 * These methods must check for an empty queue and report an error if there
 * is no first element.
 */

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue() {
   if (count == 0) error("dequeue: Attempting to dequeue an empty queue");
   //TODO

}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
   if (count == 0) error("peek: Attempting to peek at an empty queue");
   //TODO
}

template <typename ValueType>
double PriorityQueue<ValueType>::peekPriority() const {
   if (count == 0) error("peekPriority: Attempting to peek at an empty queue");
   //TODO
}

template <typename ValueType>
void enqueueHeap(ValueType & value, double priority) {
   //TODO
}

template <typename ValueType>
ValueType dequeueHeap(){
   //TODO
}

template <typename ValueType>
bool PriorityQueue<ValueType>::takesPriority(int i1, int i2) {
   /* Return true if i1 takes the priority */

   //TODO
}

template <typename ValueType>
void PriorityQueue<ValueType>::swapHeapEntries(int i1, int i2) {
   /* Swap elements in the two positions */

   //TODO
}

template <typename ValueType>
std::string PriorityQueue<ValueType>::toString() {
   /* convert the PriorityQueue into a printable String */

   //TODO
}

template <typename ValueType>
std::ostream & operator<<(std::ostream & os,
                          const PriorityQueue<ValueType> & pq) {
   /* give the output of all the elements in queue(not dequeue)
      i.e.: cout << pq gives the output of all the content in current queue without change pq */

   //TODO
}

int main() {
   PriorityQueue<string> pq;
   string value;
   double priority;

   string in_pair;
   while(getline(cin,in_pair)){
      int sp = in_pair.find(' ');
      value = in_pair.substr(0, sp);
      priority = stod(in_pair.substr(sp+1, in_pair.size()));
      pq.enqueue(value, priority);
   }
   cout<<"pq.size() = "<<pq.size()<<endl;
   cout<<"pq.toString() : "<<pq.toString()<<endl;
   int init_len = pq.size();
   for (int i = 0; i<init_len; i++) {
      cout<<"i="<<i<<": pq.peek() = "<<pq.peek()<<endl;
      cout<<"i="<<i<<": pq.dequeue() = "<<pq.dequeue()<<endl;
   }
   cout<<"pq.isEmpty(): "<<boolalpha<<pq.isEmpty()<<endl;
   return 0;
}
