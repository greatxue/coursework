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

#include "lib.h" // for local test
#include "priorityqueue.h" // for local test

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
    //TODO
    heap.push_back({value, priority, enqueueCount++});
    count++;
    int index = count - 1;

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (takesPriority(parent, index)) {
            break;
        }
        swapHeapEntries(parent, index);
        index = parent;
    }
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
    ValueType value = heap[0].value;
    swapHeapEntries(0, count - 1);
    count--;
    int index = 0;
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left >= count) {
            break;
        }
        int child = left;
        if (right < count && takesPriority(right, left)) {
            child = right;
        }
        if (takesPriority(index, child)) {
            break;
        }
        swapHeapEntries(index, child);
        index = child;
    }

    return value;

}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek() const {
   if (count == 0) error("peek: Attempting to peek at an empty queue");
   //TODO
    return heap[0].value;
}

template <typename ValueType>
double PriorityQueue<ValueType>::peekPriority() const {
   if (count == 0) error("peekPriority: Attempting to peek at an empty queue");
   //TODO
    return heap[0].priority;
}

template <typename ValueType>
void PriorityQueue<ValueType>::enqueueHeap(ValueType & value, double priority) {
   //TODO

}


template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeueHeap() {
    //TODO
}



template <typename ValueType>
bool PriorityQueue<ValueType>::takesPriority(int i1, int i2) {
   /* Return true if i1 takes the priority */
   //TODO
    if (heap[i1].priority < heap[i2].priority) return true;
    if (heap[i1].priority > heap[i2].priority) return false;
    return heap[i1].sequence < heap[i2].sequence;
}

template <typename ValueType>
void PriorityQueue<ValueType>::swapHeapEntries(int i1, int i2) {
   /* Swap elements in the two positions */
   //TODO
    HeapEntry entry = heap[i1];
    heap[i1] = heap[i2];
    heap[i2] = entry;
}

template <typename ValueType>
std::string PriorityQueue<ValueType>::toString() {
   /* convert the PriorityQueue into a printable String */
   //TODO
    string queueStr = "{";
    for (int i = 0; i < count - 1; i++) {
        queueStr += to_string(int(heap[i].priority)) + ":\"" + heap[i].value + "\", ";
    }
    queueStr += to_string(int(heap[count - 1].priority)) + ":\"" + heap[count - 1].value + "\"}";
    return queueStr;
}

template <typename ValueType>
std::ostream & operator<<(std::ostream & os,
                          const PriorityQueue<ValueType> & pq) {
   /* give the output of all the elements in queue(not dequeue)
      i.e.: cout << pq gives the output of all the content in current queue without change pq */

   //TODO
   os << pq.toString();
   return os;
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
