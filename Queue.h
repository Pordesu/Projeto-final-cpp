#ifndef _QUEUE_
#define _QUEUE_
#include "atmega_libs.h"
#include "Node.h"

template <typename T>
class Queue {
    private:
        Node<T>* head;
    
    public: 
        Queue();
        void clear();
        void insert(T dat);
        void remove_first();
};

template <typename T>
Queue<T>::Queue(){
    head = 0;
}

template <typename T>
void Queue<T>::clear(){
    Node<T>* cursor = head;
        while(head) {
            cursor = cursor->getNext();
            delete head;
            head = cursor;
        }
    head = 0;
}

template <typename T>
void Queue<T>::remove_first(){
    Node<T>* cursor = head;
    cursor = cursor -> getNext();
    delete head;
    head = cursor;
}

template <typename T>
void Queue<T>::insert(T dat){
    Node<T>* p = head;
    Node<T>* q = head;

    if (head == 0)
        head = new Node<T>(dat, head);
    else {
        while (q != 0) {
            p = q;
            q = p->getNext();
        }
        p->setNext(new Node<T>(dat,0));
    }
}


#endif