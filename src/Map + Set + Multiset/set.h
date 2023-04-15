#ifndef SRC_SET_H
#define SRC_SET_H
#include <cstdint>
#include <stdexcept>
#include <vector>

#include "binary_tree.h"

namespace Study {

template <typename Key, class Compare = std::less<Key>>
class Set : public BinaryTree<Key, Compare> {
 public:
  using typename BinaryTree<Key, Compare>::TreeNode;

  class Iterator : public BinaryTree<Key, Compare> {
   private:
    TreeNode* node_ = nullptr;
    TreeNode* tree_head_ = nullptr;

   public:
    Iterator() {}
    explicit Iterator(TreeNode* node) { node_ = node; }
    Iterator(TreeNode* node, TreeNode* head) {
      node_ = node;
      tree_head_ = head;
    }
    Iterator(const Iterator& other) { *this = other; }
    ~Iterator() { node_ = nullptr; }
    Iterator& operator=(const Iterator& other) {
      node_ = other.node_;
      tree_head_ = other.tree_head_;
      return *this;
    }

    Key operator*() const;
    void operator++() { node_ = IncreaseIterator(); }
    void operator--() { node_ = DecreaceIterator(); }
    bool operator==(const Iterator& other) const {
      return node_ == other.node_;
    }
    bool operator==(const TreeNode* other) const { return node_ == other; }
    bool operator!=(const Iterator& other) const {
      return node_ != other.node_;
    }
    bool operator!=(const TreeNode* other) const { return node_ != other; }

    TreeNode*& GetNode() { return node_; }
    Key& GetKey() { return node_->key; }
    void SetKey(const Key& key) { node_->key = key; }

   private:
    TreeNode* IncreaseIterator();
    TreeNode* DecreaceIterator();
  };  // Iterator

  using BinaryTree<Key, Compare>::head_;
  using key_type = Key;
  using size_type = std::size_t;
  using iterator = Iterator;

  // Constructors and destructor
  Set(){};
  explicit Set(std::initializer_list<key_type> const& items);
  Set(const Set& other);
  Set(Set&& other) { Swap(other); }
  ~Set(){};
  Set& operator=(const Set& other);
  Set& operator=(Set&& other) {
    Swap(other);
    return *this;
  }

  // Iterators
  iterator begin() { return iterator(this->MinNode(), head_); }
  iterator end() { return iterator(nullptr, head_); }

  // Capacity
  bool Empty() const { return head_ ? false : true; }
  size_type Size();
  size_type MaxSize() const { return SIZE_MAX / sizeof(*this); }

  // Modifiers
  void Clear() { this->DeleteTree(head_); }
  std::pair<iterator, bool> Insert(const key_type& value);
  void Erase(iterator pos);
  void Swap(Set& other) {
    if (head_ != other.head_) std::swap(head_, other.head_);
  }
  void Merge(Set& other);

  // Lookup
  iterator Find(const key_type& key);
  bool Contains(const key_type& key) {
    return this->FindNode(key) == nullptr ? false : true;
  }

  // Emplace
  std::vector<std::pair<iterator, bool>> Emplace();
  template <class... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args&&... args);

 protected:
  // Other
  void CopySet(iterator it);
}; // class Set

}  // namespace Study

#include "set.inl"
#endif  // SRC_SET_H