//
// Created by Daniel Ferguson on 17/08/2022.
// C3374690 Assessment 2 SENG1120
// Successfully compiled and ran in Ubuntu 22.04 LTS using GCC 11.2.0 with 0 errors + no leaks per Valgrind
//


#ifndef CPLUSPLUS_NODE_H
#define CPLUSPLUS_NODE_H


#include <string>
#include <iostream>


template <typename T>
class Node {

public:

    //constructor / destructor
    Node(const T& dataIn, Node* nextIn = NULL, Node<T>* prevIn = NULL);
    Node();
    ~Node();

    // setters and getters for next and previous nodes
    void set_next(Node* n);
    void set_prev(Node* p);

    Node* get_next() const;
    Node* get_prev() const;
    T& get_data(); // returns the data in the node, needs ostream operator to be used

private:
    Node* prev; // pointer to previous Node in list
    Node* next; // pointer to next Node in list
    T data;

};


#include "Node.hpp"
#endif //CPLUSPLUS_NODE_H
