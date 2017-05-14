#include "UnionFind.h"
UnionFind::UnionFind(int n) {
    a = vector<int>(n);
    for (int i = 0; i < n; ++i)
        a[i] = i;
}
int UnionFind::Find(int x) {
    return a[x];
}
void UnionFind::Union(int x, int y) {
    if (Find(x) != Find(y)) {
        int s = Find(x);
        for (int i = 0; i < static_cast<int>(a.size()); ++i)
            if (a[i] == s) a[i] = a[y];
    }
}
