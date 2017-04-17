#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_
#include "rbnode.h"
template <class T>
class RBTree {
	rbnode<T>* root;
    void RotateLeft(rbnode<T> *x);
    void RotateRight(rbnode<T> *x);
    void InsertFixup(rbnode<T> *x);
    void DeleteFixup(rbnode<T> *x);
public:
    RBTree();
    RBTree(T key);
    ~RBTree(void);
	rbnode<T>* GetRoot();
    void Insert(T v);
    void Delete(T v);
    rbnode<T>* Find(T v);
};
template <class T>
RBTree<T>::RBTree() {
	root = NIL;
}
template <class T>
RBTree<T>::RBTree(T key) {
    root = new rbnode<T>;
    root->val = key;
    root->color = 0;
    root->left = root->right = NIL;
    root->parent = 0;
}
template <class T>
RBTree<T>::~RBTree() {
    while (root != NIL) 
        Delete(root->val);
}
template <class T>
rbnode<T>* RBTree<T>::GetRoot() {
	return root;
}
template <class T>
void RBTree<T>::RotateLeft(rbnode<T> *x) {
    rbnode<T> *y = x->right;
    x->right = y->left;
    if (y->left != NIL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent != 0) {
        if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
    } else {
        root = y;
    }
    y->left = x;
    x->parent = y;
}
template <class T>
void RBTree<T>::RotateRight(rbnode<T> *x) {
    rbnode<T> *y = x->left;
    x->left = y->right;
    if (y->right != NIL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent != 0) {
        if (x = x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
    } else {
        root = y;
    }
    y->right = x;
    x->parent = y;
}
template <class T>
void RBTree<T>::InsertFixup(rbnode<T> *x) {
    while ( (x != root) && (x->parent->color == 1) ) {
        if (x->parent == x->parent->parent->left) {
            rbnode<T> *y = x->parent->parent->right;
            if (y->color == 1) {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->right) {
                    x = x->parent;
                    RotateLeft(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                RotateRight(x->parent->parent);
            }
        } else {
            rbnode<T> *y = x->parent->parent->left;
            if (y->color == 1) {
                x->parent->color = 0;
                y->color = 0;
                x->parent->parent->color = 1;
                x = x->parent->parent;
            } else {
                if (x == x->parent->left) {
                    x = x->parent;
                    RotateRight(x);
                }
                x->parent->color = 0;
                x->parent->parent->color = 1;
                RotateLeft(x->parent->parent);
            }
        }
    }
    root->color = 0;
}
template <class T>
void RBTree<T>::Insert(T v) {
    rbnode<T> *tmp = root, *ptmp = 0, *x = 0;
    while (tmp != NIL) {
        if (tmp->val == v) throw 1;
        ptmp = tmp;
        if (v < tmp->val) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    x = new rbnode<T>;
    x->parent = ptmp;
    x->left = x->right = NIL;
    x->color = 1;    
    x->val = v;
    if (ptmp != 0) {
        if ( v < ptmp->val) {
            ptmp->left = x;
        } else {
            ptmp->right = x;
        }
    } else {
        root = x;
    }
    InsertFixup(x);
}
template <class T>
void RBTree<T>::DeleteFixup(rbnode<T> *x) {
    while ( (x != root) && (x->color == 0) ) {
        if (x == x->parent->left) {
            rbnode<T> *y = x->parent->right;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                RotateLeft(x->parent);
                y = x->parent->right;
            }
            if ( (y->left->color == 0) && (y->right->color == 0) ) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->right->color == 0) {
                    y->left->color = 0;
                    y->color = 1;
                    RotateRight(y);
                    y = x->parent->right;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->right->color = 0;
                RotateLeft(x->parent);
                x = root;
            }
        } else {
            rbnode<T> *y = x->parent->left;
            if (y->color == 1) {
                y->color = 0;
                x->parent->color = 1;
                RotateRight(x->parent);
                y = x->parent->left;
            }
            if ( (y->right->color == 0) && (y->left->color == 0) ) {
                y->color = 1;
                x = x->parent;
            } else {
                if (y->left->color == 0) {
                    y->right->color = 0;
                    y->color = 1;
                    RotateLeft(y);
                    y = x->parent->left;
                }
                y->color = x->parent->color;
                x->parent->color = 0;
                y->left->color = 0;
                RotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}
template <class T>
void RBTree<T>::Delete(T v) {
    rbnode<T> *x, *y, *z;
    z = root;
    while (z != NIL) {
        if (z->val == v) {
            break;
        } else {
            if (v < z->val) {
                z = z->left;
            } else {
                z = z->right;
            }
        }
    }
    if (z == NIL) throw 1;
    if ( (z->left == NIL) || (z->right == NIL) ) {
        y = z;
    } else {
        y = z->right;
        while (y->left != NIL) y = y->left;
    }
    if (y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }
    x->parent = y->parent;
    if (y->parent != 0) {
        if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
    } else {
        root = x;
    }
    if (y != z) z->val = y->val;
    if (y->color == 0) DeleteFixup(x);
    delete y;
}
template <class T>
rbnode<T>* RBTree<T>::Find(T v) {
    rbnode<T> *tmp = root;
    while (tmp != 0) {
        if (v == tmp->val) {
            return tmp;
        } else {
            if (v < tmp->val) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }    
        }
    }
    throw 1;
}
#endif  // INCLUDE_RBTREE_H_