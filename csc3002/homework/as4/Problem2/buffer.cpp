/* P3:
 * File: p3beffer.cpp
 * -------------------
 * This file implements EditorBuffer
 */
#include <iostream>
//#include "CSC3002OJActive/assignment4/buffer.h"
//#include "CSC3002OJActive/assignment4/SimpleTextEditor.h"
//#include "buffer.h"
//#include "SimpleTextEditor.h"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/* TODO PART:
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer() {
   // TODO

}

/* TODO PART:
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
   // TODO
}

void EditorBuffer::moveCursorBackward() {
   // TODO

}

void EditorBuffer::moveCursorToStart() {
   // TODO
}

void EditorBuffer::moveCursorToEnd() {
   // TODO
}

/* TODO PART:
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {
   // TODO
}

void EditorBuffer::deleteCharacter() {
   // TODO
   
}

/* TODO PART:
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const {
   // TODO
}

int EditorBuffer::getCursor() const {
   // TODO

}

/* DO NOT modify the main() part */
int main(){
    string cmd;
    EditorBuffer buffer;
    while(getline(cin,cmd)){
        executeCommand(buffer, cmd);
    }        
    return 0;
}