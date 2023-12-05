#ifndef _QUEUE_
#define _QUEUE_
#include "Node.h"

template <typename T>
class Queue {  //Classe da fila de eventos
    private:
        Node<T>* head; //Ponteiro para o  primeiro da fila
        Node<T>* tail; //Ponteiro para o  último da fila
        int size;
    public: 
        Queue();
        void clear(); //Limpa a fila
        void insert(T dat); //Insere na fila
        void remove_first(); //Remove o primeiro da fila (mais antigo)
        Node<T>* get_head();
        Node<T>* get_tail();
        unsigned int get_size();
};

template <typename T>
Queue<T>::Queue(){
    head = 0;
    tail = 0;
    size = 0;
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
    tail = 0;
    size = 0;
}

template <typename T>
void Queue<T>::remove_first(){
    Node<T>* cursor = head;
    cursor = cursor->getNext();
    delete head;
    head = cursor;
    if (size > 0){
        size --;
    }
    else{
        size = 0;
    }
}

template <typename T>
void Queue<T>::insert(T dat){
    if (tail == 0){
        head = new Node<T>(dat, head);
        tail = head;
    }
    else{
    tail->setNext(new Node<T>(dat,0));
    tail = tail->getNext();
    size++;
    }
}

template <typename T>
unsigned int Queue<T>::get_size(){
    return size;
}

template <typename T>
Node<T>* Queue<T>::get_head(){
    return head;
}

template <typename T>
Node<T>* Queue<T>::get_tail(){
    return tail;
}

#endif
