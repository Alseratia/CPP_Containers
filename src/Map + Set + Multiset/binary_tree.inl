#include "binary_tree.h"
namespace Study {

template <typename key_type, class Compare>
typename BinaryTree<key_type, Compare>::const_node
BinaryTree<key_type, Compare>::FindNode(const_node current, const_key key) {
  return current == nullptr || EqualKey(current->key, key)
             ? current
             : LessKey(key, current->key) ? FindNode(current->left, key)
                                          : FindNode(current->right, key);
}
template <typename key_type, class Compare>
void BinaryTree<key_type, Compare>::DeleteTree(node_reference current) {
  if (current != nullptr) {
    DeleteTree(current->left);
    DeleteTree(current->right);
    delete current;
    current = nullptr;
  }
}

template <typename key_type, class Compare>
typename BinaryTree<key_type, Compare>::node_reference
BinaryTree<key_type, Compare>::AddNode(node_reference current, const_key key) {
  if (current == nullptr) {
    current = new TreeNode;
    current->key = key;
    current->left = current->right = current->parent = nullptr;
  } else {
    if (GreaterKey(key, current->key)) {
      if (current->right != nullptr) {
        return AddNode(current->right, key);
      } else {
        return CreateNode(current, key, 0, 1);
      }
    } else if (LessKey(key, current->key)) {
      if (current->left != nullptr) {
        return AddNode(current->left, key);
      } else {
        return CreateNode(current, key, 1, 0);
      }
    } else if (EqualKey(key, current->key)) {
      if (current->right != nullptr) {
        TreeNode* src = current->right;
        CreateNode(current, key, 0, 1);
        current->right->right = src;
        src->parent = current->right;
        src = nullptr;
        return current->right;
      } else {
        return CreateNode(current, key, 0, 1);
      }
    }
  }
  return current;
}

template <typename key_type, class Compare>
typename BinaryTree<key_type, Compare>::node_reference
BinaryTree<key_type, Compare>::CreateNode(const_node parent, const_key key,
                                          bool left, bool right) {
  if (left) {
    parent->left = new TreeNode;
    parent->left->parent = parent;
    parent->left->right = parent->left->left = nullptr;
    parent->left->key = key;
  }
  if (right) {
    parent->right = new TreeNode;
    parent->right->parent = parent;
    parent->right->right = parent->right->left = nullptr;
    parent->right->key = key;
  }
  return right ? parent->right : parent->left;
}

template <typename key_type, class Compare>
void BinaryTree<key_type, Compare>::DeleteNode(node_reference current,
                                               const_key& key) {
  if (current != nullptr) {
    if (EqualKey(current->key, key)) {
      if (current->left == nullptr && current->right == nullptr) {
        delete current;
        current = nullptr;
      } else if (current->left == nullptr && current->right != nullptr) {
        current->right->parent = current->parent;
        node src = current;
        current = current->right;
        delete src;
      } else if (current->left != nullptr && current->right == nullptr) {
        current->left->parent = current->parent;
        node src = current;
        current = current->left;
        delete src;
      } else {
        current->key = MinNode(current->right)->key;
        DeleteNode(current->right, current->key);
      }
    } else if (LessKey(key, current->key)) {
      DeleteNode(current->left, key);
    } else {
      DeleteNode(current->right, key);
    }
  }
}

}  // namespace Study