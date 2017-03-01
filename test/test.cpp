#include <gtest/gtest.h>
#include "find.h"

TEST(Find, SaveOriginalTree) {
    CNode *tree = new CNode(5);
    CNode *treecopy = tree;
    tree->left = new CNode(3);
    CNode *leftcopy = tree->left;
    tree->right = new CNode(7);
    CNode *rightcopy = tree->right;
    CNode**res = find(&tree, 1);
    EXPECT_EQ(treecopy, tree);
    EXPECT_EQ(leftcopy, tree->left);
    EXPECT_EQ(rightcopy, tree->right);
}
TEST(Find, CanFindExistingItem) {
    CNode *tree = new CNode(5);
    tree->left = new CNode(3);
    tree->right = new CNode(7);
    CNode**res = find(&tree, 3);
    EXPECT_EQ(tree->left, *res);
}
TEST(Find, CanIndicateTheAbsenceOfItem) {
    CNode *tree = new CNode(5);
    tree->left = new CNode(3);
    tree->right = new CNode(7);
    CNode**res = find(&tree, 1);
    EXPECT_EQ(0, *res);
}
TEST(Find, AllowToInsertAbsentItem) {
    CNode *tree = new CNode(5);
    tree->left = new CNode(3);
    tree->right = new CNode(7);
    CNode**res = find(&tree, 1);
    *res = new CNode(1);
    EXPECT_EQ(tree->left->left->val, 1);
}
int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}

