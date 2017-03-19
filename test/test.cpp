#include <gtest/gtest.h>
#include "find.h"
int i = 0;
void TestTree(CNode*root, int* a) {
    if (root) {
        TestTree(root->left, a);
		a[i++] = root->val;
        TestTree(root->right, a);
    }
}
TEST(CreateTree, can_create_search_tree_with_odd_number_of_items) {
	int a[] = {2,3,5,7,9};
	CNode *tree = CreateTree(a,5);
	int *res = (int*)malloc(sizeof(int)*5);
	TestTree(tree, res);
	i = 0;
	for (int i = 0; i < 5; i++)
		EXPECT_EQ(res[i], a[i]);
}
TEST(CreateTree, can_create_search_tree_with_even_number_of_items) {
	int a[] = {2,3,5,7,9,10};
	CNode *tree = CreateTree(a,6);
	int *res = (int*)malloc(sizeof(int)*6);
	TestTree(tree, res);
	i = 0;
	for (int i = 0; i < 6; i++)
		EXPECT_EQ(res[i], a[i]);
}
TEST(CreateTree, can_create_balanced_search_tree) {
	int a[] = {2,3,5,7,9};
	CNode *tree = CreateTree(a,5);
	EXPECT_EQ(tree->val, 5);
	EXPECT_EQ(tree->left->val, 2);
	EXPECT_EQ(tree->right->val, 7);
	EXPECT_EQ(tree->left->right->val, 3);
	EXPECT_EQ(tree->right->right->val, 9);
}
TEST(CreateTree, can_find_elem_in_search_tree) {
	int a[] = {2,3,5,7,9};
	CNode *tree = CreateTree(a,5);
	CNode**res = find(&tree, 3);
    EXPECT_EQ(tree->left->right, *res);
}
TEST(CreateTree, Throw_when_n_is_negative) {
	int a[] = {2,3,5,7,9};
	ASSERT_ANY_THROW(CreateTree(a,-3));
}
TEST(CreateTree, Throw_when_a_is_NULL) {
	int *a = 0;
	ASSERT_ANY_THROW(CreateTree(a,3));
}
TEST(CreateTree, Throw_when_array_is_not_ordered) {
	int a[] = {2,6,5};
	ASSERT_ANY_THROW(CreateTree(a,3));
}
int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

