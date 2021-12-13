#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#define RED   true
#define BLACK false
using namespace std;

class Item {
public:
    float value;        
};

class Node {
public:
    Item  item;
    Node *left;
    Node *right;
    Node *parent;
    bool  color;
};

class Tree {
public:
    Node *root;
    Node *NIL;
    Tree *initialize();                                           // root of the tree          obs: to return a Null Ptr from a function, it must be a Ptr function too
    void insertValue(Tree *tree, Node *node);                     // insert some requested int value on tree
    void removeValue(Node **node, Node **f, Item requestedValue); // remove ....  .......  ...  ...  from tree
    void nextChild(Node **node, Node *temp);                      // chose left child to verification and point to the most deeper right branch on the sequence to swap (it could do the opposite)
    void search(Node **node, Node **temp, Item requestedValue);   // search for an exclusive value on the tree
    Node *newNode(Item requestedValue);
    void rightRotation(Node *node, Tree *tree);
    void leftRotation(Node *node, Tree *tree);
    void insertion_fixup(Node *node, Tree *tree);

    void preOrderPrint(Tree *tree, Node *node);                   // print the PreOrder tree
    void inOrderPrint(Tree *tree, Node *node);                    //  ...  ... InOrder   ..
    void postOrderPrint(Tree *tree, Node *node);                  //  ...  ... PostOrder ..
};

#endif