#include <vector>
#include <fstream>
#include <utility>
#define pair std::pair
#define vector std::vector
vector < vector < pair<int, int> > > CreateGraphAdjacencyList(char filename[]) {
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
void CreateGraphMatrixOfIncidence(char filename[], vector<vector<int>> *gr,
vector<int> *w) {
    std::ifstream file(filename);
    int n, m;
    file >> n >> m;
    (*gr) = vector<vector<int>>(n, vector<int>(m));
    (*w) = vector<int>(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            file >> (*gr)[i][j];
    for (int j = 0; j < m; ++j)
        file >> (*w)[j];
}
