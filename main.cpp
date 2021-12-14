#include "tree.hpp"

void TreeOperations(int *toInsert, int toInsertSize) {
    Tree tree;
    Tree *root = tree.initialize();
    Node *temp;
    Item item;

    cout << "Showing insertion process: " << endl;
    for (int i = 0; i < toInsertSize; i++) {
        item.value = toInsert[i];
        cout << "Inserting the " << i + 1 << "º -> " << item.value << endl;
        tree.insertValue(root, tree.newNode(item));
        cout << endl << "=================" << endl;
    }
    tree.preOrderPrint(root, root->root);
    cout << endl;
    item.value = 99;
    tree.search(&root->root, &temp, item);
    tree.preOrderPrint(root, temp);
}

int main() {
    // 1st tree
    cout << "1st tree" << endl;
    int vector1[] = {77, 77, 56, 38, 11, 21, 24, 99, 51, 88, 93, 110};
    int vectorSize = sizeof(vector1) / sizeof(vector1[0]);

    TreeOperations(vector1, vectorSize);

    return 0;
}

