#include "find.h"

CNode::CNode(int v) {
    val = v;
    left = right = 0;
}
CNode** find(CNode**root, int v) {
    while (*root) {
        if ((*root)->val == v) {
            return root;
        } else {
            if ((*root)->val < v) {
                root = &((*root)->right);
            } else {
                root = &((*root)->left);
            }
        }
    }
    return root;
}
