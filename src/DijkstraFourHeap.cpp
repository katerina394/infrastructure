#include "PQFHeap.h"
#include "Dijkstra.h"
#include <vector>
#include <utility>
#include <stdexcept>
#define pair std::pair
#define vector std::vector
vector<int> DijkstraFourHeap(vector < vector < pair<int, int> > > g,
    int start) {
    if ( g.empty() || (start < 1) || (start > static_cast<int>(g.size())) )
        throw std::logic_error("incorrect parametrs");
    vector<int> d(g.size(), INF);
    int v;
    d[start-1] = 0;
    PQFHeap< pair<int, int> > pq;
    pq.Insert(pair<int, int>(0, start));
    while (!pq.empty()) {
        pair<int, int> tmp = pq.Min();
        pq.DeleteMin();
        v = tmp.second-1;
        for (int i = 0; i < static_cast<int>(g[v].size()); ++i) {
            if (d[v] + g[v][i].second < d[g[v][i].first-1]) {
                d[g[v][i].first-1] = d[v] + g[v][i].second;
                pq.Insert(pair<int, int>(d[g[v][i].first-1], g[v][i].first));
            }
        }
    }
    return d;
}
