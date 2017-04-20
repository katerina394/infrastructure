#ifndef INCLUDE_RBTREE_H_
#define INCLUDE_RBTREE_H_
#include "rbnode.h"
#include <queue>
#include <stack>
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
    rbnode<T>* Min();
    bool IsRBTree();
};
template <class T>
RBTree<T>::RBTree() {
    root = reinterpret_cast<rbnode<T>*>(NIL);
}
template <class T>
RBTree<T>::RBTree(T key) {
    root = new rbnode<T>;
    root->val = key;
    root->color = 0;
    root->left = root->right = reinterpret_cast<rbnode<T>*>(NIL);
    root->parent = 0;
}
template <class T>
RBTree<T>::~RBTree() {
    std::queue<rbnode<T>*> q;
    if (root != reinterpret_cast<rbnode<T>*>(NIL)) q.push(root);
    rbnode<T>* tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp->left != reinterpret_cast<rbnode<T>*>(NIL))
            q.push(tmp->left);
        if (tmp->right != reinterpret_cast<rbnode<T>*>(NIL))
            q.push(tmp->right);
        delete tmp;
    }
}
template <class T>
rbnode<T>* RBTree<T>::GetRoot() {
    return root;
}
template <class T>
void RBTree<T>::RotateLeft(rbnode<T> *x) {
    rbnode<T> *y = x->right;
    x->right = y->left;
    if (y->left != reinterpret_cast<rbnode<T>*>(NIL))
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
    if (y->right != reinterpret_cast<rbnode<T>*>(NIL))
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
    while (tmp != reinterpret_cast<rbnode<T>*>(NIL)) {
        if (tmp->val == v) throw std::logic_error("this key already exist");
        ptmp = tmp;
        if (v < tmp->val) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    x = new rbnode<T>;
    x->parent = ptmp;
    x->left = x->right = reinterpret_cast<rbnode<T>*>(NIL);
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
    while (z != reinterpret_cast<rbnode<T>*>(NIL)) {
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
    if (z == reinterpret_cast<rbnode<T>*>(NIL))
        throw std::logic_error("this key does not exist");
    if ( (z->left == reinterpret_cast<rbnode<T>*>(NIL)) ||
       (z->right == reinterpret_cast<rbnode<T>*>(NIL)) ) {
        y = z;
    } else {
        y = z->right;
        while (y->left != reinterpret_cast<rbnode<T>*>(NIL)) y = y->left;
    }
    if (y->left != reinterpret_cast<rbnode<T>*>(NIL)) {
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
    throw std::logic_error("this key does not exist");
}
template <class T>
rbnode<T>* RBTree<T>::Min() {
    rbnode<T>* tmp = root;
    while (tmp->left != reinterpret_cast<rbnode<T>*>(NIL))
        tmp = tmp->left;
    return tmp;
}
template <class T>
bool RBTree<T>::IsRBTree() {
    std::queue<rbnode<T>*> q;
    if (root->color == 1) return false;
    if (root != reinterpret_cast<rbnode<T>*>(NIL)) {
        q.push(root);
    } else {
        return true;
    }
    rbnode<T>* tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if ((tmp->color == 1) && ((tmp->left->color == 1) ||
            (tmp->right->color == 1))) return false;
        if (tmp->left != reinterpret_cast<rbnode<T>*>(NIL))
            q.push(tmp->left);
        if (tmp->right != reinterpret_cast<rbnode<T>*>(NIL))
            q.push(tmp->right);
    }
    std::stack<rbnode<T>*> s1;
    std::stack<int> s2;
    std::stack<bool> s3;
    int lh, rh;
    s1.push(root);
    s3.push(false);
    while (!s1.empty()) {
        tmp = s1.top();
        if (s3.top() == false) {
            s3.pop();
            s3.push(true);
            if (tmp == NIL) {
                s2.push(1);
                s1.pop();
                s3.pop();
                continue;
            }
            s1.push(tmp->right);
            s3.push(false);
            s1.push(tmp->left);
            s3.push(false);
        } else {
            rh = s2.top();
            s2.pop();
            lh = s2.top();
            s2.pop();
            if (rh != lh) {
                return false;
            } else {
                s1.pop();
                s3.pop();
                if (tmp->color == 0) {
                    s2.push(lh+1);
                } else {
                    s2.push(lh);
                }
            }
        }
    }
    return true;
}
#endif  // INCLUDE_RBTREE_H_
