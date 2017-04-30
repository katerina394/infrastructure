#ifndef INCLUDE_ISLANDS_H_
#define INCLUDE_ISLANDS_H_
#include <vector>
struct index {
    int str;
    int stlb;
};
int Find(std::vector<int> a, int v);
void Union(std::vector<int> *a, std::vector<int> *b, int v1, int v2);
std::vector<std::vector<int>> PercolationUF(std::vector<std::vector<int>> m);
std::vector<std::vector<int>> PercolationWidth(std::vector<std::vector<int>>
m);
#endif  // INCLUDE_ISLANDS_H_
