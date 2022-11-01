//
// Created by Daniel Ferguson on 22/08/2022.
// C3374690 Assessment 2 SENG1120
//


#ifndef CPLUSPLUS_LINKEDLIST_H
#define CPLUSPLUS_LINKEDLIST_H


#include "Node.h"
#include <string>
#include <ostream>

template <typename T>
class LinkedList {

public:

    //constructor / destructor
    LinkedList();
    ~LinkedList();

    //add to linkedlist
    void addToHead(const T& d);
    void addToTail(const T& d);
    void addToCurrent(const T& d);

    //remove from linkedlist
    T remove_head();
    T remove_tail();
    T remove_current();

    //current pointer modifers
    void move_to_head();
    void move_to_tail();

    void forward();
    void backward();

    T& get_current() const;
    T& get_head() const;
    T& get_tail() const;

    int size() const; //size of the linkedlist

    void remove(const std::string& nameDel);

    double calcAverage();
    int count(const std::string& nameNum);

    void nodeDataReturn(std::ostream& out) const; //used by ostream operator
    void operator+=(LinkedList<T>& ll_2); // overloads += to concat two linkedlists together

    void operator == (LinkedList<T>& ll_2);

private:
    //pointers
    Node<T>* head_ptr;
    Node<T>* tail_ptr;
    Node<T>* current_ptr;

    int lst_len; //linkedlist number of nodes
};

template<typename T>
std::ostream& operator <<(std::ostream& out, const LinkedList<T>& ll); //overloads the ostream << operator

#include "LinkedList.hpp"
#endif //CPLUSPLUS_LINKEDLIST_H
