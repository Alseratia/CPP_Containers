#include "vector.h"
namespace Study {

// --------------------------------------------Constructors and destructor-------------------------------------------- //
template <typename T>
Vector<T>::Vector(const Vector& vector) : Massive<T>() {
  CreateVector(vector.size_);
  CopyVector(vector);
}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> const& items) {
  CreateVector(items.size());
  int count = 0;
  for (auto element : items) {
    this->value_[count] = element;
    count++;
  }
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& vector) {
  RemoveVector();
  CreateVector(vector.size_);
  CopyVector(vector);
  return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& vector) {
  RemoveVector();
  Swap(vector);
  return *this;
}

// --------------------------------------------Capacity--------------------------------------------//
template <typename T>
void Vector<T>::Reserve(size_type size) {
  if (size > MaxSize()) throw "Lenght error";
  if (size > capacity_) {
    int srcsize = size_;
    Vector<T> src(size);
    src.CopyVector(*this);
    RemoveVector();
    src.Swap(*this);
    size_ = srcsize;
  }
}
template <typename T>
void Vector<T>::ShrinkToFit() {
  if (size_ < capacity_) {
    Vector<T> src(size_);
    src.CopyVector(*this);
    RemoveVector();
    src.Swap(*this);
  }
}

// --------------------------------------------Modifiers--------------------------------------------//
template <typename T>
typename Vector<T>::iterator Vector<T>::Insert(iterator pos,
                                               const_reference value) {  // типы
  CheckPosition(pos);
  size_type p = pos - this->begin();
  CheckCapacity();
  for (size_type i = size_; i > p; --i) {
    value_[i] = value_[i - 1];
  }
  value_[p] = value;
  ++size_;
  iterator it(&value_[p]);
  return it;
}
template <typename T>
void Vector<T>::Erase(iterator pos) {  //
  CheckPosition(pos);
  size_type p = pos - this->begin();
  --size_;
  for (; p < size_; ++p) {
    value_[p] = value_[p + 1];
  }
}
template <typename T>
void Vector<T>::PushBack(const_reference value) {
  CheckCapacity();
  value_[size_] = value;
  ++size_;
}
template <typename T>
void Vector<T>::Swap(Vector& other) {
  std::swap(value_, other.value_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}
// --------------------------------------------Emplace--------------------------------------------//
template <class T>
template <class Type, class... Args>
typename Vector<T>::iterator Vector<T>::Emplace(iterator pos, Type data,
                                                Args... args) {
  pos = Insert(pos, data);
  Emplace(pos, args...);
  return pos;
}

template <typename T>
template <typename Type, class... Args>
void Vector<T>::EmplaceBack(Type data, Args... args) {
  PushBack(data);
  EmplaceBack(args...);
}
// --------------------------------------------Other-------------------------------------------- //
template <typename T>
void Vector<T>::CreateVector(const size_type capacity) {
  if (capacity > MaxSize()) throw "Max_size";
  if (capacity == 0)
    value_ = nullptr;
  else
    value_ = new value_type[capacity]{};
  size_ = capacity;
  capacity_ = capacity;
}
template <typename T>
void Vector<T>::RemoveVector() {
  if (capacity_ != 0) delete[] value_;
  capacity_ = 0;
  size_ = 0;
}
template <typename T>
void Vector<T>::CopyVector(const Vector& other) {
  for (size_type i = 0; i < size_ && i < other.size_; ++i) {
    value_[i] = other.value_[i];
  }
}

template <typename T>
void Vector<T>::CheckCapacity() {
  if (capacity_ == 0) {
    CreateVector(1);
    size_ = 0;
  } else if (this->size_ == capacity_) {
    Reserve(capacity_ * 2);
  }
}
}  // namespace Study
