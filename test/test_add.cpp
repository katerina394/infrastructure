#include <gtest/gtest.h>
#include "add.h"

TEST(arrays, work_right) {
    int a[] = { 1, 2, 3, 4, 2 };
    int exp[] = { 48, 24, 16, 12, 24 };
    int *res = arrays(a, 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(exp[i], res[i]);
    }
}
TEST(arrays, work_right_with_two_elems) {
    int a[] = {2, 5};
    int exp[] = {5, 2};
    int *res = arrays(a, 2);
    for (int i = 0; i < 2; ++i) {
        EXPECT_EQ(exp[i], res[i]);
	}
}
TEST(arrays, work_right_with_one_elem) {
    int a[] = {2};
    int exp[] = {1};
    int *res = arrays(a, 1);
    for (int i = 0; i < 1; ++i) {
        EXPECT_EQ(exp[i], res[i]);
    }
}