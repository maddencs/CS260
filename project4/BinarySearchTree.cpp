#include <cstring>
#include <fstream>
#include <iostream>
#include "BinarySearchTree.h"

const int MAX_LINE_SIZE = 255;

void BinarySearchTree::add(Node *& root, SiteInfo site) {
    if(!root){
        root = new Node();
        root->site = site;
        return;
    }
    if(strcmp(root->site.getKeyword(), site.getKeyword()) > 0){
        add(root->left, site);
    } else {
        add(root->right, site);
    }
}


BinarySearchTree::Node *BinarySearchTree::remove(BinarySearchTree::Node *& node, SiteInfo site) {
    if(!node){
        return node;
    }
    int compareVal = strcmp(node->site.getKeyword(), site.getKeyword());
    if(compareVal == 0){
        node = removeNode(node);
    } else if(compareVal < 0){
        node->right = remove(node->right, site);
    } else {
        node->left = remove(node->left, site);
    }
    return node;
}

void BinarySearchTree::add(SiteInfo site) {
    add(root, site);
}

void BinarySearchTree::remove(SiteInfo site) {
    remove(root, site);
}

BinarySearchTree::Node *BinarySearchTree::removeLeftmostNode(Node *&node, SiteInfo &site) {
    if(!node->left){
        site = node->site;
        return removeNode(node);
    } else {
        node->left = removeLeftmostNode(node->left, site);
        return node;
    }
}

BinarySearchTree::Node *BinarySearchTree::removeNode(Node *&node) {
    if(!node->left && !node->right) { // If node is a leaf
        delete node;
        return nullptr;
    }else if(node->left && node->right){ // if node has a left and a right
        SiteInfo site;
        Node * tempPtr = removeLeftmostNode(node->right, site);
        node->right = tempPtr;
        node->site = site;
        return node;
    } else{
        Node * connectNode;
        if(node->left && !node->right){ // if node has a left child but not a right
            connectNode = node->left;
        } else{ // if node has a right child but not a left
            connectNode = node->right;
        }
        delete node;
        return connectNode;
    }
}

void BinarySearchTree::load(char *fileName) {
    ifstream file;
    file.open(fileName);
    char * line = new char[MAX_LINE_SIZE];
    char **siteInfo = new char*[6];
    char *pch;
    file.getline(line, MAX_LINE_SIZE);
    while(file.getline(line, MAX_LINE_SIZE)){
        for(int i=0; i <= 5; i++){
            siteInfo[i] = new char[MAX_LINE_SIZE];
        }
        pch = strtok(line, ",");
        int attrCount = 0;
        while(pch != nullptr){
            strcpy(siteInfo[attrCount++], pch);
            pch = strtok(NULL, ",");
        }
        SiteInfo info = SiteInfo(siteInfo);
        add(info);
        for(int i=0; i <= 5; i++){
            delete[] siteInfo[i];
        }
    }
    delete[] siteInfo;
    delete[] line;
}

void BinarySearchTree::print() {
    print(root);
}

void BinarySearchTree::print(BinarySearchTree::Node *node) {
    if(!node){
        return;
    }
    print(node->left);
    cout << node->site << endl;
    print(node->right);
}

BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

void BinarySearchTree::destroy(BinarySearchTree::Node *&node) {
    if(!node) {
        return;
    }
    destroy(node->left);
    delete node;
    destroy(node->right);
}

void BinarySearchTree::retrieve(char *keyword, SiteInfo &site) {
   get(keyword, site, root);
}

void BinarySearchTree::get(char *keyword, SiteInfo &site, Node *& node) {
    if(!node){
        return;
    }
    int compareVal = strcmp(node->site.getKeyword(), keyword) < 0;
    if(compareVal > 0){
        get(keyword, site, node->right);
    } else if(compareVal == 0){
        site = node->site;
        return;
    } else {
        get(keyword, site, node->left);
    }
}
