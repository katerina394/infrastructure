#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <utility>
int main() {
    std::vector < std::vector < std::pair<int, int> > > gr = CreateGraph("Graph.txt");
    for (int i = 0; i < gr.size(); ++i) {
        for (int j = 0; j < gr[i].size(); ++j)
            std::cout << '(' << gr[i][j].first << ',' << gr[i][j].second << ')'
            << ' ';
        std::cout << std::endl;
    }
}
