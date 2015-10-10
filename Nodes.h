
//  Created by Marisa Schmidt on 11/25/14.
//  Nodes.h
//

#ifndef _____D__
#define _____D__

#include <stdio.h>
#include <iostream>
using namespace std;


template <class T>
class Node {
    
public:
    Node ();
    Node( T );
    ~Node();
    Node *getNext();
    T getData(); // essentially Node (fname, lname, mi, ss, age);
    //void setNext(Node* );
    void setNext(Node<T> *);
    //isTop? () makes sure the last node is the top one?
    
private:
    T data;
    Node *next;
};



template <class T>
Node<T>::Node() {
    next = NULL; //default value next
    data = 0; //default value sPtr
}

template <class T>
Node<T>::~Node() {
    delete next;
}

template <class T>
Node<T>::Node( T d ) { //Student *student is parameter of function
    data = d; //sPtr points to where s pointer points to
    next = NULL; //default value next
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next; //where that next pointer is pointing to
}

template <class T>
T Node<T>::getData(){
    return data; //where that sPtr is pointing to
}



/*void Node::setEquation( char *ddptr){
    dPtr = ddptr;
}
 */

template <class T>
void Node<T>::setNext(Node<T> * n) {
    next = n; //set next pointer to where n is pointing to
}






#endif /* defined(_____D__) */
