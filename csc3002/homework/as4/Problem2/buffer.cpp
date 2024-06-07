/* P3:
 * File: p3beffer.cpp
 * -------------------
 * This file implements EditorBuffer
 */
#include <iostream>
//#include "CSC3002OJActive/assignment4/buffer.h"
//#include "CSC3002OJActive/assignment4/SimpleTextEditor.h"
#include "buffer.h"
#include "SimpleTextEditor.h"
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
   Cell *cur = start->next;
   while (cur != start) {
      Cell *next = cur->next;
      delete cur;
      cur = next;
   }

   if (start != NULL) { // check to prevent double delete
      delete start;
}

}

/* TODO PART:
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
   // TODO
   if (cursor->next != start) cursor = cursor->next;
}

void EditorBuffer::moveCursorBackward() {
   // TODO
   if (cursor != start) cursor = cursor->prev;

}

void EditorBuffer::moveCursorToStart() {
   // TODO
   if (cursor != start->next) cursor = start;
}

void EditorBuffer::moveCursorToEnd() {
   // TODO
   if (cursor != start->prev) cursor = start->prev;
}

/* TODO PART:
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {
   // TODO
   Cell *newCell = new Cell;
   newCell->ch = ch; // ch is the member to insert in
   newCell->next = cursor->next; // point the next of newCell at the cursor's next
   newCell->prev = cursor;       // point the prev of newCell at the cursor
   cursor->next->prev = newCell; // point the cursor's next back at newCell
   cursor->next = newCell;       // point the next of cursor at newCell
   cursor = newCell; // recover the cursor pointer
}

void EditorBuffer::deleteCharacter() {
   // TODO
   if (cursor->next != start) {
      Cell *cellToDelete = cursor->next; // cursor's next is the one to delete
      cursor->next = cellToDelete->next; // update the cursor's next
      cellToDelete->next->prev = cursor; // point the new cursor's next back at cursor
      delete cellToDelete; // eliminate the cellToDelete in case of dangling pointer
   }
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
   Cell *crt = start->next;
   string text = "";
   while (crt != start) { // traverse the whole linked list
      text += crt->ch;
      crt = crt->next;
   }
   return text;
}

int EditorBuffer::getCursor() const {
   // TODO
   Cell *crt = start;
   int index = 0;
   while (crt != cursor) {
      index++;
      crt = crt->next;
   }
   return index;
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