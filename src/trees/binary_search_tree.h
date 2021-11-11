//
// Created by jacob on 11/10/21.
//

#ifndef TREES_SRC_BINARY_SEARCH_TREE_H_
#define TREES_SRC_BINARY_SEARCH_TREE_H_

#include <iostream>
#include "trees/binary_tree.h"

template<typename T>
class BinarySearchTree : public BinaryTree<T> {
  struct TreeNode {
    T data_;
    TreeNode *left_;
    TreeNode *right_;

    TreeNode() = default;
    explicit TreeNode(T data,
                      TreeNode *left = nullptr,
                      TreeNode *right = nullptr)
        : data_{data}, left_{left}, right_{right} {}
  };

 public:
  BinarySearchTree() { root_ = nullptr; }
  BinarySearchTree(const BinarySearchTree &);
  ~BinarySearchTree() override;
  BinarySearchTree &operator=(const BinarySearchTree &);

  void Insert(T);
  void Inorder();

  bool Empty() const;
  void Clear();

 private:
  TreeNode *root_;

  void Insert(TreeNode *&, T);
  void Inorder(TreeNode *node);
  void Copy(TreeNode *, TreeNode *&);
  void Clear(TreeNode*&);

};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T> &tree) {
  Copy(tree.root_);
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  Clear();
}

template<typename T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree<T> &tree) {
  if (this != &tree) {
    Clear();
    Copy(tree.root_);
  }
  return *this;
}

template<typename T>
void BinarySearchTree<T>::Clear() {
  Clear(root_);
}

template<typename T>
void BinarySearchTree<T>::Insert(T data) {
  Insert(root_, data);
}

template<typename T>
void BinarySearchTree<T>::Insert(TreeNode *&node, T data) {
  if (node == nullptr) {
    node = new TreeNode(data);
    return;
  }

  if (data < node->data_) {
    Insert(node->left_, data);
  } else {
    Insert(node->right_, data);
  }

}
template<typename T>
void BinarySearchTree<T>::Inorder(TreeNode *node) {

  if (node == nullptr) {
    return;
  }

  Inorder(node->left_);
  std::cout << node->data_ << " ";
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
  if (node == nullptr) {
    return;
  }

  node = new TreeNode(orig_tree_node->data_,
                      orig_tree_node->left_,
                      orig_tree_node->right_);

  Copy(orig_tree_node->left, node->left_);
  Copy(orig_tree_node->right, node->right_);
}

template<typename T>
void BinarySearchTree<T>::Clear(TreeNode *&node) {
  if (node == nullptr) {
    return;
  }

  Clear(node->left_);
  Clear(node->right_);

  delete node;
}

#endif //TREES_SRC_BINARY_SEARCH_TREE_H_
