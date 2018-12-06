#ifndef PROJECT4_BINARYSEARCHTREE_H
#define PROJECT4_BINARYSEARCHTREE_H


#include "SiteInfo.h"

class BinarySearchTree {
private:
    struct Node{
        SiteInfo site;
        Node * left;
        Node * right;
    };
    Node * root;
    void add(Node *&, SiteInfo site);
    Node * remove(Node *&, SiteInfo site);
    Node * removeLeftmostNode(Node *& node, SiteInfo&);
    Node * removeNode(Node *& node);
    void print(Node *);
    void destroy(Node *&);
    void get(char *, SiteInfo&, Node *&);
public:
    void retrieve(char * keyword, SiteInfo&);
    void add(SiteInfo site);
    void remove(SiteInfo site);
    void load(char *);
    void print();
    ~BinarySearchTree();
};


#endif //PROJECT4_BINARYSEARCHTREE_H
