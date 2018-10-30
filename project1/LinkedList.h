#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H

#include "Node.h"

template<class ItemType>
class LinkedList{
public:
    Node<ItemType> * getHead() const;
    Node<ItemType> * getTail() const;
    void setHead(Node<ItemType>*);
    void setTail(Node<ItemType>*);
    bool add(Node<ItemType>*);
    bool remove(ItemType*);
    ~LinkedList();
private:
    Node<ItemType> * head = nullptr;
    Node<ItemType> * tail = nullptr;
};

template<class ItemType>
bool LinkedList<ItemType>::add(Node<ItemType> *node) {
    Node<ItemType> * current = head;
    if(!current){
        head = node;
        tail = node;
        return true;
    }
    tail->setNext(node);
    node->setPrev(tail);
    tail = node;
    return true;
}
template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    Node<ItemType> * current = head;
    while(current){
        delete current->getPrev();
        current = current->getNext();
    }
    delete current;
}

template<class ItemType>
Node<ItemType> * LinkedList<ItemType>::getHead() const{
    return head;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(ItemType *target) {
    Node<ItemType> * current = head;
    if(current->getItem() == target){
        head = current->getNext();
        return true;
    }
    while(current->getNext()){
        if(current->getNext()->getItem() == target){
            current->setNext(current->getNext()->getNext());
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template<class ItemType>
Node<ItemType> *LinkedList<ItemType>::getTail() const {
    return tail;
}

template<class ItemType>
void LinkedList<ItemType>::setHead(Node<ItemType> *node) {
    head = node;
}

template<class ItemType>
void LinkedList<ItemType>::setTail(Node<ItemType> *node) {
    tail = node;
}

#endif //PROJECT1_LINKEDLIST_H
