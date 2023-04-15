#ifndef SRC_ARRAY_H_
#define SRC_ARRAY_H_
#include "base.h"

namespace Study {

template <typename T, std::size_t N>
class Array : public Massive<T> {
  using value_type = T;
  using reference = value_type &;
  using const_reference = const reference;
  using iterator = typename Massive<T>::Iterator;
  using const_iterator = const iterator;
  using size_type = std::size_t;

 private:
  value_type avalue_[N]{};
  size_type asize_ = N;

 public:
  // Constructors and destructor
  Array() { CreateMassive(avalue_, asize_); }
  explicit Array(std::initializer_list<value_type> const &items);
  Array(const Array &a) : Massive<T>() {
    CreateMassive(avalue_, asize_);
    CopyArray(a);
  }
  Array(Array &&a) : Array() { Swap(a); }
  Array &operator=(const Array &a);
  Array &operator=(Array &&a) {
    Swap(a);
    return *this;
  }
  ~Array() {}

  // Modifiers
  void Swap(Array &other);
  void Fill(const_reference value);

 private:
  void CopyArray(const Array &other);
  using Massive<T>::CreateMassive;
  using Massive<T>::CheckPosition;
};
}  // namespace Study

#include "array.inl"
#endif  // SRC_ARRAY_H_