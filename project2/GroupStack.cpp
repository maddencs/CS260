#include <iostream>
#include "GroupStack.h"
#include <cmath>

GroupStack::GroupStack(int initialStackSize) {
    groupList = new Group*[initialStackSize];
    stackSize = initialStackSize;
}

void GroupStack::push(const Group &group) {
    if(stackCount >= (stackSize - 1)){
        stackSize *= (int)ceil(1.5);  // TODO: Test if this works
        Group ** newGroupList = new Group*[stackSize];
        for(int i=0; i < stackCount; i++){
            newGroupList[i] = groupList[i];
        }
    }
    groupList[stackCount++] = new Group(group);
}

void GroupStack::display() {
    for(int i=0; i<stackCount; i++){
        std::cout << *groupList[i];
    }
}

Group *GroupStack::pop() {
    if(stackCount > 0){
        Group * group = new Group(*groupList[--stackCount]);
        return group;
    }
    return nullptr;
}

Group *GroupStack::peek() {
    if(stackCount > 0){
        return  groupList[stackCount-1];
    }
    return nullptr;
}

GroupStack::~GroupStack() {
    for(int i=0; i <= stackCount; i++){
        delete groupList[i];
    }
    delete[] groupList;
}
