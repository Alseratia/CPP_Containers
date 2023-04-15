#include "set.h"
namespace Study {

// -----------------------------Iterator----------------------------- //
template <typename key_type, class Compare>
typename Set<key_type, Compare>::key_type
Set<key_type, Compare>::Iterator::operator*() const {
  if (node_ == nullptr)
    throw std::out_of_range("operator *: iterator is nullptr");
  return node_->key;
}
template <typename key_type, class Compare>
typename Set<key_type, Compare>::TreeNode*
Set<key_type, Compare>::Iterator::IncreaseIterator() {
  if (node_->right != nullptr) return this->MinNode(node_->right);
  TreeNode* parent = node_->parent;
  while (parent && node_ == parent->right) {
    node_ = node_->parent;
    parent = node_->parent;
  }
  return parent;
}
template <typename key_type, class Compare>
typename Set<key_type, Compare>::TreeNode*
Set<key_type, Compare>::Iterator::DecreaceIterator() {
  if (node_ == nullptr && tree_head_) return this->MaxNode(tree_head_);
  if (node_->left != nullptr) return this->MaxNode(node_->left);
  TreeNode* parent = node_->parent;
  while (parent && node_ == parent->left) {
    node_ = node_->parent;
    parent = node_->parent;
  }
  return parent;
}
// -----------------------------Constructors----------------------------- //
template <typename key_type, class Compare>
Set<key_type, Compare>::Set(std::initializer_list<key_type> const& items) {
  for (auto item : items) {
    Insert(item);
  }
}
template <typename key_type, class Compare>
Set<key_type, Compare>::Set(const Set& other)
    : BinaryTree<key_type, Compare>() {
  *this = other;
}
template <typename key_type, class Compare>
Set<key_type, Compare>& Set<key_type, Compare>::operator=(const Set& other) {
  Clear();
  if (other.head_ != nullptr) {
    iterator it(other.head_);
    CopySet(it);
  }
  return *this;
}

// -----------------------------Capacity----------------------------- //
template <typename key_type, class Compare>
typename Set<key_type, Compare>::size_type Set<key_type, Compare>::Size() {
  size_type size = 0;
  for (Iterator it = begin(); it != end(); ++it) ++size;
  return size;
}
// -----------------------------Modifiers----------------------------- //
template <typename key_type, class Compare>
std::pair<typename Set<key_type, Compare>::iterator, bool>
Set<key_type, Compare>::Insert(const key_type& value) {
  std::pair<iterator, bool> result;
  TreeNode* src = this->FindNode(value);
  if (src == nullptr) {
    result.first = iterator(this->InsertInTree(value), head_);
    result.second = true;
  } else {
    result.first = iterator(src, head_);
    result.second = false;
  }
  return result;
}

template <typename key_type, class Compare>
void Set<key_type, Compare>::Erase(iterator pos) {
  if (pos.GetNode() != nullptr) this->DeleteNode(pos.GetKey());
}

template <typename key_type, class Compare>
void Set<key_type, Compare>::Merge(Set& other) {
  if (head_ != other.head_) {
    for (key_type it : other) {
      Insert(it);
    }
    other.Clear();
  }
}
// -----------------------------Lookup----------------------------- //
template <typename key_type, class Compare>
typename Set<key_type, Compare>::iterator Set<key_type, Compare>::Find(
    const key_type& key) {
  Iterator result(this->FindNode(key), head_);
  if (result.GetNode() == nullptr) result = end();
  return result;
}

// -----------------------------Emplace----------------------------- //
template <typename key_type, class Compare>
std::vector<std::pair<typename Set<key_type, Compare>::iterator, bool>>
Set<key_type, Compare>::Emplace() {
  std::vector<std::pair<iterator, bool>> result;
  result.push_back({end(), false});
  return result;
}
template <typename key_type, class Compare>
template <class... Args>
std::vector<std::pair<typename Set<key_type, Compare>::iterator, bool>>
Set<key_type, Compare>::Emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;
  for (auto& value : {args...}) {
    auto insertResult = Insert(value);
    result.push_back(insertResult);
  }
  return result;
}
// -----------------------------Other----------------------------- //
template <typename key_type, class Compare>
void Set<key_type, Compare>::CopySet(iterator it) {
  Insert(*it);
  if (it.GetNode()->right != nullptr) {
    Iterator it2(it.GetNode()->right);
    CopySet(it2);
  }
  if (it.GetNode()->left != nullptr) {
    Iterator it2(it.GetNode()->left);
    CopySet(it2);
  }
}

}  // namespace Study
