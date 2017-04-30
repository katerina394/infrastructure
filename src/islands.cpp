#include <stdlib.h>
#include <vector>
#include <queue>
#include "islands.h"
int Find(std::vector<int> a, int v) {
    int tmp = v;
    while (a[tmp] != tmp)
        tmp = a[tmp];
    return tmp;
}
void Union(std::vector<int> *a, std::vector<int> *b, int v1, int v2) {
    if ((*b)[Find(*a, v1)] > (*b)[Find(*a, v2)]) {
        (*a)[Find(*a, v2)] = (*a)[Find(*a, v1)];
        (*b)[Find(*a, v1)]++;
    } else {
        (*a)[Find(*a, v1)] = (*a)[Find(*a, v2)];
        (*b)[Find(*a, v2)]++;
    }
}
std::vector<std::vector<int>> PercolationUF(std::vector<std::vector<int>> m) {
    int mSize = m.size();
    int n = mSize*mSize + 2;
    std::vector<int> c(n);
    std::vector<int> d(n, 1);
    for (int i = 0; i < n; ++i)
        c[i] = i;
    for (int i = 0; i < mSize; ++i)
        if (m[0][i]) Union(&c, &d, 0, i + 1);
    for (int i = 0; i < mSize - 1; ++i) {
        for (int j = 0; j < mSize - 1; ++j) {
            if (m[i][j] && m[i][j + 1]) Union(&c, &d, i*mSize + j + 1,
                i*mSize + j + 2);
            if (m[i][j] && m[i + 1][j]) Union(&c, &d, i*mSize + j + 1,
                (i + 1)*mSize + j + 1);
        }
        if (m[i][mSize - 1] && m[i + 1][mSize - 1]) Union(&c, &d,
            i*mSize + mSize,
            (i + 1)*mSize + mSize);
    }
    for (int j = 0; j < mSize - 1; ++j)
        if (m[mSize - 1][j] && m[mSize - 1][j + 1]) Union(&c, &d,
            (mSize - 1)*mSize + j + 1,
            (mSize - 1)*mSize + j + 2);
    for (int j = 0; j < mSize; ++j)
        if (m[mSize - 1][j]) Union(&c, &d, n - 1, (mSize - 1)*mSize + j + 1);
    c.push_back(n);
    c.push_back(n + 1);
    d.push_back(1);
    d.push_back(1);
    for (int i = 0; i < mSize; ++i)
        if (m[i][0]) Union(&c, &d, n, i*mSize + 1);
    for (int i = 0; i < mSize; ++i)
        if (m[i][mSize-1]) Union(&c, &d, n+1, i*mSize + mSize);
    Union(&c, &d, 0, n - 1);
    Union(&c, &d, 0, n);
    Union(&c, &d, 0, n + 1);
    for (int i = 0; i < mSize - 1; ++i)
        for (int j = 0; j < mSize - 1; ++j)
            if (Find(c, i*mSize + j + 1) != Find(c, 0)) m[i][j] = 0;
    return m;
}
void BFS(std::vector<std::vector<int>> m, std::vector<std::vector<int>> *b,
    index y) {
    index* temp;
    int mSize = m.size();
    std::queue<index> q;
    q.push(y);
    (*b)[y.str][y.stlb] = 1;
    while (!q.empty()) {
        index tmp = q.front();
        q.pop();
        if (tmp.stlb - 1 > -1) {
            if ((m[tmp.str][tmp.stlb - 1] == 1) &&
                ((*b)[tmp.str][tmp.stlb - 1] == 1000)) {
                (*b)[tmp.str][tmp.stlb - 1] = 1;
                temp = new index;
                temp->str = tmp.str;
                temp->stlb = tmp.stlb - 1;
                q.push(*temp);
            }
        }
        if (tmp.str - 1 > -1) {
            if ((m[tmp.str - 1][tmp.stlb] == 1) &&
                ((*b)[tmp.str - 1][tmp.stlb] == 1000)) {
                (*b)[tmp.str - 1][tmp.stlb] = 1;
                temp = new index;
                temp->str = tmp.str - 1;
                temp->stlb = tmp.stlb;
                q.push(*temp);
            }
        }
        if (tmp.stlb + 1 < mSize) {
            if ((m[tmp.str][tmp.stlb + 1] == 1) &&
                ((*b)[tmp.str][tmp.stlb + 1] == 1000)) {
                (*b)[tmp.str][tmp.stlb + 1] = 1;
                temp = new index;
                temp->str = tmp.str;
                temp->stlb = tmp.stlb + 1;
                q.push(*temp);
            }
        }
        if (tmp.str + 1 < mSize) {
            if ((m[tmp.str + 1][tmp.stlb] == 1) &&
                ((*b)[tmp.str + 1][tmp.stlb] == 1000)) {
                (*b)[tmp.str + 1][tmp.stlb] = 1;
                temp = new index;
                temp->str = tmp.str + 1;
                temp->stlb = tmp.stlb;
                q.push(*temp);
            }
        }
    }
}
std::vector<std::vector<int>> PercolationWidth(std::vector<std::vector<int>>
    m) {
    int mSize = m.size();
    std::vector<std::vector<int>> b(mSize, std::vector<int>(mSize, 1000));
    index y;
    y.str = 0;
    for (y.stlb = 0; y.stlb < mSize; ++y.stlb) {
        if (m[y.str][y.stlb] == 1) BFS(m, &b, y);
    }
    y.str = mSize-1;
    for (y.stlb = 0; y.stlb < mSize; ++y.stlb) {
        if (m[y.str][y.stlb] == 1) BFS(m, &b, y);
    }
    y.stlb = 0;
    for (y.str = 0; y.str < mSize; ++y.str) {
        if (m[y.str][y.stlb] == 1) BFS(m, &b, y);
    }
    y.stlb = mSize-1;
    for (y.str = 0; y.str < mSize; ++y.str) {
        if (m[y.str][y.stlb] == 1) BFS(m, &b, y);
    }
    for (int i = 1; i < mSize-1; ++i)
        for (int j = 1; j < mSize-1; ++j)
            if (b[i][j] == 1000) m[i][j] = 0;
    return m;
}
