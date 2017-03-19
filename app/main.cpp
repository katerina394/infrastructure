#include "find.h"
#include <iostream>
#include <stdio.h>
void print(CNode*root) {
    if (root) {
        print(root->left);
		std::cout<<root->val<<' ';
        print(root->right);
    }
}
int main() {
	int a[] = {2,3,5,7,9};
	CNode *tree = CreateTree(a,5);
	print(tree);
}

