#include <gtest/gtest.h>
#include "Percolation.h"

TEST(Percolation, works) {
    std::vector<std::vector<int>> m(3, std::vector<int>(3, 0));
    m[0][0] = 1;
    m[1][0] = 1;
    m[1][1] = 1;
    m[2][1] = 1;
    EXPECT_TRUE(Percolation(m));
}
