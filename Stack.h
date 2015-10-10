//
//  Stack.h
//  
//
//  Created by Marisa Schmidt on 12/12/14.
//
//

#ifndef ____Stack__
#define ____Stack__

#include <stdio.h>
#include "Nodes.h"
using namespace std;


template <class T>
class Stack {
    
public:
    //operand stack
    //operator stack
    Stack();
    ~Stack();
    T getTop();//return value at top of stack
    void pop(); //pop off the stack
    void push(T); //push on Node with data on to stack
    bool isEmpty();
    
private:
    Node<T> * head;
    Node<T> * nPtr;
    T top;
};


template <class T>
Stack<T>::Stack() {
    head = NULL;
    top = 0;
}

template <class T>
Stack<T>::~Stack() {
    Node<T> *nodeToDelete = head; //nodeToDelete will be used to delete node in the list, which will always be at the head of the list
    Node<T> *t = NULL; //t will point to the node's contents we want to destroy
    
    while (nodeToDelete!=NULL){ //while there are still nodes to delete
        t = nodeToDelete->getNext(); //nodeToDelete points to node after t node.
        nodeToDelete -> setNext(NULL); //t's next pointer no longer points to afterT node, break connection.
        delete nodeToDelete; //delete sPtr and its contents from nodeToDelete.
        nodeToDelete=t; //now node to delete is next node in the list
    }
}

template <class T>
void Stack<T>::push(T c) {
    
    Node<T> *t = head; //temporary pointer so we can traverse list, points to where head points to
    nPtr = new Node<T> (c);
    
    //IF (START OF LIST)
    if (head==NULL) { //if the list is empty (meaning head points to NULL), you are at start of list
        head = nPtr; //head points to where pointer node points to
        //next of ptrNode already set to NULL because of constructor
    }
    //ELSE (MIDDLE OR END OF LIST)
    else { // head != NULL, t points to where head points to, which is where ptrNode points to
        
        //WHILE (NOT AT END OF LIST)
        while (t -> getNext()) { //while t's next is not NULL, keep traversing list, not at end of list!
            t = t -> getNext(); //traverse list
            //t points to where n pointer is pointing to, so can check until a NULL 'next' pointer found
        } //reached end of list, node pointer points to last node, last node found
        
        // the new node being generated will be attached to the end of the list
        t -> setNext(nPtr); // This line enables the new node created to have a next pointer and append node to previous node
        
        // list complete!
        
    }
}

template <class T>
void Stack<T>::pop() {
    
    if (head==NULL) { //no node to delete
        cout << "ERROR: No node to delete, character cannot be popped." << endl;
    }
    else { //nodes to delete

        Node<T> *t = head; //a local pointer to find the node with target name
        Node<T> *prev = NULL; //pointer to keep track of previous node before target node

        //traverse list to find the previous node from the one specified
        while (t->getNext()!=NULL) { //while not at end of list, traverse list!
            prev = t; //move prev to where t is pointing to
            t = t -> getNext(); //traverse
            }
        
        if (prev==NULL) {
            head = NULL;
        }
        else {
        //when have reached end of stack list, set prev's next to NULL
        prev -> setNext(NULL);
        }
        
        delete t;   //destructor! delete t pointer, which means connection to nodeToDelete is gone! t points to nothing
   
    }
    
}


template <class T>
T Stack<T>::getTop() {
    
    Node<T> *t = head;
    
    while(t->getNext()!=NULL) {
        //traverse
        t = t -> getNext();
    }
    
    //now you are at end of list
    top = (t->getData()); //set top to last node's character data
    
    return top;
}

template <class T>
bool Stack<T>::isEmpty() {
    bool empty = true;
    if (head==NULL)
        empty=true;
    else {
        empty=false;
    }
    return empty;
}

#endif
