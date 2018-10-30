#ifndef PROJECT2_GROUPQUEUE_H
#define PROJECT2_GROUPQUEUE_H

#include "Group.h"

class GroupQueue{
public:
    Group * dequeue();
    void enqueue(const Group&);
    Group * peek();
    void display();
    GroupQueue() {
        tail = nullptr;
    }
    ~GroupQueue(){
        if(tail){
            Node * current = tail->next;
            Node * prev;
            while(current != tail){
                if(!current){
                    break;
                }
                prev = current;
                current = current->next;
                delete prev;
            }
            delete current;
        }
    }
private:
    struct Node{
        Group group;
        Node * next = nullptr;
        Node(const Group & group){
            this->group = group;
            next = nullptr;
        };
        Node(const Group & group, Node * next){
            this->group = group;
            this->next = next;
        };
    };
    Node * tail = nullptr;
};

#endif //PROJECT2_GROUPQUEUE_H
