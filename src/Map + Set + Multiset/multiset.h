#ifndef SRC_MULTISET_H
#define SRC_MULTISET_H
#include <vector>

#include "set.h"
namespace Study {

template <typename Key, class Compare = std::less<Key>>
class Multiset : public Set<Key, Compare> {
 public:
  using typename Set<Key>::key_type;
  using typename Set<Key>::size_type;
  using typename Set<Key>::iterator;
  using typename Set<Key>::Iterator;
  using Set<Key>::head_;

  // Constructors and destructor
  Multiset() {}
  explicit Multiset(std::initializer_list<key_type> const& items);
  Multiset(const Multiset& other);
  Multiset(Multiset&& other) { this->Swap(other); }
  Multiset& operator=(Multiset&& other) {
    this->Swap(other);
    return *this;
  }
  Multiset& operator=(const Multiset& other);
  ~Multiset(){};

  // Modifiers
  iterator Insert(const key_type& value) {
    return iterator(this->InsertInTree(value), this->head_);
  }  // iterator
  void Merge(Multiset& other);

  // Lookup
  size_type Count(const Key& key);
  std::pair<iterator, iterator> EqualRange(const key_type& key);
  iterator LowerBound(const key_type& key);
  iterator UpperBound(const Key& key);

  // Emplace
  std::vector<std::pair<iterator, bool>> Emplace();
  template <class... Args>
  std::vector<std::pair<iterator, bool>> Emplace(Args&&... args);

  // Other
  void CopyMSet(iterator it);
};  // Multiset
}  // namespace Study

#include "multiset.inl"
#endif  // SRC_MULTISET_H
