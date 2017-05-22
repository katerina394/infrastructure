#include <Dijkstra.h>
#include <rbnode.h>
#include <iostream>
#include <vector>
#include <utility>
#define pair std::pair
#define vector std::vector
rbnode<int> NILnode;
int main(int argc, char *argv[]) {
    vector <int> res;
    vector < vector < pair<int, int> > > gr = CreateGraph(argv[1]);
    if (*(argv[2]) == '1') {
        res = DijkstraRBTree(gr, atoi(argv[3]));
    } else {
        res = DijkstraFourHeap(gr, atoi(argv[3]));
    }
    for (int i = 0; i < static_cast<int>(res.size()); ++i)
        std::cout << res[i] << ' ';
}
