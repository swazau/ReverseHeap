//
// Created by Daniel Ferguson on 17/08/2022.
// C3374690 Assessment 2 SENG1120
//


template<typename T>
//setters and getter implementation for next and previous nodes
void Node<T>::set_next(Node* n){next = n;}

template<typename T>
void Node<T>::set_prev(Node* p){prev = p;}

template<typename T>
Node<T>* Node<T>::get_next() const{return next;}

template<typename T>
Node<T>* Node<T>::get_prev() const{return prev;}

template<typename T>
T& Node<T>::get_data(){return data;} // returns the data in the node, needs ostream operator to be used

template<typename T>
Node<T>::Node(const T& dataIn, Node *nextIn, Node *prevIn) { //constructor for the node class, takes in the data and next and previous nodes
    data = dataIn;
    next = nextIn;
    prev = prevIn;
}

template<typename T>
Node<T>::Node() { //constructor for the node class
    next = NULL;
    prev = NULL;
}

template<typename T>
Node<T>::~Node(){}

//template<typename T>
//std::ostream& operator <<(std::ostream& out, const T& gay){
    //out <<"Name: "<< gay.get_name() << ", balance: " << gay.balance()<<std::endl;
    //return out;
//}






