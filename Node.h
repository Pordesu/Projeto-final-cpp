#ifndef _NODE_
#define _NODE_

#include "new_del.h"

template <typename T>
class Node {

    T val;
    Node* next;

  public:
         
    Node(T dat, Node* nxt);
    int getVal();
    Node* getNext();
    void setVal(T dat);
    void setNext(Node* nxt);
};

template <typename T>
Node<T>::Node(T dat, Node<T>* nxt){
       val = dat;
       next = nxt;
}

template <typename T>
int Node<T>::getVal(){
     return val;
}

template <typename T>
Node<T>* Node<T>::getNext(){
     return next;
}

template <typename T>
void Node<T>::setVal(T dat){
     val = dat;
}

template <typename T>
void Node<T>::setNext(Node<T>* nxt){
       next = nxt;
}

#endif