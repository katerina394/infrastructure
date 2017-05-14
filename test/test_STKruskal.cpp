#include <gtest/gtest.h>
#include "SpanningTree.h"
TEST(STKruskal, work_right_for_graph_with_one_vertex) {
    vector < vector<int> > gr(1);
    vector<int> w;
    vector < vector<int> > res(1);
    vector<int> wres;
    STKruskal(gr, w, &res, &wres);
    EXPECT_EQ(static_cast<int>(res.size()), 1);
    EXPECT_EQ(static_cast<int>(res[0].size()), 0);
    EXPECT_EQ(static_cast<int>(wres.size()), 0);
}
TEST(STKruskal, work_right_for_graph_which_equel_his_spanning_tree) {
    vector < vector<int> > gr(3, vector<int>(2, 1));
    gr[0][1] = 0;
    gr[2][0] = 0;
    vector<int> w(2);
    w[0] = 5;
    w[1] = 7;
    vector < vector<int> > res(3, vector<int>(2));
    vector<int> wres;
    STKruskal(gr, w, &res, &wres);
    for (int i = 0; i < static_cast<int>(gr.size()); ++i)
        for (int j = 0; j < static_cast<int>(gr[i].size()); ++j)
            EXPECT_EQ(gr[i][j], res[i][j]);
    for (int i = 0; i < static_cast<int>(w.size()); ++i)
        EXPECT_EQ(w[i], wres[i]);
}
TEST(STKruskal, throw_when_graph_is_disconnected) {
    vector < vector<int> > gr(4, vector<int>(2, 1));
    gr[0][1] = 0;
    gr[2][0] = 0;
    gr[3][0] = gr[3][1] = 0;
    vector<int> w(2);
    w[0] = 5;
    w[1] = 7;
    vector < vector<int> > res(4, vector<int>(3));
    vector<int> wres;
    ASSERT_ANY_THROW(STKruskal(gr, w, &res, &wres));
}
TEST(STKruskal, work_right_for_complete_graph_with_three_vertexes) {
    vector < vector<int> > gr(3, vector<int>(3, 1));
    gr[0][1] = 0;
    gr[1][2] = 0;
    gr[2][0] = 0;
    vector<int> w(3);
    w[0] = 5;
    w[1] = 7;
    w[2] = 11;
    vector < vector<int> > exp(3, vector<int>(2, 1));
    exp[0][1] = 0;
    exp[2][0] = 0;
    vector<int> wexp(2);
    wexp[0] = 5;
    wexp[1] = 7;
    vector < vector<int> > res(3, vector<int>(2));
    vector<int> wres;
    STKruskal(gr, w, &res, &wres);
    for (int i = 0; i < static_cast<int>(exp.size()); ++i)
        for (int j = 0; j < static_cast<int>(exp[i].size()); ++j)
            EXPECT_EQ(exp[i][j], res[i][j]);
    for (int i = 0; i < static_cast<int>(wexp.size()); ++i)
        EXPECT_EQ(wexp[i], wres[i]);
}
TEST(STKruskal, work_right_for_connected_graph_with_five_vertexes) {
    char filename1[] = "GraphMatrixOfIncidence";
    vector<vector<int>> gr;
    vector<int> w;
    CreateGraphMatrixOfIncidence(filename1, &gr, &w);
    char filename2[] = "connected_graph_with_five_vertexes_m_of_i.txt";
    PrintGraphMatrixOfIncidence(gr, w, filename2);
    vector < vector<int> > res(5, vector<int>(4));
    vector<int> wres;
    STKruskal(gr, w, &res, &wres);
    char filename3[] = "spanning_tree_with_five_vertexes_Kruskal.txt";
    PrintGraphMatrixOfIncidence(res, wres, filename3);
    vector < vector<int> > exp(5, vector<int>(4, 0));
    exp[0][2] = exp[1][0] = exp[2][3] = exp[3][1] =
    exp[3][2] = exp[3][3] = exp[4][0] = exp[4][1] = 1;
    vector<int> wexp(4, 1);
    wexp[2] = 2;
    wexp[3] = 5;
    for (int i = 0; i < static_cast<int>(exp.size()); ++i)
        for (int j = 0; j < static_cast<int>(exp[i].size()); ++j)
            EXPECT_EQ(exp[i][j], res[i][j]);
    for (int i = 0; i < static_cast<int>(wexp.size()); ++i)
        EXPECT_EQ(wexp[i], wres[i]);
}
