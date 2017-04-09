#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_
#include <set>
#include <vector>
#include <utility>
#define INF 0x3F3F3F3F
std::vector<int> Dijkstra(std::vector < std::vector< std::pair<int, int> > > g,
int start);
/*std::vector < std::vector < std::pair<int, int> > >
CreateGraph(char filename[]);*/

#endif  // INCLUDE_DIJKSTRA_H_
