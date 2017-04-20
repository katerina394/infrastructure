#include <gtest/gtest.h>
#include "FourHeap.h"
TEST(FourHeap, can_create_heap) {
    ASSERT_NO_THROW(FourHeap<int> h);
}
TEST(FourHeap, can_insert_in_heap) {
    FourHeap<int> h;
    ASSERT_NO_THROW(h.Insert(2));
    ASSERT_NO_THROW(h.Insert(5));
    ASSERT_NO_THROW(h.Insert(1));
}
TEST(FourHeap, can_find_min) {
    FourHeap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    EXPECT_EQ(1, h.Min());
}
TEST(FourHeap, can_delete_min) {
    FourHeap<int> h;
    h.Insert(2);
    h.Insert(5);
    h.Insert(1);
    ASSERT_NO_THROW(h.DeleteMin());
    EXPECT_EQ(2, h.Min());
}
TEST(FourHeap, can_check_empty) {
    FourHeap<int> h;
    EXPECT_TRUE(h.empty());
}
