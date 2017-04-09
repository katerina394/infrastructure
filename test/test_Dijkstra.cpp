#include <gtest/gtest.h>
#include "Dijkstra.h"
#include <vector>
#include <utility>
#define pair std::pair
#define vector std::vector
TEST(Dijkstra, throws_when_parametrs_are_incorrect) {
    vector < vector < pair<int, int> > > gr1;
    EXPECT_ANY_THROW(vector <int> res = Dijkstra(gr1, 1));
    vector < vector < pair<int, int> > > gr2 = CreateGraph("Graph.txt");
    EXPECT_ANY_THROW(vector <int> res = Dijkstra(gr2, 8));
}
TEST(Dijkstra, work_right_for_graph_with_one_vertex) {
    vector < vector < pair<int, int> > > gr(1);
    vector <int> res = Dijkstra(gr, 1);
    EXPECT_EQ(res[0], 0);
}
TEST(Dijkstra, work_right_for_connected_graph) {
    vector < vector < pair<int, int> > > gr = CreateGraph("Graph.txt");
    vector <int> res = Dijkstra(gr, 1);
    int exp[] = {0, 4, 6, 5, 8, 6, 8};
    for (int i = 0; i < 7; ++i)
        EXPECT_EQ(exp[i], res[i]);
}
TEST(Dijkstra, work_right_for_disconnected_graph) {
    vector < vector < pair<int, int> > > gr(3);
    gr[0].push_back(pair<int, int>(2, 5));
    vector <int> res = Dijkstra(gr, 1);
    EXPECT_EQ(res[0], 0);
    EXPECT_EQ(res[1], 5);
    EXPECT_EQ(res[2], INF);
}