#include <gtest/gtest.h>
#include "UnionFind.h"
TEST(UnionFind, can_create_collection) {
    ASSERT_NO_THROW(UnionFind h(5));
}
TEST(UnionFind, can_find_set_of_elem) {
    UnionFind h(5);
    ASSERT_NO_THROW(h.Find(3));
    EXPECT_EQ(3, h.Find(3));
}
TEST(UnionFind, can_union_singleton_sets) {
    UnionFind h(5);
    ASSERT_NO_THROW(h.Union(1, 2));
    EXPECT_EQ(h.Find(1), h.Find(2));
}
TEST(UnionFind, can_union_multi_item_set_with_singleton_set) {
    UnionFind h(5);
    h.Union(1, 2);
    ASSERT_NO_THROW(h.Union(2, 3));
    EXPECT_EQ(h.Find(2), h.Find(3));
}
TEST(UnionFind, can_union_singleton_set_with_multi_item_set) {
    UnionFind h(5);
    h.Union(1, 2);
    ASSERT_NO_THROW(h.Union(3, 1));
    EXPECT_EQ(h.Find(3), h.Find(1));
}
TEST(UnionFind, can_union_multi_item_sets) {
    UnionFind h(5);
    h.Union(1, 2);
    h.Union(3, 4);
    ASSERT_NO_THROW(h.Union(2, 3));
    EXPECT_EQ(h.Find(2), h.Find(4));
}
