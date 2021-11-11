//
// Created by jacob on 11/10/21.
//

#include <iostream>
#include "trees/binary_search_tree.h"

using namespace std;

int main() {

  BinarySearchTree<int> tree;
  int nums[] = {10, 5, 56, 16, 30, 2};
  for (auto num : nums) {
    tree.Insert(num);
  }

  tree.Inorder();

  return 0;
}
