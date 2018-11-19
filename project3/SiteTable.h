#ifndef PROJECT3_SITETABLE_H
#define PROJECT3_SITETABLE_H

#include "SiteInfo.h"
#include <cstring>

class SiteTable{
private:
    int tableSize = 101;
    int limit = 10;
    struct Node{
        SiteInfo site;
        Node * previous = nullptr;
        Node * next = nullptr;
    };
    Node ** table;
    int getHashKey(char*);
    int convertChar(char);
    void convertSite(char*, int*);
public:
    SiteTable(){
        table = new Node*[tableSize];
    };
    SiteTable(int tableSize){
        this->tableSize = tableSize;
        table = new Node*[tableSize];
    }
    int add(char*, const SiteInfo&);
    void remove();
    void retrieve(char *, SiteInfo[], const int & maxMatches);
    void load(char*);
    void displayAll();
    void display(char*);
    ~SiteTable();

};

#endif //PROJECT3_SITETABLE_H
