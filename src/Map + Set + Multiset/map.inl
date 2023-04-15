#include "map.h"
namespace Study {

template <typename Key, typename Value, class Compare>
Map<Key, Value, Compare>::Map(std::initializer_list<value_type> const& items) {
  for (auto item : items) {
    Insert(item);
  }
}

template <typename Key, typename Value, class Compare>
Map<Key, Value, Compare>& Map<Key, Value, Compare>::operator=(
    const Map& other) {
  this->Clear();
  if (other.head_ != nullptr) {
    Iterator it(other.head_);
    this->CopySet(it);
  }
  return *this;
}

template <typename Key, typename Value, class Compare>
typename Map<Key, Value, Compare>::mapped_type& Map<Key, Value, Compare>::At(
    const Key& key) {
  iterator res = this->Find({key, Value()});
  if (res == nullptr) throw std::out_of_range("No elements");
  return res.GetKey().second;
}

template <typename Key, typename Value, class Compare>
typename Map<Key, Value, Compare>::mapped_type&
Map<Key, Value, Compare>::operator[](const Key& key) {
  std::pair<typename Map<Key, Value>::iterator, bool> res =
      Insert({key, Value()});
  return res.first.GetKey().second;
}

template <typename Key, typename Value, class Compare>
std::pair<typename Map<Key, Value, Compare>::iterator, bool>
Map<Key, Value, Compare>::InsertOrAssign(const Key& key, const Value& obj) {
  std::pair<iterator, bool> result = Insert({key, obj});
  if (result.second == false) result.first.GetKey().second = obj;
  return result;
}
}  // namespace Study