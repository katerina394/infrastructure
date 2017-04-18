#ifndef INCLUDE_4-HEAP_H_
#define INCLUDE_4-HEAP_H_
#include <vector>
#define vector std::vector
template <class T>
class 4-heap {
	vector<T> heap;
	T child(int i);
	T parent(int i);
public:
	4-heap();
	~4-heap();
	T Min();
	void DeleteMin();
	void Insert(T key);
}
template <class T>
T 4-heap<T>::Min() {
	return heap[0];
}
template <class T>
T 4-heap<T>::child(int i) {
	if ( (i > 0) && (4*i+1 < heap.size)) return 4*i+1;
	throw 1;
}
template <class T>
T 4-heap<T>::parent(int i) {
	if ( (i > 0) && (i < heap.size)) return (i-1)/4;
	throw 1;
}
template <class T>
void 4-heap<T>::Insert(T key) {
	heap.push_back(key);
	int tmp = heap.size()-1;
	while ((tmp > 0) && (heap[parent(tmp)] > heap[tmp])) {
		T temp = heap[parent(tmp)];
		heap[parent(tmp)] = heap[tmp];
		heap[tmp] = temp;
		tmp = parent(tmp);
	}
}
template <class T>
void 4-heap<T>::DeleteMin() {
	heap[0] = heap[heap.size()-1];
	heap.pop_back();
    int tmp = 0;
	while (4*tmp+1 < heap.size()) {
		int iofmin = tmp;
		for (int j = 0; (j < 4) && (tmp+j < heap.size()); j++)
			if ( heap[child(tmp) + j] < heap[iofmin]) iofmin = child(tmp) + j;
		if (tmp == iofmin) break;
		T temp = heap[tmp];
		heap[tmp] = heap[iofmin];
		heap[iofmin] = temp;
		tmp = iofmin;
	}
}

#endif  // INCLUDE_4-HEAP_H_