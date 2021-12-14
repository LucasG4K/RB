#include "tree.hpp"

Tree* Tree::initialize() {
    Tree *tree       = (Tree*)malloc(sizeof(Tree));
    Node *node       = (Node*)malloc(sizeof(Node));
    node->left       = NULL;
    node->right      = NULL;
    node->parent     = NULL;
    node->color      = BLACK;
    node->item.value = 0;
    tree->NIL = node;
    tree->root = tree->NIL;
    return tree;
}

Node* Tree::newNode(Item requestedValue) {
    Node *node   = (Node*)malloc(sizeof(Node));
    node->item   = requestedValue;
    node->left   = NULL;
    node->right  = NULL;
    node->parent = NULL;
    node->color  = RED;
    return node;
}

void Tree::insertValue(Tree *tree, Node *node) {
    Node *y = tree->NIL;
    Node *temp = tree->root;

    while (temp != tree->NIL) {
        y = temp;
        if (node->item.value < temp->item.value)
            temp = temp->left;
        else
            temp = temp->right;
    }
    node->parent = y;

    if (y == tree->NIL)
        tree->root = node;
    else if (node->item.value < y->item.value)
        y->left = node;
    else
        y->right = node;

    node->right = tree->NIL;
    node->left  = tree->NIL;

    insertion_fixup(node, tree);
}

void Tree::insertion_fixup(Node *node, Tree *tree) {
    
    while (node->parent->color == RED) {
        if(node->parent == node->parent->parent->left) { // went left
            if(node->parent->parent->right->color == RED) { // verify right uncle
                node->parent->color = BLACK;
                node->parent->parent->right->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else { // case2 or case3
                if(node == node->parent->right){
                    node = node->parent;
                    leftRotation(node, tree);
                }
                node->parent->color = BLACK; //made parent black
                node->parent->parent->color = RED; //made grandparent red
                rightRotation(node->parent->parent, tree);
            }
        }

        else { // went right
            if (node->parent->parent->left->color == RED) { // verify left uncle
                node->parent->color = BLACK;
                node->parent->parent->left->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->left) {
                    node = node->parent;
                    rightRotation(node, tree);
                }
                node->parent->color = BLACK; //made parent black
                node->parent->parent->color = RED; //made grandparent red
                leftRotation(node->parent->parent, tree);
            }
        }
    }
    tree->root->color = BLACK;
}

void Tree::rightRotation(Node *node, Tree *tree) { 
    Node *temp = node->left;
    node->left = temp->right;
    if (temp->right != tree->NIL)
        temp->right->parent = node;
    
    temp->parent = node->parent;
    
    if (node->parent == tree->NIL)
        tree->root = temp;
    else if (node == node->parent->right)
        node->parent->right = temp;
    else
        node->parent->left = temp;
    
    temp->right  = node;
    node->parent = temp;
}

void Tree::leftRotation(Node *node, Tree *tree) {
    Node *temp = node->right;
    node->right = temp->left;
    if (temp->left != tree->NIL)
        temp->left->parent = node;
    
    temp->parent = node->parent;
    
    if (node->parent == tree->NIL)
        tree->root = temp;
    else if (node == node->parent->left)
        node->parent->left = temp;
    else
        node->parent->right = temp;
    
    temp->left  = node;
    node->parent = temp;
}

void Tree::search(Node **node, Node **temp, Item requestedValue) {
    if (*node == NULL) {
        cout << "[ERROR]: NODE NOT FOUND" << endl;
        return;
    } else if ((*node)->item.value > requestedValue.value) { 
        search(&(*node)->left, temp, requestedValue);
        return;
    } else if ((*node)->item.value < requestedValue.value) {
        search(&(*node)->right, temp, requestedValue);
        return;
    }
    *temp = *node;
}

void Tree::preOrderPrint(Tree *tree, Node *node) {
    if (node != tree->NIL) {
        cout << node->item.value << ":" << node->color << ":" << node->parent->item.value << " ";
        preOrderPrint(tree, node->left);
        preOrderPrint(tree, node->right);
    }
}

void Tree::inOrderPrint(Tree *tree, Node *node) {
    if (node != tree->NIL) {
        inOrderPrint(tree, node->left);
        cout << node->item.value << ":" << node->color << ":" << node->parent->item.value << " ";
        inOrderPrint(tree, node->right);
    }
}

void Tree::postOrderPrint(Tree *tree, Node *node) {
    if (node != tree->NIL) {
        postOrderPrint(tree, node->left);
        postOrderPrint(tree, node->right);
        cout << node->item.value << ":" << node->color << ":" << node->parent->item.value << " ";
    }
}

