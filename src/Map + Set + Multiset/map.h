#ifndef SRC_MAP_H_
#define SRC_MAP_H_
//#include <functional>
#include <stdexcept>

#include "set.h"

namespace Study {

template <typename Key, typename Value>
struct PairLess {
  bool operator()(const std::pair<Key, Value>& one,
                  const std::pair<Key, Value>& two) {
    return (one.first < two.first);
  }
};

template <typename Key, typename Value, class Compare = PairLess<Key, Value>>
class Map : public Set<std::pair<Key, Value>, Compare> {
 public:
  using key_type = Key;
  using mapped_type = Value;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = typename Set<std::pair<Key, Value>, Compare>::iterator;
  using Iterator = typename Set<std::pair<Key, Value>, Compare>::Iterator;
  using size_type = std::size_t;
  using Set<std::pair<Key, Value>, Compare>::head_;

 public:
  // Constructors
  Map() {}
  explicit Map(std::initializer_list<value_type> const& items);
  Map(const Map& other) : Set<std::pair<Key, Value>, Compare>() {
    *this = other;
  }
  Map(Map&& other) { this->Swap(other); }
  ~Map() {}
  Map& operator=(Map&& other) {
    Swap(other);
    return *this;
  }
  Map& operator=(const Map& other);

  // Element access
  mapped_type& At(const Key& key);
  mapped_type& operator[](const Key& key);

  // Modifiers
  using Set<std::pair<Key, Value>, PairLess<Key, Value>>::Insert;
  std::pair<iterator, bool> Insert(const Key& key, const Value& obj) {
    return Insert({key, obj});
  }
  std::pair<iterator, bool> InsertOrAssign(const Key& key, const Value& obj);
  // Lookup
  bool Contains(const Key& key) {
    return Set<std::pair<Key, Value>, Compare>::Contains({key, Value()});
  }
}; // class Map
}  // namespace Study

#include "map.inl"
#endif  // MAP_H_
