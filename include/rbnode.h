#ifndef INCLUDE_RBNODE_H_
#define INCLUDE_RBNODE_H_
template <class T>
struct rbnode {
    T val;
    rbnode* left, right, parent;
    int color;
}
rbnode<int> NILnode = {0, 0, 0, 0, 0};
#define NIL &NILnode
#endif  // INCLUDE_RBNODE_H_