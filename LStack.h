//
// Created by Daniel Ferguson on 6/9/2022.
// C3374690 Assessment 2 SENG1120
//


#ifndef SENG1120A2_LSTACK_H
#define SENG1120A2_LSTACK_H


#include "LinkedList.h"

template<typename T>
class LStack {
public:

    //constructor / destructor
    LStack();
    ~LStack();

    //The 4 permitted linkedlist modifiers
    void push(const T& d);
    T pop();
    T& peek();
    bool isEmpty() const;

    //reverse
    void reverse();
    void bottomInsert(const T& d);

    int getSize() const; //returns the size of the stack


private:
    LinkedList<T>* SQ;
    int size;
};

template<typename T>
std::ostream& operator << (std::ostream& out, LStack<T>& LSin);


#include "LStack.hpp"
#endif //SENG1120A2_LSTACK_H
