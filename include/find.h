#ifndef INCLUDE_FIND_H_
#define INCLUDE_FIND_H_

struct CNode {
    int val;
    CNode *left, *right;
    explicit CNode(int v);
};
CNode** find(CNode**root, int v);
#endif  // INCLUDE_FIND_H_
