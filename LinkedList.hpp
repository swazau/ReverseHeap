//
// Created by Daniel Ferguson on 22/08/2022.
// C3374690 Assessment 2 SENG1120
//


template<typename T>
LinkedList<T>::LinkedList(){ //constructor for the linkedlist class
    head_ptr = NULL;
    tail_ptr = NULL;
    current_ptr = NULL;
    lst_len = 0;
}

template<typename T>
LinkedList<T>::~LinkedList(){ //destructor for the linkedlist class
    while(head_ptr !=NULL){ // loops while head_ptr isn't NULL
        remove_head(); // calls remove_head for each head that isn't NULL
    }
    tail_ptr=NULL; // after loop is complete assign tail_ptr to NULL
}

template<typename T>
void LinkedList<T>::addToHead(const T& d){ //adds a node to the head of the list
    if(lst_len==0){
        head_ptr = new Node<T>(d);
        tail_ptr = head_ptr;
        lst_len=1;
    }
    else{
        Node<T>* head_insert = new Node<T>(d); //create a new node to insert into the list

        head_ptr->set_prev(head_insert); //sets the previous pointer of the head node to the new node
        head_insert->set_next(head_ptr); //sets the next pointer of the new node to the head node

        head_ptr = head_insert; //sets the head node to the new node
        lst_len++; //increments the length of the list

        head_insert = NULL; //deletes the new node
    }
    current_ptr=head_ptr; //sets the current pointer to the head node
}

template<typename T>
void LinkedList<T>::addToTail(const T& d){ //adds a node to the tail of the list
    if(lst_len==0){
        head_ptr = new Node<T>(d); //create a new node to insert into the list
        tail_ptr=head_ptr; //sets the tail node to the new node
        lst_len=1; //increments the length of the list
    }
    else{
        Node<T>* tail_insert = new Node<T>(d); //create a new node to insert into the list

        tail_ptr->set_next(tail_insert); //sets the next pointer of the tail node to the new node
        tail_insert->set_prev(tail_ptr); //sets the previous pointer of the new node to the tail node

        tail_ptr = tail_insert; //sets the tail node to the new node

        lst_len++; //increments the length of the list
        tail_insert = NULL; //deletes the new node
    }
    current_ptr = tail_ptr; //sets the current node to the tail node
}

template<typename T>
void LinkedList<T>::addToCurrent(const T &d) {



    //if(current_ptr->get_prev() == NULL){ //if the current node has no previous node (if its the head node)
        //addToHead(d);
    //}

    if(current_ptr->get_next() == NULL){ //if the current node has no next node (if its the tail node)
        addToTail(d);
    }

    else{ // all other nodes between the head and the tail nodes

        Node<T>* tmp_next = current_ptr->get_next(); //create a temporary node to hold the next node
        Node<T>* newCurrent; //create a temporary node to hold the new current node

        current_ptr->set_next(newCurrent);
        newCurrent->set_prev(current_ptr);

        newCurrent->set_next(tmp_next);
        tmp_next->set_prev(newCurrent);



        //tmp_next->set_prev(current_ptr); // sets the previous pointer of the next node to the previous node
        //tmp_prev->set_next(current_ptr); // sets the next pointer of the previous node to the next node



        //delete current_ptr; //deletes the current node (mem mgmnt)

        //current_ptr = head_ptr; //sets the current node to the head node

        //tmp_next = NULL; //sets the temporary nodes to null
        //tmp_prev = NULL;

        //lst_len--; //decrements the length of the list

    }





}

template<typename T>
T LinkedList<T>::remove_head(){ //removes the head node from the list
    if(lst_len==0){ //if the list is empty
        return static_cast<T>(NULL); //returns an empty value_type
    }

    else if(lst_len==1){ //if the list has only one node
        T delData = head_ptr->get_data(); //gets the delData from the head node, this delData will be returned
        delete head_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return delData; //returns the delData
    }

    else{ //if the list has more than one node
        T delData = head_ptr->get_data();

        Node<T>* tmp_head_ptr = head_ptr; //create a temporary node to hold the head node

        head_ptr = tmp_head_ptr->get_next(); //sets the head node to the next node
        head_ptr->set_prev(NULL); //sets the previous pointer of the new head node to NULL

        delete tmp_head_ptr;
        lst_len--;

        tmp_head_ptr=NULL; //sets the temporary node to null

        current_ptr=tail_ptr; //sets the current node to the tail node
        return delData;
    }
}

template<typename T>
T LinkedList<T>::remove_tail(){ //removes the tail node from the list
    if(lst_len==0){ //if the list is empty
        return static_cast<T>(NULL); //returns an empty value_type
    }

    else if(lst_len==1){ //if the list has only one node
        T delData = tail_ptr->get_data(); //gets the delData from the tail node, this will be returned
        delete tail_ptr; //deletes the head node (mem mgmnt)
        head_ptr=NULL; //sets the head node to null
        tail_ptr=NULL; //sets the tail node to null
        lst_len--; //decrements the length of the list
        return delData; //returns the data
    }

    else{ //if the list has more than one node
        T delData = tail_ptr->get_data();

        Node<T>* tmp_tail_ptr = tail_ptr; //create a temporary node to hold the tail node

        tail_ptr = tmp_tail_ptr->get_prev(); //sets the tail node to the next node
        tail_ptr->set_next(NULL); //sets the next pointer of the new tail node to null

        delete tmp_tail_ptr; //deletes the temporary node (mem mgmnt)

        lst_len--; //decrements the length of the list
        tmp_tail_ptr=NULL; //sets the temporary node to null


        current_ptr = head_ptr; //sets the current node to the head node
        return delData; //returns the data
    }
}

template<typename T>
T LinkedList<T>::remove_current(){ //removes the current node from the list
    T delData = current_ptr->get_data(); //gets the delData from the current node, this will be returned

    if(current_ptr->get_prev() == NULL){ //if the current node has no previous node (if its the head node)
        remove_head();
    }

    else if(current_ptr->get_next() == NULL){ //if the current node has no next node (if its the tail node)
        remove_tail();
    }

    else{ // all other nodes between the head and the tail nodes

        Node<T>* tmp_next = current_ptr->get_next(); //create a temporary node to hold the next node
        Node<T>* tmp_prev = current_ptr->get_prev(); //create a temporary node to hold the previous node

        tmp_next->set_prev(tmp_prev); // sets the previous pointer of the next node to the previous node
        tmp_prev->set_next(tmp_next); // sets the next pointer of the previous node to the next node

        delete current_ptr; //deletes the current node (mem mgmnt)

        current_ptr = head_ptr; //sets the current node to the head node

        tmp_next = NULL; //sets the temporary nodes to null
        tmp_prev = NULL;

        lst_len--; //decrements the length of the list

    }
    return delData; //returns the data
}


template<typename T>
void LinkedList<T>::remove(const std::string& nameDel) { // searches the list for a node with the same name as the parameter and removes it
    int numOfNodes = count(nameDel); //counts the number of nodes with the same name as the parameter

    for(int i =0;i<numOfNodes;i++){ //loops through the linkedlist the number of times the node name is found
        move_to_head(); //moves the current node to the head node
        while (current_ptr->get_data().get_name() != nameDel ){ //loops until the current node has the same name as the parameter
            current_ptr = current_ptr->get_next();
        }
        if(current_ptr->get_data().get_name() == nameDel){ // if the node name equals the parameter
            remove_current(); //removes the current node
        }
    }
}


template<typename T>
void LinkedList<T>::move_to_head(){ //moves the current node to the head node
    current_ptr = head_ptr;
}

template<typename T>
void LinkedList<T>::move_to_tail(){ //moves the current node to the tail node
    current_ptr = tail_ptr;
}

template<typename T>
void LinkedList<T>::forward(){ //moves the current node forward one node
    if(current_ptr->get_next() != NULL){
        current_ptr = current_ptr->get_next();
    }
}

template<typename T>
void LinkedList<T>::backward(){ //moves the current node to the previous node
    if(current_ptr->get_prev() !=NULL){
        current_ptr = current_ptr->get_prev();
    }
}

template<typename T>
T& LinkedList<T>::get_current()const { //returns the current node's data
    return current_ptr->get_data();
}

template<typename T>
T& LinkedList<T>::get_head() const{ //returns the current node's data
    return head_ptr->get_data();
}

template<typename T>
T& LinkedList<T>::get_tail() const{ //returns the current node's data
    return tail_ptr->get_data();
}

template<typename T>
int LinkedList<T>::size() const{ //returns the number of nodes in the linkedlist
    return lst_len;
}

template<typename T>
double LinkedList<T>::calcAverage(){ //calculates the average age of all students in the linkedlist
    move_to_head();
    double tmp_score = 0;
    for(int i=0;i<lst_len;i++){ //loops through the linkedlist
        tmp_score += current_ptr->get_data().get_score(); //adds the score of the current node to the temporary score
        forward();
    }
    tmp_score/=lst_len; //divides the temporary score by the number of nodes in the linkedlist
    return  tmp_score;
}

template<typename T>
int LinkedList<T>::count(const std::string& nameNum){ //counts the number of times a name appears in the list
    Node<T>* tmp_ptr = head_ptr;
    int tmp_cnt = 0;
    while(tmp_ptr != NULL){ //while the temporary node is not null
        if(tmp_ptr->get_data().get_name() == nameNum){ //if the name of the temporary node is the same as the name we are searching for
            tmp_cnt++;
        }
        tmp_ptr=tmp_ptr->get_next();
    }
    return  tmp_cnt;
}

template<typename T>
void LinkedList<T>::nodeDataReturn(std::ostream &out) const { //returns the data contained inside the node to the ostream
    Node<T>* tmp_ptr = head_ptr; //create a temporary node to point to the head node
    while(tmp_ptr!=NULL){ //loops until the temporary node is null
        out<<tmp_ptr->get_data()<<" ";
        tmp_ptr = tmp_ptr->get_next();
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll){ //overloaded << operator, allows linklist to be printed with <<
    ll.nodeDataReturn(out); //calls the nodeDataReturn function to return the data of the nodes
    return out;
}

template<typename T>
void LinkedList<T>::operator+=(LinkedList<T>& ll_2) { //concats the data from the second list to the first list
    ll_2.move_to_head(); //moves the second list to the head postion
    T temp; //creates a temp valuetype (student) to hold the second list data.]
    for(int i=0;i<ll_2.size();i++){ //loops until the second list is empty
        temp = ll_2.get_current(); //sets the temp valuetype to the second list data
        addToTail(temp); //adds the temp valuetype to the first list
        ll_2.forward(); //moves the second list forward
    }
}

template<typename T>
void LinkedList<T>::operator==(LinkedList<T> &ll_2) {

}
