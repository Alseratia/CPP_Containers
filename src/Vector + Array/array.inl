#include "array.h"

namespace Study {

// --------------------------------------------Constructors and destructor-------------------------------------------- //
template <typename T, std::size_t N>
Array<T, N>::Array(std::initializer_list<value_type> const &items) : Array() {
  size_type min = ((asize_ > items.size() ? items.size() : asize_));
  for (size_type i = 0; i < min; ++i) avalue_[i] = *(items.begin() + i);
}
template <typename T, std::size_t N>
Array<T, N> &Array<T, N>::operator=(const Array &a) {
  CopyArray(a);
  return *this;
}
// --------------------------------------------Modifiers--------------------------------------------//
template <typename T, std::size_t N>
void Array<T, N>::Swap(Array &other) {
  if (other.avalue_ != this->avalue_) {
    std::swap(avalue_, other.avalue_);
    CreateMassive(avalue_, asize_);
    other.CreateMassive(other.avalue_, other.asize_);
  }
}
template <typename T, std::size_t N>
void Array<T, N>::Fill(const_reference value) {  // не работает без переменных
  for (size_type i = 0; i < asize_; ++i) avalue_[i] = value;
}

// --------------------------------------------Other--------------------------------------------//

template <typename T, std::size_t N>
void Array<T, N>::CopyArray(const Array &other) {
  for (size_type i = 0; i < asize_; ++i) {
    avalue_[i] = other.avalue_[i];
  }
}
}  // namespace Study
