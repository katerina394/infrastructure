#ifndef INCLUDE_UNIONFIND_H_
#define INCLUDE_UNIONFIND_H_
#include <vector>
#define vector std::vector
class UnionFind {
    vector<int> a;
 public:
     explicit UnionFind(int n);
     void Union(int x, int y);
     int Find(int x);
};
#endif  // INCLUDE_UNIONFIND_H_
