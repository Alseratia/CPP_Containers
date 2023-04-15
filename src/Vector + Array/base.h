#ifndef SRC_BASE_H_
#define SRC_BASE_H_

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>

namespace Study {
template <typename T>
class Massive {
 public:
  class Iterator {
   private:
    T* pointer_ = nullptr;

   public:
    Iterator() {}
    explicit Iterator(T* pointer) : pointer_(pointer){};
    Iterator& operator=(T* pointer) {
      pointer_ = pointer;
      return *this;
    }
    T& operator*() { return *pointer_; }
    bool operator>=(const Iterator& other) const {
      return pointer_ >= other.pointer_;
    }
    bool operator<(const Iterator& other) const {
      return pointer_ < other.pointer_;
    }
    int operator-(const Iterator& other) const {
      return pointer_ - other.pointer_;
    }
    void operator++() { pointer_++; }
    void operator--() { pointer_--; }
    bool operator==(const Iterator& other) const {
      return other.pointer_ == pointer_;
    }
    bool operator!=(const Iterator& other) const {
      return other.pointer_ != pointer_;
    }
  };  // Iterator

  using value_type = T;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = Iterator;
  using const_iterator = const iterator;
  using size_type = std::size_t;

 protected:
  value_type* value_;
  size_type size_;

 public:
  Massive() : value_(nullptr), size_(0) {}
  Massive(const Massive& other) : value_(other.value_), size_(other.size_) {}
  Massive(value_type* data, size_type size) { CreateMassive(data, size); }

  // Element access
  reference At(size_type pos);
  const_reference Front() const { return value_[0]; }
  const_reference Back() const { return value_[size_ - 1]; }
  T* Data() { return value_; }

  // Iterators
  iterator begin();
  iterator end();

  // Capacity
  bool Empty() const { return size_ ? false : true; }
  size_type Size() const { return size_; }
  size_type MaxSize() const { return size_; }

  // Operators
  reference operator[](size_type pos);

 protected:
  void CreateMassive(value_type* data, size_type size);
  void CheckPosition(size_type pos);
  void CheckPosition(iterator pos);

};  // Massive
}  // namespace Study

#include "base.inl"
#endif  // SRC_BASE_H_