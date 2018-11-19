#include <cstdlib>
#include "SiteTable.h"
#include <fstream>
#include <iostream>

const int MAX_LINE_SIZE = 255;

using namespace std;


void SiteTable::load(char * fileName){
    ifstream file;
    file.open(fileName);
    char * line = new char[MAX_LINE_SIZE];
    char **siteInfo = new char*[5];
    char *pch;
    file.getline(line, MAX_LINE_SIZE);
    while(file.getline(line, MAX_LINE_SIZE)){
        for(int i=0; i < 5; i++){
            siteInfo[i] = new char[MAX_LINE_SIZE];
        }
        pch = strtok(line, ",");
        int attrCount = 0;
        char * topic = new char[strlen(pch) + 1];
        strcpy(topic, pch);
        pch = strtok(NULL, ",");
        while(pch != nullptr){
            strcpy(siteInfo[attrCount++], pch);
            pch = strtok(NULL, ",");
        }
        SiteInfo info = SiteInfo(topic, siteInfo);
        add(topic, info);
        delete[] topic;
        for(int i=0; i < 5; i++){
            delete[] siteInfo[i];
        }
    }
    delete[] siteInfo;
    delete[] line;
}

int SiteTable::add(char * topic, const SiteInfo &info) {
    int key = getHashKey(topic);
    int count = 1;
    Node * node = new Node();
//    node->site = new SiteInfo(info);
    node->site = info;
    if (!table[key]) {
        table[key] = node;
    } else {
        Node *current = table[key];
        while (current->next) {
            current = current->next;
            count++;
        }
        current->next = node;
        node->previous = current;
    }
    return count;
}

void SiteTable::remove() {
    for (int i = 0; i < tableSize; i++) {
        Node *node = table[i];
        while(node){  // For each node in the chain
            if(node->site.getRating() == 1){  // if the site has a rating of 1
                Node *nodeToDelete = node;  // assign node to delete to new variable
                if (node->previous) {  // update previous and next variables
                    node->previous->next = node->next;
                }
                if(node->next){
                    node->next->previous = node->previous;
                }
                delete nodeToDelete;
            }
            node = node->next;
        }
    }
}

SiteTable::~SiteTable() {
    for (int i = 0; i < tableSize; i++) {
        Node *node = table[i];
        if(node){
            while (node->next) {
                node = node->next;
                delete node->previous;
            }
            delete node;
        }
    }
    delete[] table;
}

int SiteTable::getHashKey(char *siteName) {
    int *intList = new int[strlen(siteName) + 1];
    convertSite(siteName, intList);
    int sum = 0;
    for (int i = 0; i < strlen(siteName); i++) {
        sum += intList[i];
    }
    delete[] intList;
    return sum % tableSize;
}

int SiteTable::convertChar(char c) {
    int val = ((int) c) - 64;
    if((65 <= c) && (c <= 122)){
        return val;
    } else {
        // Don't include numbers and special characters in calculations
        return 0;
    }
}

void SiteTable::convertSite(char *name, int *intList) {
    for (int i = 0; i < strlen(name); i++) {
        intList[i] = convertChar(name[i]);
    }
}

void SiteTable::retrieve(char *topic, SiteInfo info[], const int &maxMatches) {
    int idx = getHashKey(topic);
    if(table[idx]){
        int copied = 0;
        Node * node = table[idx];
        while(copied < maxMatches && node){
            info[copied++] = node->site;
            node = node->next;
        }
    }
}

void SiteTable::displayAll() {
    for(int i=0; i < tableSize; i++){
        if(table[i]){
            Node * node = table[i];
            while(node){
                SiteInfo info = node->site;
                cout << info << endl;
                node = node->next;
            }
        }
    }
};

void SiteTable::display(char * key){
    int idx = getHashKey(key);
    Node * curr = table[idx];
    while(curr){
        cout << curr->site << endl;
        curr = curr->next;
    }
}
