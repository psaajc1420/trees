//
// Created by jacob on 11/10/21.
//

#ifndef TREES_SRC_BINARY_SEARCH_TREE_H_
#define TREES_SRC_BINARY_SEARCH_TREE_H_

#include <iostream>
#include <iterator>
#include "trees/binary_tree.h"

template<typename T>
class BinarySearchTree : public BinaryTree<T> {

  using Iterator = typename BinaryTree<T>::iterator;
  using TreeNode = typename BinaryTree<T>::TreeNode;
 public:
  BinarySearchTree() { root_ = nullptr; }
  BinarySearchTree(const BinarySearchTree &);
  ~BinarySearchTree() override;
  BinarySearchTree &operator=(const BinarySearchTree &);

  void Insert(T) override;
  Iterator Find(T) override;
  bool Empty() const override;
  void Clear() override;

  void Inorder();
 private:
  TreeNode *root_;

  void Insert(TreeNode *&, T);
  void Inorder(TreeNode *node);
  void Copy(TreeNode *, TreeNode *&);
  void Clear(TreeNode *&);
  TreeNode *Find(TreeNode *&, T);

};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &tree) {
  Copy(tree.root_, root_);
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  Clear();
}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &tree) {
  if (this != &tree) {
    Clear();
    Copy(tree.root_, root_);
  }
  return *this;
}

template<typename T>
void BinarySearchTree<T>::Clear() {
  Clear(root_);
}

template<typename T>
void BinarySearchTree<T>::Insert(T key) {
  Insert(root_, key);
}

template<typename T>
void BinarySearchTree<T>::Insert(TreeNode *&node, T key) {
  if (node == nullptr) {
    node = new TreeNode(key);
    return;
  }

  if (key < node->key_) {
    Insert(node->left_, key);
  } else {
    Insert(node->right_, key);
  }
}

template<typename T>
void BinarySearchTree<T>::Inorder(TreeNode *node) {

  if (node == nullptr) {
    return;
  }

  Inorder(node->left_);
  std::cout << node->key_ << " ";
  Inorder(node->right_);
}

template<typename T>
void BinarySearchTree<T>::Inorder() {
  Inorder(root_);
}

template<typename T>
bool BinarySearchTree<T>::Empty() const {
  return root_ == nullptr;
}

template<typename T>
void BinarySearchTree<T>::Copy(TreeNode *orig_tree_node, TreeNode *&node) {
  if (orig_tree_node == nullptr) {
    return;
  }

  node = new TreeNode(orig_tree_node->key_,
                      orig_tree_node->left_,
                      orig_tree_node->right_);

  Copy(orig_tree_node->left_, node->left_);
  Copy(orig_tree_node->right_, node->right_);
}

template<typename T>
void BinarySearchTree<T>::Clear(TreeNode *&node) {
  if (node == nullptr) {
    return;
  }

  Clear(node->left_);
  Clear(node->right_);

  delete node;
  node = nullptr;
}

template<typename T>
typename BinarySearchTree<T>::Iterator BinarySearchTree<T>::Find(T key) {
  TreeNode *node = Find(root_, key);
  if (node == nullptr) {
    return BinarySearchTree<T>::Iterator(nullptr);
  }

  return BinarySearchTree<T>::Iterator(node);
}

template<typename T>
typename BinarySearchTree<T>::TreeNode *BinarySearchTree<T>::Find(TreeNode *&node,
                                                                  T key) {
  if (node == nullptr || node->key_ == key) {
    return node;
  }
  if (key < node->key_) {
    return Find(node->left_, key);
  }

  return Find(node->right_, key);
}

#endif //TREES_SRC_BINARY_SEARCH_TREE_H_
