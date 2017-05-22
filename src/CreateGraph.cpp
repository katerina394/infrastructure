#include <vector>
#include <fstream>
#include <utility>
#define pair std::pair
#define vector std::vector
vector < vector < pair<int, int> > > CreateGraph(char filename[]) {
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
