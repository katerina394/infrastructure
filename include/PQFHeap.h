#ifndef INCLUDE_PQFHEAP_H_
#define INCLUDE_PQFHEAP_H_
#include "FourHeap.h"
template <class T>
class PQFHeap {
    FourHeap<T> h;
 public:
    T Min();
    void DeleteMin();
    void Insert(T key);
    bool empty();
};
template <class T>
T PQFHeap<T>::Min() {
    return h.Min();
}
template <class T>
void PQFHeap<T>::DeleteMin() {
    h.DeleteMin();
}
template <class T>
void PQFHeap<T>::Insert(T key) {
    h.Insert(key);
}
template <class T>
bool PQFHeap<T>::empty() {
    return h.empty();
}
#endif  // INCLUDE_PQFHEAP_H_
