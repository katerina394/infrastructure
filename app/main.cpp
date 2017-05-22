#include <SpanningTree.h>
#include <iostream>
#include <vector>
#include <utility>
#define pair std::pair
#define vector std::vector
int main(char *argv[]) {
    if (*(argv[1]) == '1') {
        vector<vector<int>> gr;
        vector<int> w;
        CreateGraphMatrixOfIncidence(argv[2], &gr, &w);
        vector < vector<int> > res(gr.size(), vector<int>(gr[0].size()));
        vector<int> wres;
        STKruskal(gr, w, &res, &wres);
        PrintGraphMatrixOfIncidence(gr, w, res, argv[3]);
    } else {
        vector < vector < pair<int, int> > > gr = CreateGraphAdjacencyList(argv[2]);
        vector<vector<pair<int, int>>> res = STPrim(gr);
        PrintGraphAdjacencyList(gr, res, argv[3]);
    }
}
