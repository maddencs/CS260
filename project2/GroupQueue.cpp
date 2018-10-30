#include <iostream>
#include "GroupQueue.h"

Group *GroupQueue::dequeue() {
    if(tail){
        Node * node = tail->next;  // Get the first node in the queue
        Group *group = new Group(node->group);
        if(node == tail){ // If there's only one item in the queue null the tail
            tail = nullptr;
        } else { // otherwise set the new first item in line as the previous second item in line
            tail->next = node->next;
        }
        delete node;
        return group;
    }
    return nullptr;
}

void GroupQueue::enqueue(const Group &group) {
    if(tail){  // if we're adding an item to the end of the queue update the current tail and make the new node the tail
        tail->next = new Node(group, tail->next); // Set new node to tail's next node and set new node's next node as the start of the list
        tail = tail->next;
    } else { // if this is the first item in the queue set the new node as the tail and the next node as itself
        tail = new Node(group);
        tail->next = tail;  // Point towards self as next node
    }
}

Group *GroupQueue::peek() {
    if(tail){
        if(tail->next){
            return &tail->next->group;
        }
        return &tail->group;
    }
    return nullptr;
}

void GroupQueue::display() {
    if(!tail){
        std::cout << "The queue is empty." << endl;
        return;
    }
    Node * current = tail->next;  // Start at the front of the queue
    int count = 1;  // Start counting the number the Group is in line from 1
    while(current != tail){  // If we've removed all but one item from the queue, then tail->next will point to tail
        if(!current){  // If there's only ever been one item in the queue then current will be null
            break;
        }
        std::cout << "Position: " << count++ << std::endl << current->group << std::endl;
        current = current->next;
    }
    std::cout << "Position: " << count << endl << tail->group << endl;
}
