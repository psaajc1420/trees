//
// Created by jacob on 11/10/21.
//
#include <string>
#include "trees/binary_search_tree.h"
#include "gtest/gtest.h"

namespace {

class BinarySearchTreeTest : public testing::Test {
 protected:
  void SetUp() override {
    std::vector<int> nums = {10, 5, 56, 16, 30, 2};
    for (auto num : nums) {
      tree_.Insert(num);
    }
  }

  BinarySearchTree<int> tree_;
};

TEST_F(BinarySearchTreeTest, DefaultConstructor) {
  BinarySearchTree<int> empty_tree;
  EXPECT_TRUE(empty_tree.Empty() == true);
}

TEST_F(BinarySearchTreeTest, CopyConstructor) {
  BinarySearchTree<int> empty_tree = tree_;
  EXPECT_TRUE(empty_tree.Empty() == false);
  auto it = empty_tree.Find(10);
  EXPECT_EQ(*it, 10);
  empty_tree.Clear();
  EXPECT_TRUE(empty_tree.Empty() == true);
}

TEST_F(BinarySearchTreeTest, AssignmentOperator) {
  BinarySearchTree<int> empty_tree;
  empty_tree = tree_;
  EXPECT_TRUE(empty_tree.Empty() == false);
  auto it = empty_tree.Find(10);
  EXPECT_EQ(*it, 10);
  empty_tree.Clear();
  EXPECT_TRUE(empty_tree.Empty() == true);
}

TEST_F(BinarySearchTreeTest, Insert) {
  EXPECT_TRUE(tree_.Empty() == false);
  BinarySearchTree<int> new_tree;
  new_tree.Insert(10);
  EXPECT_TRUE(new_tree.Empty() == false);
}

TEST_F(BinarySearchTreeTest, Find) {
  auto it = tree_.Find(10);
  EXPECT_EQ(*it, 10);
  it = tree_.Find(16);
  EXPECT_EQ(*it, 16);
}

TEST_F(BinarySearchTreeTest, Clear) {
  EXPECT_TRUE(tree_.Empty() == false);
  tree_.Clear();
  EXPECT_TRUE(tree_.Empty() == true);
  BinarySearchTree<std::string> tree;
  EXPECT_TRUE(tree.Empty() == true);
  tree.Insert("hello");
  EXPECT_TRUE(tree.Empty() == false);
}


}  // namespace
