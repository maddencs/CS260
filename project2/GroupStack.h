#ifndef PROJECT2_GROUPSTACK_H
#define PROJECT2_GROUPSTACK_H

#include "Group.h"

class GroupStack{
public:
    void push(const Group &);
    void display();
    Group * pop();
    Group * peek();
    GroupStack(int);
    ~GroupStack();
private:
    Group ** groupList;
    int stackSize;
    int stackCount = 0;
};

#endif //PROJECT2_GROUPSTACK_H
