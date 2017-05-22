#include <gtest/gtest.h>
#include "FiveHeap.h"
TEST(FourHeap, can_create_heap) {
    ASSERT_NO_THROW(FiveHeap<int> h);
}
TEST(FiveHeap, can_insert_in_heap) {
    FiveHeap<int> h;
    ASSERT_NO_THROW(h.Insert(2));
    ASSERT_NO_THROW(h.Insert(5));
    ASSERT_NO_THROW(h.Insert(1));
}
TEST(FiveHeap, can_find_min) {
    FiveHeap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    EXPECT_EQ(1, h.Min());
}
TEST(FiveHeap, can_delete_min) {
    FiveHeap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    ASSERT_NO_THROW(h.DeleteMin());
    EXPECT_EQ(2, h.Min());
}
TEST(FiveHeap, can_check_empty) {
    FiveHeap<int> h;
    EXPECT_TRUE(h.empty());
}
