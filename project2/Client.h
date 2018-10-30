#ifndef PROJECT2_CLIENT_H
#define PROJECT2_CLIENT_H

#include <cstring>
#include "Group.h"
#include "GroupQueue.h"
#include "GroupStack.h"

const int DEFAULT_STACK_SIZE = 100;

/***
       Menu Options:
           Add Group to GroupQueue:
                Prompt user for group's contact info,
                                        number of people in the party,
                                        special requirements,
                                        if interested in promotional offers.
            Seat next Group:
                Remove next Group from Restaurant's GroupQueue
            View next Group to be seated:
                Print out next Group in Restaurant's GroupQueue
            Print all Groups in GroupQueue
            Remove most recently added Group from the PromotionGroupStack:
                Will remove the most recently added Group, but also write it to the Restaurant's Group info file
            View the next Group on the PromotionGroupStack
            Print out all of the groups in the PromotionGroupStack
 */
class Client{
public:
    Client(char * restaurantName){
         stack = new GroupStack(DEFAULT_STACK_SIZE);
         queue = new GroupQueue;
         char baseFileName[] = "Promotion Group List - ";
         promotionGroupListFileName = new char[strlen(baseFileName) + strlen(restaurantName) + strlen(".txt") + 1];
         strcat(promotionGroupListFileName, baseFileName);
         strcat(promotionGroupListFileName, restaurantName);
         strcat(promotionGroupListFileName, ".txt");
    }
    ~Client(){
        delete stack;
        delete queue;
        delete[] promotionGroupListFileName;
    }
    void translateInput(char*);
    void printMenu();
private:
    GroupQueue * queue = nullptr;  // Queue of Groups waiting to be seated
    GroupStack * stack = nullptr;  // Stack of Groups interested in promotional offers
    char * promotionGroupListFileName = nullptr; // name of file to store popped Groups in
    void addGroup();
    void seatNextGroup();
    void printNextGroupInQueue();
    void printFullQueue();
    void removeMostRecentGroupFromStack();
    void printNextInStack();
    void printPromotionGroupStack();
    void writeGroupToFile(Group*);
};

#endif //PROJECT2_CLIENT_H
