#ifndef INCLUDE_RBNODE_H_
#define INCLUDE_RBNODE_H_
template <class T>
struct rbnode {
    T val;
    rbnode *left, *right, *parent;
    int color;  // BLACK = 0, RED = 1
};
extern rbnode<int> NILnode;
#define NIL &NILnode
#endif  // INCLUDE_RBNODE_H_
