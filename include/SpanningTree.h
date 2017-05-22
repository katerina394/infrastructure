#ifndef INCLUDE_SPANNINGTREE_H_
#define INCLUDE_SPANNINGTREE_H_
#include <vector>
#include <utility>
#define pair std::pair
#define vector std::vector
vector < vector < pair<int, int> > > CreateGraphAdjacencyList(char filename[]);
void CreateGraphMatrixOfIncidence(char filename[], vector<vector<int>> *gr,
vector<int> *w);
void STKruskal(vector<vector<int>> gr, vector<int> w, vector<vector<int>> *ST,
vector<int> *wST);
vector<vector<pair<int, int>>> STPrim(vector<vector<pair<int, int>>> gr);
void PrintGraphAdjacencyList(vector < vector < pair<int, int> > > gr,
vector < vector < pair<int, int> > > ST, char filename[]);
void PrintGraphMatrixOfIncidence(const vector<vector<int>> &gr, const vector<int> &w,
const vector<vector<int>> &ST, char filename[]);
#endif  // INCLUDE_SPANNINGTREE_H_
