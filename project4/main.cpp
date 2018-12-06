#include <iostream>
#include <cstring>
#include "BinarySearchTree.h"

void printMenu();
void translateInput(char *, BinarySearchTree*);
void getByKeyword(BinarySearchTree *tree);
void deleteByKeyword(BinarySearchTree *tree);


int main() {
    BinarySearchTree tree = BinarySearchTree();
    char fileName[] = "sites.csv";
    tree.load(fileName);

    char * input = new char[10];
    do{
        printMenu();
        cout << endl;
        cout << "Enter input: ";
        cin.getline(input, 10);
        if(strcmp(input, "X") != 0){
            translateInput(input, &tree);
        }
    } while(strcmp(input, "X") != 0);
    delete[] input;

    return 0;
}

void translateInput(char * input, BinarySearchTree *tree){
    switch (atoi(input)){
        case 1:
            tree->print();
            break;
        case 2:
            getByKeyword(tree);
            break;
        case 3:
            deleteByKeyword(tree);
            break;
        case 4:
//            getList(table);
            break;
        default:
            cout << "That wasn't a valid option." << endl;
            break;
    }
}

void printMenu(){
    cout << endl << "Please choose from the following options: " << endl
         << "1. Display All" << endl
         << "2. Retrieve by keyword" << endl
         << "3. Delete by Category" << endl;
}

void getByKeyword(BinarySearchTree *tree){
    char * input = new char[20];
    cin.clear();
    cout << "Enter keyword: ";
    cin.getline(input, 20);
    SiteInfo site;
    tree->retrieve(input, site);
    delete[] input;
    cout << "Site Retrieved:\n" << site << endl;
}

void deleteByKeyword(BinarySearchTree *tree){
    char * input = new char[20];
    cin.clear();
    cout << "Enter keyword: ";
    cin.getline(input, 20);
    SiteInfo site;
    tree->retrieve(input, site);
    delete[] input;
    tree->remove(site);
}
