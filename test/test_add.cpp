#include <gtest/gtest.h>
#include "add.h"

TEST(ways, can_find_way) {
    CNode a;
    a.x = 2;
    a.y = 1;
    char *res = ways(a);
    char *exp = "EWESN";
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], exp[i]);
}
