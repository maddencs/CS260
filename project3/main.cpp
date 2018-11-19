#include <iostream>
#include "SiteTable.h"

void printMenu();
void translateInput(char *, SiteTable*);
void displayCategory(SiteTable*);
void getList(SiteTable*);


int main() {
    SiteTable table = SiteTable(101);
    char fileName[] = "sites.csv";
    table.load(fileName);

    char * input = new char[10];
    do{
        printMenu();
        cout << endl;
        cout << "Enter input: ";
        cin.getline(input, 10);
        if(strcmp(input, "X") != 0){
            translateInput(input, &table);
        }
    } while(strcmp(input, "X") != 0);
    delete[] input;
    return 0;
}

void translateInput(char * input, SiteTable *table){
    switch (atoi(input)){
        case 1:
            table->displayAll();
            break;
        case 2:
            table->remove();
            break;
        case 3:
            displayCategory(table);
            break;
        case 4:
            getList(table);
            break;
        default:
            cout << "That wasn't a valid option." << endl;
            break;
    }
}

void printMenu(){
    cout << endl << "Please choose from the following options: " << endl
         << "1. Display All" << endl
         << "2. Delete low rated(1 star) sites" << endl
         << "3. Display by Category" << endl
         << "4. Get list of sites" << endl;
}

void displayCategory(SiteTable *table){
    char * input = new char[20];
    cout << "Enter category: ";
    cin.getline(input, 20);
    table->display(input);
    delete[] input;
}

void getList(SiteTable *table){
    char * input = new char[20];
    const int siteCount = 5;
    cin.clear();
    cout << "Enter category: ";
    cin.getline(input, 20);
    SiteInfo list[siteCount];
    table->retrieve(input, list, siteCount);
    delete[] input;
}
