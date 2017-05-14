#include <vector>
#include <fstream>
#include <utility>
#define pair std::pair
#define vector std::vector
void PrintGraphAdjacencyList(vector < vector < pair<int, int> > > gr,
char filename[]) {
    std::ofstream file;
    file.open(filename);
    vector<vector<bool>> m(gr.size(), vector<bool>(gr.size(), 0));
    file << "digraph MyGraph {" << std::endl <<
    "node [shape=\"circle\", style=\"filled\", fillcolor=\"blue\", " <<
    "fontcolor=\"#FFFFFF\", margin=\"0.01\"];"
        << std::endl << "edge [dir=\"both\"];" << std::endl;
    for (int i = 0; i < static_cast<int>(gr.size()); ++i)
        for (int j = 0; j < static_cast<int>(gr[i].size()); ++j)
            if (m[i][gr[i][j].first] == 0) {
                m[i][gr[i][j].first] = 1;
                m[gr[i][j].first][i] = 1;
                file << i << "->" << gr[i][j].first << "[label=\""<<
                gr[i][j].second << "\"]" << std::endl;
            }
    file << "}";
}
void PrintGraphMatrixOfIncidence(const vector<vector<int>> &gr,
const vector<int> &w, char filename[]) {
    std::ofstream file;
    file.open(filename);
    file << "digraph MyGraph {" << std::endl << "node [shape=\"circle\", " <<
    "style=\"filled\", fillcolor=\"blue\", fontcolor=\"#FFFFFF\", " <<
    "margin=\"0.01\"];"
        << std::endl << "edge [dir=\"both\"];" << std::endl;
    for (int j = 0; j < static_cast<int>(w.size()); ++j) {
        int x = -1;
        for (int i = 0; i < static_cast<int>(gr.size()); ++i) {
            if ((x != -1) && (gr[i][j] == 1))
                file << x << "->" << i << "[label=\""<< w[j] << "\"]" <<
                std::endl;
            if (gr[i][j] == 1) x = i;
            }
    }
    file << "}";
}
