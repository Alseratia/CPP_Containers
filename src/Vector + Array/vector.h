#ifndef SRC_VECTOR_H_
#define SRC_VECTOR_H_

#include "base.h"
namespace Study {

template <typename T>
class Vector : public Massive<T> {
  using value_type = T;
  using reference = value_type&;
  using const_reference = const reference;
  using iterator = typename Massive<T>::Iterator;
  using const_iterator = const iterator;
  using size_type = std::size_t;

 private:
  using Massive<T>::value_;
  using Massive<T>::size_;
  size_type capacity_;

 public:
  // Constructors and destructor
  Vector() { CreateVector(0); }
  explicit Vector(size_type n) { CreateVector(n); }
  Vector(const Vector& vector);
  Vector(Vector&& vector) { Swap(vector); }
  explicit Vector(std::initializer_list<value_type> const& items);
  Vector& operator=(const Vector& vector);
  Vector& operator=(Vector&& vector);
  ~Vector() { RemoveVector(); }

  // Capacity
  bool Empty() const { return capacity_ ? false : true; }
  size_type MaxSize() const { return (SIZE_MAX / sizeof(value_)); }
  void Reserve(size_type size);
  size_type Capacity() const { return capacity_; }
  void ShrinkToFit();

  // Modifiers
  void Clear() { this->size_ = 0; }
  iterator Insert(iterator pos, const_reference value);
  void Erase(iterator pos);
  void PushBack(const_reference value);
  void PopBack() {
    if (!this->Empty()) --this->size_;
  }
  void Swap(Vector& other);

  // Emplace
  iterator Emplace(const_iterator pos) { return pos; }
  template <typename Type, class... Args>
  iterator Emplace(iterator pos, Type number, Args... args);

  void EmplaceBack() {}
  template <typename Type, class... Args>
  void EmplaceBack(Type data, Args... args);

 private:
  using Massive<T>::CheckPosition;
  void CreateVector(const size_type capacity);
  void RemoveVector();
  void CopyVector(const Vector& other);
  void CheckCapacity();
};

}  // namespace Study
#include "vector.inl"
#endif  // SRC_VECTOR_H_
