//
// Created by jacob on 11/10/21.
//

#ifndef TREES_SRC_BINARY_TREE_H_
#define TREES_SRC_BINARY_TREE_H_

template <typename T>
class BinaryTree {

 protected:
  struct TreeNode {
    T key_;
    TreeNode *left_;
    TreeNode *right_;

    TreeNode() = default;
    explicit TreeNode(T key,
                      TreeNode *left = nullptr,
                      TreeNode *right = nullptr)
        : key_{key}, left_{left}, right_{right} {}
  };

  template<typename K=T>
  class Iterator {
    using SelfType = Iterator;
   public:

    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = K;
    using pointer = K *;
    using reference = K &;

    Iterator() = default;
    Iterator(const Iterator &) = default;
    ~Iterator() = default;
    Iterator &operator=(const Iterator &) = default;
    explicit Iterator(TreeNode *root = nullptr) : root_{root} {}

    T &operator*() {
      return root_->key_;
    }

    SelfType operator++() {

    }

    friend bool operator==(const Iterator &lhs, const Iterator &rhs) {
      return lhs.root_ == rhs.root_;
    }

    friend bool operator!=(const Iterator &lhs, const Iterator &rhs) {
      return lhs.root_ != rhs.root_;
    }

   private:
    TreeNode *root_;
  };

 public:
  using iterator = Iterator<T>;

  virtual ~BinaryTree() = default;
  virtual void Insert(T) = 0;
  virtual iterator Find(T) = 0;
  virtual bool Empty() const = 0;
  virtual void Clear() = 0;
};

#endif //TREES_SRC_BINARY_TREE_H_
