#include <vector>
#include <utility>
#include "FiveHeap.h"
#include "UnionFind.h"
#define pair std::pair
#define vector std::vector
void STKruskal(vector<vector<int>> gr, vector<int> w, vector<vector<int>> *ST,
vector<int> *wST) {
    FiveHeap<pair<int, int>> h;
    UnionFind uf(gr.size());
    for (int i = 0; i < static_cast<int>(w.size()); ++i)
        h.Insert(pair<int, int>(w[i], i));
    while ( (!h.empty()) && ((*wST).size() < gr.size() - 1) ) {
        pair<int, int> tmp = h.Min();
        h.DeleteMin();
        int x = -1;
        for (int i = 0; i < static_cast<int>(gr.size()); ++i) {
            if ((x != -1) && (gr[i][tmp.second] == 1)) {
                if (uf.Find(x) != uf.Find(i)) {
                    uf.Union(x, i);
                    (*ST)[x][(*wST).size()] = 1;
                    (*ST)[i][(*wST).size()] = 1;
                    (*wST).push_back(tmp.first);
                }
            }
            if (gr[i][tmp.second] == 1) x = i;
            }
    }
    for (int i = 0; i < static_cast<int>(gr.size()); i++)
        if (uf.Find(i) != uf.Find(0))
            throw std::logic_error("graph is disconnected");
}
