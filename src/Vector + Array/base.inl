#include "base.h"

namespace Study {
template <typename T>
typename Massive<T>::reference Massive<T>::At(size_type pos) {
  CheckPosition(pos);
  return value_[pos];
}

template <typename T>
typename Massive<T>::iterator Massive<T>::begin() {
  return iterator(&value_[0]);
}

template <typename T>
typename Massive<T>::iterator Massive<T>::end() {
  return iterator(&value_[size_]);
}

template <typename T>
typename Massive<T>::reference Massive<T>::operator[](size_type pos) {
  CheckPosition(pos);
  return value_[pos];
}

template <typename T>
void Massive<T>::CreateMassive(value_type* data, size_type size) {
  value_ = data;
  size_ = size;
}

template <typename T>
void Massive<T>::CheckPosition(size_type pos) {
  if (pos >= size_) throw std::out_of_range("Invalid argument");
}

template <typename T>
void Massive<T>::CheckPosition(iterator pos) {
  if (pos >= end() || pos < begin())
    throw std::out_of_range("Invalid argument");
}
}  // namespace Study