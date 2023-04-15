#ifndef SRC_BINARY_TREE_H
#define SRC_BINARY_TREE_H
#include <cstdint>

namespace Study {

template <typename Key, class Compare = std::less<Key>>
class BinaryTree {
 protected:
  struct TreeNode {
    Key key;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
  };
  using key_type = Key;
  using const_key = const key_type;
  using node = TreeNode*;
  using node_reference = node&;
  using const_node = const node_reference;

  node head_ = nullptr;

  BinaryTree(){};
  ~BinaryTree() { DeleteTree(head_); }
  node_reference InsertInTree(const_key key) { return AddNode(head_, key); }
  void DeleteNode(const_key key) { DeleteNode(head_, key); }
  node_reference FindNode(const_key key) { return FindNode(head_, key); }
  node_reference MinNode() { return head_ ? MinNode(head_) : head_; }
  node_reference MinNode(const_node current) {
    return current->left == nullptr ? current : MinNode(current->left);
  }
  node_reference MaxNode() { return head_ ? MaxNode(head_) : head_; }
  node_reference MaxNode(const_node current) {
    return current->right == nullptr ? current : MaxNode(current->right);
  }
  void DeleteTree() { DeleteTree(head_); }
  void DeleteTree(node_reference current);

 private:
  node_reference FindNode(const_node current, const_key key);
  node_reference AddNode(node_reference current, const_key key);
  node_reference CreateNode(const_node parent, const_key key, bool left,
                            bool right);
  void DeleteNode(node_reference current, const_key& key);

  bool EqualKey(const_key& a, const_key& b, Compare cmp = Compare{}) {
    return (!cmp(a, b) && !cmp(b, a));
  }
  bool LessKey(const_key& a, const_key& b, Compare cmp = Compare{}) {
    return cmp(a, b);
  }
  bool GreaterKey(const_key& a, const_key& b, Compare cmp = Compare{}) {
    return cmp(b, a);
  }
}; // class BinaryTree
}  // namespace Study

#include "binary_tree.inl"
#endif  // SRC_BINARY_TREE_H