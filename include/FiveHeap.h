#ifndef INCLUDE_FIVEHEAP_H_
#define INCLUDE_FIVEHEAP_H_
#include <vector>
#include <stdexcept>
#define vector std::vector
template <class T>
class FiveHeap {
    vector<T> heap;
    int child(int i);
    int parent(int i);
 public:
    T Min();
    void DeleteMin();
    void Insert(T key);
    bool empty();
};
template <class T>
T FiveHeap<T>::Min() {
    return heap[0];
}
template <class T>
int FiveHeap<T>::child(int i) {
    if ( (i >= 0) && (5*i+1 < static_cast<int>(heap.size()))) return 5*i+1;
    throw std::logic_error("incorrect index");
}
template <class T>
int FiveHeap<T>::parent(int i) {
    if ( (i > 0) && (i < static_cast<int>(heap.size()))) return (i-1)/5;
    throw std::logic_error("incorrect index");
}
template <class T>
void FiveHeap<T>::Insert(T key) {
    heap.push_back(key);
    int tmp = static_cast<int>(heap.size())-1;
    while ((tmp > 0) && (heap[parent(tmp)] > heap[tmp])) {
        T temp = heap[parent(tmp)];
        heap[parent(tmp)] = heap[tmp];
        heap[tmp] = temp;
        tmp = parent(tmp);
    }
}
template <class T>
void FiveHeap<T>::DeleteMin() {
    heap[0] = heap[static_cast<int>(heap.size())-1];
    heap.pop_back();
    int tmp = 0;
    while (5*tmp+1 < static_cast<int>(heap.size())) {
        int iofmin = tmp;
        for (int j = 0; (j < 5) && (child(tmp)+j <
            static_cast<int>(heap.size())); j++)
            if ( heap[child(tmp) + j] < heap[iofmin]) iofmin = child(tmp) + j;
        if (tmp == iofmin) break;
        T temp = heap[tmp];
        heap[tmp] = heap[iofmin];
        heap[iofmin] = temp;
        tmp = iofmin;
    }
}
template <class T>
bool FiveHeap<T>::empty() {
    return heap.empty();
}
#endif  // INCLUDE_FIVEHEAP_H_
