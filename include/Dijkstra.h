#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_
#include <vector>
#include <utility>
#include <stdlib.h>
#define INF 0x3F3F3F3F
#define vector std::vector
#define pair std::pair
vector<int> DijkstraRBTree(vector < vector<
pair<int, int> > > g, int start);
vector<int> DijkstraFourHeap(vector < vector<
pair<int, int> > > g, int start);
vector < vector < pair<int, int> > >
CreateGraph(char filename[]);
#endif  // INCLUDE_DIJKSTRA_H_
