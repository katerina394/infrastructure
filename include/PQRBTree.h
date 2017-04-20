#ifndef INCLUDE_PQRBTREE_H_
#define INCLUDE_PQRBTREE_H_
#include "RBTree.h"
template <class T>
class PQRBTree {
    RBTree<T> tree;
public:
    rbnode<T>* Find(T key);
    rbnode<T>* Min();
    void Insert(T key);
    void Delete(T key);
    bool empty();
};
template <class T>
rbnode<T>* PQRBTree<T>::Find(T key) {
    return tree.Find(key);
}
template <class T>
rbnode<T>* PQRBTree<T>::Min() {
    return tree.Min();
}
template <class T>
void PQRBTree<T>::Insert(T key) {
    tree.Insert(key);
}
template <class T>
void PQRBTree<T>::Delete(T key) {
    tree.Delete(key);
}
template <class T>
bool PQRBTree<T>::empty() {
    return (tree.GetRoot() == reinterpret_cast<rbnode<T>*>(NIL));
}
#endif  // INCLUDE_PQRBTREE_H_
