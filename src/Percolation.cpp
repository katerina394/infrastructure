#include <time.h>
#include <stdlib.h>
#include <vector>

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
bool Percolation(std::vector<std::vector<int>> m) {
    int mSize = m.size();
    int n = mSize*mSize+2;
    std::vector<int> c(n);
    std::vector<int> d(n, 1);
    for (int i = 0; i < n; ++i)
        c[i] = i;
    for (int i = 0; i < mSize; ++i)
        if (m[0][i]) Union(&c, &d, 0, i+1);
    for (int i = 0; i < mSize-1; ++i) {
        for (int j = 0; j < mSize-1; ++j) {
            if (m[i][j] && m[i][j+1]) Union(&c, &d, i*mSize+j+1,
                i*mSize+j+2);
            if (m[i][j] && m[i+1][j]) Union(&c, &d, i*mSize+j+1,
                (i+1)*mSize+j+1);
        }
        if (m[i][mSize-1] && m[i+1][mSize-1]) Union(&c, &d,
             i*mSize+mSize,
            (i+1)*mSize+mSize);
    }
    for (int j = 0; j < mSize-1; ++j)
        if (m[mSize-1][j] && m[mSize-1][j+1]) Union(&c, &d,
            (mSize-1)*mSize+j+1,
            (mSize-1)*mSize+j+2);
    for (int j = 0; j < mSize; ++j)
        if (m[mSize-1][j]) Union(&c, &d, n-1, (mSize-1)*mSize+j+1);
    if (Find(c, 0) == Find(c, n-1)) {
        return true;
    } else {
        return false;
    }
}
double Probability(int n, int k) {
    int x, y;
    srand(time(NULL));
    double s = 0, j = 0;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (j = 0; !Percolation(m); ++j) {
            x = rand() % n;
            y = rand() % n;
            if (m[x][y] == 1) {
                j--;
                continue;
            }
            m[x][y] = 1;
        }
        s += j / (n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[i][j] = 0;
    }
    return s / k;
}
