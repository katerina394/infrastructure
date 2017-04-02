#include <gtest/gtest.h>
#include "ways.h"

CNode test(char *s) {
    CNode res;
    res.x = 0;
    res.y = 0;
    for (int i = 1; s[i-1] != '\0'; ++i) {
        switch (s[i-1]) {
        case 'E':
            res.x += i;
            break;
        case 'W':
            res.x -= i;
            break;
        case 'N':
            res.y += i;
            break;
        case 'S':
            res.y -= i;
            break;
        }
    }
    return res;
}
TEST(ways, can_find_way) {
    CNode a;
    a.x = 2;
    a.y = 1;
    char *res = ways(a);
    char exp[] = "EWESN";
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(res[i], exp[i]);
}
TEST(test, work_right) {
    CNode a;
    a.x = 2;
    a.y = 1;
    char s[] = "EWESN";
    CNode b = test(s);
    EXPECT_EQ(a.x, b.x);
    EXPECT_EQ(a.y, b.y);
}
TEST(ways, can_find_way_2) {
    CNode a;
    a.x = -5;
    a.y = 1;
    char *res = ways(a);
    CNode b = test(res);
    EXPECT_EQ(a.x, b.x);
    EXPECT_EQ(a.y, b.y);
}
TEST(ways, can_find_way_in_100_points) {
    CNode a, b;
    char *res;
    for (a.x = -10; a.x < 10; ++a.x)
        for (a.y = -10; a.y < 10; ++a.y) {
            res = ways(a);
            b = test(res);
            EXPECT_EQ(a.x, b.x);
            EXPECT_EQ(a.y, b.y);
        }
}
