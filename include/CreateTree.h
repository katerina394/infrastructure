#ifndef INCLUDE_CREATETREE_H_
#define INCLUDE_CREATETREE_H_

struct CNode {
    int val;
    CNode *left, *right;
    explicit CNode(int v);
};
CNode** find(CNode**root, int v);
CNode* CreateTree(int *a, int n);
#endif  // INCLUDE_CREATETREE_H_
