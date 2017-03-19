#include "CreateTree.h"
#include <queue>
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
CNode* CreateTree(int *a, int n) {
    if ( (n < 1) || (a == 0) )
        throw 1;
    for(int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1])
            throw 1;
    std::queue <CNode*> q1;
    std::queue <int> q2, q3;
    CNode *root = new CNode(a[(n-1)/2]);
    q1.push(root);
    q2.push((n-1)/2);
    q3.push(n);
    while (!q1.empty()) {
        CNode* tmp1 = q1.front();
        q1.pop();
        int tmp2 = q2.front();
        q2.pop();
        int tmp3 = q3.front();
        q3.pop();
        if (tmp3 > 2) {
            if (tmp3%4 == 0) {
              q3.push((tmp3-1)/2);
              q2.push(tmp2-tmp3/4);
              tmp1->left = new CNode(a[tmp2-tmp3/4]);
              q1.push(tmp1->left);
              q3.push(tmp3/2);
              q2.push(tmp2+tmp3/4);
              tmp1->right = new CNode(a[tmp2+tmp3/4]);
              q1.push(tmp1->right);
            }
            if (tmp3%4 == 1) {
                q3.push((tmp3-1)/2);
                q2.push(tmp2-tmp3/4-1);
                tmp1->left = new CNode(a[tmp2-tmp3/4-1]);
                q1.push(tmp1->left);
                q3.push(tmp3/2);
                q2.push(tmp2+tmp3/4);
                tmp1->right = new CNode(a[tmp2+tmp3/4]);
                q1.push(tmp1->right);
            }
            if ( (tmp3%4 == 2) || (tmp3%4 == 3) ) {
                q3.push((tmp3-1)/2);
                q2.push(tmp2-tmp3/4-1);
                tmp1->left = new CNode(a[tmp2-tmp3/4-1]);
                q1.push(tmp1->left);
                q3.push(tmp3/2);
                q2.push(tmp2+tmp3/4+1);
                tmp1->right = new CNode(a[tmp2+tmp3/4+1]);
                q1.push(tmp1->right);
            }
        } else {
            if (tmp3 == 2) {
                q3.push(1);
                q2.push(tmp2+1);
                tmp1->right = new CNode(a[tmp2+1]);
                q1.push(tmp1->right);
            } else {
                continue;
            }
        }
    }
    return root;
}
