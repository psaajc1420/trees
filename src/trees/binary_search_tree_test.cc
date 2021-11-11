//
// Created by jacob on 11/10/21.
//

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

TEST_F(BinarySearchTreeTest, Insert) {
  EXPECT_TRUE(tree_.Empty() == false);
  BinarySearchTree<int> new_tree;
  new_tree.Insert(10);
  EXPECT_TRUE(new_tree.Empty() == false);
}


}  // namespace
