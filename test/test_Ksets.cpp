#include <gtest/gtest.h>
#include "Ksets.h"
TEST(Ksets, works_right) {
    std::vector<std::pair<int, int>> a(3);
    a[0] = std::pair<int, int>(1, 2);
    a[1] = std::pair<int, int>(0, 4);
    a[2] = std::pair<int, int>(2, 5);
    std::vector<int> res = Ksets(a, 6);
    for (int i = 0; i < 3; ++i)
        EXPECT_TRUE(res[a[i].first] != res[a[i].second]);
}
TEST(Ksets, works_when_K_must_be_equel_1) {
    std::vector<std::pair<int, int>> a;
    ASSERT_NO_THROW(Ksets(a, 6));
    std::vector<int> res = Ksets(a, 6);
    for (int i = 0; i < 6; ++i)
        EXPECT_EQ(res[i], res[0]);
}
TEST(Ksets, works_when_K_must_be_equel_n) {
    std::vector<std::pair<int, int>> a(3);
    a[0] = std::pair<int, int>(0, 1);
    a[1] = std::pair<int, int>(1, 2);
    a[2] = std::pair<int, int>(0, 2);
    std::vector<int> res = Ksets(a, 3);
    for (int i = 0; i < 3; ++i)
        EXPECT_TRUE(res[a[i].first] != res[a[i].second]);
}
