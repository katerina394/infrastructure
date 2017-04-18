#include <gtest/gtest.h>
#include "RBTree.h"
TEST(RBTree, can_create_empty_tree) {
	ASSERT_NO_THROW(RBTree<int> a());
	RBTree<int> b;
	EXPECT_EQ(b.GetRoot(), NIL);
}
TEST(RBTree, can_create_tree) {
	ASSERT_NO_THROW(RBTree<int> a(3));
	RBTree<int> b(3);
	EXPECT_EQ(b.GetRoot()->val, 3);
}
TEST(RBTree, can_insert_node) {
	RBTree<int> b(3);
	ASSERT_NO_THROW(b.Insert(1));
}
TEST(RBTree, can_insert_node_in_empty_tree) {
	RBTree<int> b;
	ASSERT_NO_THROW(b.Insert(1));
}
TEST(RBTree, throw_when_insert_existing_node) {
	RBTree<int> b(3);
	ASSERT_ANY_THROW(b.Insert(3));
}

TEST(RBTree, can_find_node) {
	RBTree<int> b(3);
	b.Insert(1);
	ASSERT_NO_THROW(b.Find(1));
	rbnode<int> *res = b.Find(1);
	EXPECT_EQ(res->val, 1);
}
TEST(RBTree, throw_when_search_absent_node) {
	RBTree<int> b(3);
	b.Insert(1);
	ASSERT_ANY_THROW(b.Find(2));
}
TEST(RBTree, can_insert_node_in_any_case) {
	RBTree<int> b(7);
	ASSERT_NO_THROW(b.Insert(3));
	ASSERT_NO_THROW(b.Insert(5));
	ASSERT_NO_THROW(b.Insert(1));
	ASSERT_NO_THROW(b.Insert(2));
	ASSERT_NO_THROW(b.Insert(4));
	ASSERT_NO_THROW(b.Insert(6));
	ASSERT_NO_THROW(b.Find(2));
}
TEST(RBTree, throw_when_delete_absent_node) {
	RBTree<int> b(3);
	b.Insert(1);
	ASSERT_ANY_THROW(b.Delete(2));
}
TEST(RBTree, can_delete_node_with_no_childs) {
	RBTree<int> b(3);
	b.Insert(1);
	ASSERT_NO_THROW(b.Delete(1));
}
TEST(RBTree, can_delete_node_with_one_child) {
	RBTree<int> b(7);
	ASSERT_NO_THROW(b.Insert(3));
	ASSERT_NO_THROW(b.Insert(5));
	ASSERT_NO_THROW(b.Insert(1));
	ASSERT_NO_THROW(b.Insert(2));
	ASSERT_NO_THROW(b.Insert(4));
	ASSERT_NO_THROW(b.Find(5));
	ASSERT_NO_THROW(b.Delete(5));
	ASSERT_ANY_THROW(b.Find(5));
}
TEST(RBTree, can_delete_node_with_two_child) {
	RBTree<int> b(7);
	ASSERT_NO_THROW(b.Insert(3));
	ASSERT_NO_THROW(b.Insert(5));
	ASSERT_NO_THROW(b.Insert(1));
	ASSERT_NO_THROW(b.Insert(2));
	ASSERT_NO_THROW(b.Insert(4));
	ASSERT_NO_THROW(b.Find(3));
	ASSERT_NO_THROW(b.Delete(3));
	ASSERT_ANY_THROW(b.Find(3));
}