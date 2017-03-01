#include "find.h"
#include <iostream>
#include <stdio.h>
void print(CNode*root) {
    if (root) {
        print(root->left);
        printf("%15p%6d%25p%26p\n", root, root->val, root->left, root->right);
        print(root->right);
    }
}
int main() {
    CNode *tree = new CNode(5);
    tree->left = new CNode(3);
    tree->right = new CNode(7);
    std::cout << "Address of item " << "Value " << "Address of the left item "
        << "Address of the right item" << std::endl;
    print(tree);
    std::cout  <<  "ElementWithValue3:" << *find(&tree, 3) <<  std::endl;
    std::cout << "Insert item with value 3" << std::endl;
    *find(&tree, 1) = new CNode(1);
    std::cout << "Address of item " << "Value " << "Address of the left item "
        << "Address of the right item" << std::endl;
    print(tree);
}

