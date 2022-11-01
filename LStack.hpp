//
// Created by Daniel Ferguson on 6/9/2022.
// C3374690 Assessment 2 SENG1120
//


#include "LStack.h"

template<typename T>
LStack<T>::LStack() {SQ = new LinkedList<T>(); size=0;} //constructor

template<typename T>
LStack<T>::~LStack() {delete SQ;} //destructor

template<typename T>
void LStack<T>::push(const T& d) {SQ->addToTail(d); size++;} //adds to the tail of the linkedlist

template<typename T>
T LStack<T>::pop(){ //removes from the tail of the linkedlist and returns the data removed
    if(isEmpty()) {throw std::out_of_range("Stack is empty");}
    size--;
    return SQ->remove_tail(); //returns the data removed
}

template<typename T>
bool LStack<T>::isEmpty() const { //checks if the stack is empty
    if(size == 0) {return true;}
    else {return false;} //returns true if empty, false if not
}

template<typename T>
T& LStack<T>::peek(){ //returns the tail of the stack without taking it off the stack
    if(isEmpty()) {throw std::out_of_range("Stack is empty");} //if the stack is empty throw an error
    SQ->move_to_tail();
    return SQ->get_current(); //returns the tail of the stack
}

template<typename T>
int LStack<T>::getSize() const {return size;}

template<typename T> // puts the stack in reverse order
void LStack<T>::reverse() {
    if (size > 1) { // if the stack is bigger than 1
        T temp = pop(); // pop the top of the stack
        reverse(); // reverse the stack
        bottomInsert(temp); // insert the popped value to the bottom of the stack
    }
}

template<typename T>
void LStack<T>::bottomInsert(const T& d) { // inserts a node at the bottom of the stack
    if(isEmpty()) {push(d);} // if the stack is empty, push the node to the stack
    else {
        T temp = pop(); // removes the top node from the stack
        bottomInsert(d); // recursively calls the function until the stack is empty
        push(temp); // pushes the removed node back onto the stack
    }
}


template<typename T>
std::ostream& operator << (std::ostream& out, LStack<T>& LSin){ //outputs all the nodes in the stack
    LStack<T> tempStack; //creates a temporary stack
    int LS_curSize = LSin.getSize(); //gets the size of the stack

    // this for loop removes all nodes from the main stack, outputs them to iostream, and adds them to the temp stack
    for(int i=0;i<LS_curSize;i++){ //loops for the length of the stack
        out << LSin.peek()<<" "; //outputs the head of the stack
        tempStack.push(LSin.pop()); //adds the head of the stack to the temp stack
    }

    //this for loop adds all the nodes back into the main stack
    int tempSize = tempStack.getSize(); //gets the size of the temp stack
    for(int i=0;i<tempSize;i++){ //loops for the length of the temp stack
        LSin.push(tempStack.pop()); //adds the head of the temp stack back to the main stack
    }
    return out; //returns the output stream
}

