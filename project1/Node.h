#ifndef PROJECT1_NODE_H
#define PROJECT1_NODE_H

template<class ItemType>
class Node{
private:
    ItemType * item = nullptr;
    Node * next = nullptr;
    Node * prev = nullptr;
public:
    ItemType * getItem() const;
    void setItem(ItemType*);
    Node * getNext() const;
    Node * getPrev() const;
    void setNext(Node<ItemType>*);
    void setPrev(Node<ItemType>*);
    ~Node();
    Node(ItemType*);
};

template<class ItemType>
Node<ItemType>::Node(ItemType * _item) {
    item = _item;
}

template<class ItemType>
Node<ItemType>::~Node() {
    delete item;
}

template<class ItemType>
void Node<ItemType>::setItem(ItemType *item) {
    this->item = item;
}

template<class ItemType>
ItemType * Node<ItemType>::getItem() const {
    return item;
}

template<class ItemType>
Node<ItemType> *Node<ItemType>::getNext() const {
    return this->next;
}

template<class ItemType>
Node<ItemType> *Node<ItemType>::getPrev() const {
    return this->prev;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType> * node) {
    next = node;
}

template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType> *node) {
    prev = node;
}

#endif //PROJECT1_NODE_H
