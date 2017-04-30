#include <gtest/gtest.h>
#include "islands.h"
#include <time.h>

TEST(PercolationUF, can_delete_islands) {
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    m[0][3] = 1;
    m[1][3] = 1;
    m[2][3] = 1;
    m[3][3] = 1;
    m[4][3] = 1;
    m[1][1] = 1;
    m[2][1] = 1;
    std::vector<std::vector<int>> exp = m;
    exp[1][1] = 0;
    exp[2][1] = 0;
    std::vector<std::vector<int>> res = PercolationUF(m);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            EXPECT_EQ(exp[i][j], res[i][j]);
}
TEST(PercolationWidth, can_delete_islands) {
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    m[0][3] = 1;
    m[1][3] = 1;
    m[2][3] = 1;
    m[3][3] = 1;
    m[4][3] = 1;
    m[1][1] = 1;
    m[2][1] = 1;
    std::vector<std::vector<int>> exp = m;
    exp[1][1] = 0;
    exp[2][1] = 0;
    std::vector<std::vector<int>> res = PercolationWidth(m);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            EXPECT_EQ(exp[i][j], res[i][j]);
}
TEST(PercolationUF, retains_ways_with_no_islands) {
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    m[0][3] = 1;
    m[1][3] = 1;
    m[2][3] = 1;
    m[3][3] = 1;
    m[4][3] = 1;
    std::vector<std::vector<int>> res = PercolationUF(m);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            EXPECT_EQ(m[i][j], res[i][j]);
}
TEST(PercolationWidth, retains_ways_with_no_islands) {
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    m[0][3] = 1;
    m[1][3] = 1;
    m[2][3] = 1;
    m[3][3] = 1;
    m[4][3] = 1;
    std::vector<std::vector<int>> res = PercolationWidth(m);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            EXPECT_EQ(m[i][j], res[i][j]);
}
TEST(islands, PercolationUF_and_PercolationWidth_return_the_same_results) {
    std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
    srand(time(NULL));
    int x, y;
    for (int j = 0; j < 25; ++j) {
        x = rand() % 5;
        y = rand() % 5;
        if (m[x][y] == 1) {
            j--;
            continue;
        }
        m[x][y] = 1;
        std::vector<std::vector<int>> res1 = PercolationUF(m);
        std::vector<std::vector<int>> res2 = PercolationWidth(m);
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                EXPECT_EQ(res1[i][j], res2[i][j]);
    }
}
