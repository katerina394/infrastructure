#include <vector>
#include <fstream>
#include <utility>
#define pair std::pair
#define vector std::vector
void PrintGraphAdjacencyList(vector < vector < pair<int, int> > > gr,
vector < vector < pair<int, int> > > ST, char filename[]) {
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
                int f = 0;
                for (int k = 0; k < static_cast<int>(ST[i].size()); ++k)
                    if (ST[i][k].first == gr[i][j].first) f = 1;
                if (f == 1) {
                    file << "edge [color=\"red\"];" << std::endl;
                } else {
                    file << "edge [color=\"black\"];" << std::endl;
                }
                m[i][gr[i][j].first] = 1;
                m[gr[i][j].first][i] = 1;
                file << i << "->" << gr[i][j].first << "[label=\""<<
                gr[i][j].second << "\"]" << std::endl;
            }
    file << "}";
}
void PrintGraphMatrixOfIncidence(const vector<vector<int>> &gr,
const vector<int> &w, const vector<vector<int>> &ST, char filename[]) {
    std::ofstream file;
    file.open(filename);
    file << "digraph MyGraph {" << std::endl << "node [shape=\"circle\", " <<
    "style=\"filled\", fillcolor=\"blue\", fontcolor=\"#FFFFFF\", " <<
    "margin=\"0.01\"];"
        << std::endl << "edge [dir=\"both\"];" << std::endl;
    for (int j = 0; j < static_cast<int>(w.size()); ++j) {
        int x = -1;
        for (int i = 0; i < static_cast<int>(gr.size()); ++i) {
            if ( (x != -1) && (gr[i][j] == 1) ) {
                int f = 0;
                for (int k = 0; k < static_cast<int>(ST[0].size()); ++k)
                    if ((ST[x][k] == ST[i][k]) && (ST[i][k] == 1)) f = 1;
                if (f == 1) {
                    file << "edge [color=\"red\"];" << std::endl;
                } else {
                    file << "edge [color=\"black\"];" << std::endl;
                }
                file << x << "->" << i << "[label=\""<< w[j] << "\"]" <<
                std::endl;
            }
            if (gr[i][j] == 1) x = i;
            }
    }
    file << "}";
}
