#ifndef INCLUDE_PERCOLATION_H_
#define INCLUDE_PERCOLATION_H_
#include <vector>
int Find(std::vector<int> a, int v);
void Union(std::vector<int> *a, std::vector<int> *b, int v1, int v2);
bool Percolation(std::vector<std::vector<int>> m);
double Probability(int n, int k);
#endif  // INCLUDE_PERCOLATION_H_
