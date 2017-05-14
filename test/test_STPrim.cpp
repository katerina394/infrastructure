#include <gtest/gtest.h>
#include "SpanningTree.h"
TEST(STPrim, work_right_for_graph_with_one_vertex) {
    vector < vector < pair<int, int> > > gr(1);
    vector < vector < pair<int, int> > > res = STPrim(gr);
    EXPECT_EQ(static_cast<int>(res.size()), 1);
    EXPECT_EQ(static_cast<int>(res[0].size()), 0);
}
TEST(STPrim, work_right_for_graph_which_equel_his_spanning_tree) {
    vector < vector < pair<int, int> > > gr(3);
    gr[0] = vector<pair<int, int>>(1, pair<int, int>(1, 1));
    gr[1] = vector<pair<int, int>>(2);
    gr[1][0] = pair<int, int>(0, 1);
    gr[1][1] = pair<int, int>(2, 3);
    gr[2] = vector<pair<int, int>>(1, pair<int, int>(1, 3));
    vector < vector < pair<int, int> > > res = STPrim(gr);
    for (int i = 0; i < static_cast<int>(gr.size()); ++i)
        for (int j = 0; j < static_cast<int>(gr[i].size()); ++j)
            EXPECT_EQ(gr[i][j], res[i][j]);
}
TEST(STPrim, throw_when_graph_is_disconnected) {
    vector < vector < pair<int, int> > > gr(5);
    gr[0] = vector<pair<int, int>>(1, pair<int, int>(1, 1));
    gr[1] = vector<pair<int, int>>(2);
    gr[1][0] = pair<int, int>(0, 1);
    gr[1][1] = pair<int, int>(2, 3);
    gr[2] = vector<pair<int, int>>(1, pair<int, int>(1, 3));
    gr[3] = vector<pair<int, int>>(1, pair<int, int>(4, 5));
    gr[4] = vector<pair<int, int>>(1, pair<int, int>(3, 5));
    ASSERT_ANY_THROW(STPrim(gr));
}
TEST(STPrim, work_right_for_complete_graph_with_three_vertexes) {
    vector < vector < pair<int, int> > > gr(3);
    gr[0] = vector<pair<int, int>>(2);
    gr[0][0] = pair<int, int>(1, 1);
    gr[0][1] = pair<int, int>(2, 4);
    gr[1] = vector<pair<int, int>>(2);
    gr[1][0] = pair<int, int>(0, 1);
    gr[1][1] = pair<int, int>(2, 3);
    gr[2] = vector<pair<int, int>>(2);
    gr[2][0] = pair<int, int>(1, 3);
    gr[2][1] = pair<int, int>(0, 4);
    vector < vector < pair<int, int> > > res = STPrim(gr);
    vector < vector < pair<int, int> > > exp = gr;
    exp[0].pop_back();
    exp[2].pop_back();
    for (int i = 0; i < static_cast<int>(exp.size()); ++i)
        for (int j = 0; j < static_cast<int>(exp[i].size()); ++j)
            EXPECT_EQ(exp[i][j], res[i][j]);
}
TEST(STPrim, work_right_for_connected_graph_with_five_vertexes) {
    char filename1[] = "GraphAdjacencyList";
    vector < vector < pair<int, int> > > gr = CreateGraphAdjacencyList(filename1);
    char filename2[] = "connected_graph_with_five_vertexes_a_l.txt";
    PrintGraphAdjacencyList(gr, filename2);
    vector<vector<pair<int, int>>> res = STPrim(gr);
    char filename3[] = "spanning_tree_with_five_vertexes_Prim.txt";
    PrintGraphAdjacencyList(res, filename3);
    EXPECT_EQ(res[0][0].first, 3);
    EXPECT_EQ(res[0][0].second, 2);
    EXPECT_EQ(res[1][0].first, 4);
    EXPECT_EQ(res[1][0].second, 1);
    EXPECT_EQ(res[2][0].first, 3);
    EXPECT_EQ(res[2][0].second, 5);
    EXPECT_EQ(static_cast<int>(res[3].size()), 3);
    bool f1 = 0, f2 = 0, f3 = 0;
    for (int i = 0; i < 3; ++i) {
        if (res[3][i] == pair<int, int>(0, 2)) f1 = 1;
        if (res[3][i] == pair<int, int>(4, 1)) f2 = 1;
        if (res[3][i] == pair<int, int>(2, 5)) f3 = 1;
    }
    EXPECT_EQ(f1*f2*f3, 1);
    EXPECT_EQ(static_cast<int>(res[4].size()), 2);
    f1 = 0;
    f2 = 0;
    for (int i = 0; i < 2; ++i) {
        if (res[4][i] == pair<int, int>(1, 1)) f1 = 1;
        if (res[4][i] == pair<int, int>(3, 1)) f2 = 1;
    }
    EXPECT_EQ(f1*f2, 1);
}
