#include "Dijkstra.h"
#include <set>
#include <vector>
#include <fstream>
#include <utility>
#define pair std::pair
#define vector std::vector
vector<int> Dijkstra(vector < vector < pair<int, int> > > g, int start) {
    if ( g.empty() || (start < 1) || (start > g.size()) ) throw 1;
    vector<int> d(g.size(), INF);
    int v;
    d[start-1] = 0;
    std::set< pair<int, int> > s;
    s.insert(pair<int, int>(0, start));
    while (!s.empty()) {
        pair<int, int> tmp = *s.begin();
        s.erase(s.begin());
        v = tmp.second-1;
        for (int i = 0; i < g[v].size(); ++i) {
            if (d[v] + g[v][i].second < d[g[v][i].first-1]) {
                if (d[g[v][i].first-1] != INF)
                    s.erase(s.find(pair<int, int>(d[g[v][i].first-1],
                    g[v][i].first)));
                d[g[v][i].first-1] = d[v] + g[v][i].second;
                s.insert(pair<int, int>(d[g[v][i].first-1], g[v][i].first));
            }
        }
    }
    return d;
}
/*vector < vector < pair<int, int> > > CreateGraph(char filename[]) {
    std::ifstream file(filename);
    int N, n;
    file >> N;
    vector < vector < pair<int, int> > > g(N);
    for (int i = 0; i < N; ++i) {
        file >> n;
        g[i] = vector< pair<int, int>>(n);
        for (int j = 0; j < n; ++j) {
            file >> g[i][j].first >> g[i][j].second;
        }
    }
    return g;
}
*/