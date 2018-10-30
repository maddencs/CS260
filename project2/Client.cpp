#include <iostream>
#include <fstream>
#include <cstring>
#include "Client.h"

using namespace std;

const int MAX_INPUT_SIZE = 250;

void Client::translateInput(char *input) {
    switch (atoi(input)){
        case 1:
            addGroup();
            break;
        case 2:
            printFullQueue();
            break;
        case 3:
            seatNextGroup();
            break;
        case 4:
            printNextGroupInQueue();
            break;
        case 5:
            printNextInStack();
            break;
        case 6:
            removeMostRecentGroupFromStack();
            break;
        case 7:
            printPromotionGroupStack();
            break;
        default:
            cout << "That wasn't a valid option." << endl;
            break;
    }
}

void Client::printMenu() {
    cout << "Please choose from one of the following options: " << endl
        << "\t1. Add Group to Waiting List." << endl
        << "\t2. Print Waiting List" << endl
        << "\t3. Seat next group" << endl
        << "\t4. View next person in Waiting List" << endl
        << "\t5. View next person in promotion list" << endl
        << "\t6. Remove most recent person from promotion list" << endl
        << "\t7. Print all users in promotion list" << endl
        << "\tX. Exit" << endl;
}

void Client::addGroup() {
    cout << endl << "Enter group contact name: ";
    char * name = new char[MAX_INPUT_SIZE];
    cin.getline(name, MAX_INPUT_SIZE);

    cout << endl << "Enter group contact email: ";
    char * email = new char[MAX_INPUT_SIZE];
    cin.getline(email, MAX_INPUT_SIZE);
    Group group = Group(name, email);
    delete[] name;
    delete[] email;

    cout << endl << "Is the group interested in promotions?(y/n)" << endl;
    char * input = new char[2];
    cin.getline(input, 2);
    bool promotions = false;
    if(strcmp(input, "y") == 0){
        promotions = true;
    }
    group.setInterestedInPromotions(promotions);
    delete[] input;

    cout << endl << "Are there any special requirements for the group?" << endl;
    char specialRequirements[250];
    cin.getline(specialRequirements, 250);
    group.setSpecialRequirements(specialRequirements);

    cout << endl << "How many people are in the party?" << endl;
    char * groupCount = new char[10];
    cin.getline(groupCount, 10);
    group.setSize(atoi(groupCount));
    delete[] groupCount;

    queue->enqueue(group);
    if(promotions){
        stack->push(group);
    }
}

void Client::seatNextGroup() {
    Group * group = queue->dequeue();
    cout << "Now seating " << *group;
    delete group;
}

void Client::printNextGroupInQueue() {
    Group * group = queue->peek();
    if(group){
        cout << *group << endl;
    } else {
        cout << "There is no one else waiting to be seated." << endl;
    }
}

void Client::printFullQueue() {
    queue->display();
}

void Client::writeGroupToFile(Group * group){
    ofstream file;
    file.open(promotionGroupListFileName, ios::app);
    file << group->getContactName() << ";"
        << group->getContactEmail() << ";"
        << group->getSize() << ";"
        << group->getSpecialRequirements() << endl;
}

void Client::removeMostRecentGroupFromStack() {
    Group * group = stack->pop();
    if(group){
        cout << *group;
        writeGroupToFile(group);
        delete group;
    } else {
        cout << "There are no customers currently interested in promotions." << endl;
    }
}

void Client::printNextInStack() {
    Group * next = stack->peek();
    if(next){
        cout << *next;
    } else {
        cout << "There are no customers currently interested in promotions." << endl;
    }
}

void Client::printPromotionGroupStack() {
    if(stack->peek()){
        stack->display();
    } else {
        cout << "There are no customers currently interested in promotions." << endl;
    }
}
