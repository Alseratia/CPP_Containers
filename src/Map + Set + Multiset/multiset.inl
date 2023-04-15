#include "multiset.h"

namespace Study {
// -----------------------------Constructors-----------------------------//

template <typename Key, class Compare>
Multiset<Key, Compare>::Multiset(std::initializer_list<key_type> const& items) {
  for (auto item : items) {
    Insert(item);
  }
}

template <typename Key, class Compare>
Multiset<Key, Compare>::Multiset(const Multiset& other) : Set<Key, Compare>() {
  *this = other;
}

template <typename Key, class Compare>
Multiset<Key, Compare>& Multiset<Key, Compare>::operator=(
    const Multiset& other) {
  this->Clear();
  if (other.head_ != nullptr) {
    Iterator it(other.head_);
    this->CopyMSet(it);
  }
  return *this;
}

// -----------------------------Modifiers----------------------------- //

template <typename Key, class Compare>
void Multiset<Key, Compare>::Merge(Multiset& other) {
  if (this->head_ != other.head_) {
    for (auto it : other) {
      Insert(it);
    }
    other.Clear();
  }
}

// -----------------------------Lookup----------------------------- //

template <typename Key, class Compare>
typename Multiset<Key, Compare>::size_type Multiset<Key, Compare>::Count(
    const Key& key) {
  size_type result = 0;
  Iterator it = this->Find(key);
  if (it != nullptr) ++result;
  while (it != nullptr && it != this->begin() && *it == key) {
    ++it;
    ++result;
  }
  if (it != nullptr && *it != key) --result;
  return result;
}

template <typename Key, class Compare>
std::pair<typename Multiset<Key, Compare>::iterator,
          typename Multiset<Key, Compare>::iterator>
Multiset<Key, Compare>::EqualRange(const key_type& key) {
  return std::make_pair(LowerBound(key), UpperBound(key));
}

template <typename Key, class Compare>
typename Multiset<Key, Compare>::iterator Multiset<Key, Compare>::LowerBound(
    const key_type& key) {
  auto i = this->begin();
  while (i != this->end() && *i < key) ++i;
  return i;
}

template <typename Key, class Compare>
typename Multiset<Key, Compare>::iterator Multiset<Key, Compare>::UpperBound(
    const Key& key) {
  Iterator it = this->begin();
  while (it != this->end() && *it <= key) ++it;
  return it;
}
// -----------------------------Emplace----------------------------- //
template <typename Key, class Compare>
std::vector<std::pair<typename Multiset<Key, Compare>::iterator, bool>>
Multiset<Key, Compare>::Emplace() {
  std::vector<std::pair<iterator, bool>> result;  // init?
  result.push_back({this->end(), false});
  return result;
}
template <typename Key, class Compare>
template <class... Args>
std::vector<std::pair<typename Multiset<Key, Compare>::iterator, bool>>
Multiset<Key, Compare>::Emplace(Args&&... args) {
  std::vector<std::pair<iterator, bool>> result;  // init?
  for (auto& value : {args...}) {
    std::pair<iterator, bool> insertResult = {Insert(value), true};
    result.push_back(insertResult);
  }
  return result;
}
// -----------------------------Other----------------------------- //
template <typename Key, class Compare>
void Multiset<Key, Compare>::CopyMSet(iterator it) {
  Insert(*it);
  if (it.GetNode()->right != nullptr) {
    iterator it2(it.GetNode()->right);
    this->CopyMSet(it2);
  }
  if (it.GetNode()->left != nullptr) {
    iterator it2(it.GetNode()->left);
    CopyMSet(it2);
  }
}
}  // namespace Study
