#include "list.h"
using namespace Study;

template <typename T>
List<T>::List(std::initializer_list<value_type> const &items) {
  this->InitList();
  for (value_type value : items) {
    this->PushBack(value);
    ++size_;
  }
}

template <typename T>
List<T>::List(size_type size) {
  InitList();
  for (size_type i = 0; i < size; i++) {
    PushBack();
  }
  size_ = size;
}

template <typename T>
List<T>::List(List &&other) {
  this->Clear();
  head_ = other.head_;
  first_ = other.first_;
  end_ = other.end_;
  size_ = other.size_;

  other.head_ = nullptr;
  other.first_ = nullptr;
  other.end_ = nullptr;
  other.size_ = 0;
}

template <typename T>
List<T>::~List() {
  Node *r = first_;
  if (r != nullptr) {
    while (r != nullptr) {
      Node *temp = r;
      r = r->next_;
      delete temp;
    }
    head_ = nullptr;
    size_ = 0;
  }
}

template <typename T>
typename List<T>::List &List<T>::operator=(const List &other) {
  this->Clear();
  this->InitList();
  Node *r = other.head_;
  while (r != other.end_) {
    PushBack(r->value_);
    r = r->next_;
  }
  size_ = other.size_;
  return *this;
}

template <typename T>
typename List<T>::List &List<T>::operator=(List &&other) {
  this->Clear();
  this->InitList();
  Node *r = other.head_;
  while (r != other.end_) {
    PushBack(r->value_);
    r = r->next_;
  }
  size_ = other.size_;
  other.Clear();
  return *this;
}

template <typename T>
typename List<T>::iterator List<T>::Insert(iterator pos,
                                           const_reference value) {
  Node *ptr = pos.GetPointer();
  if (ptr == nullptr) throw std::out_of_range("insert: iterator is nullptr");
  Node *elemNew = new Node;
  elemNew->value_ = value;
  elemNew->next_ = ptr;
  elemNew->prev_ = ptr->prev_;
  ptr->prev_->next_ = elemNew;
  ptr->prev_ = elemNew;
  if (ptr == head_) {
    head_ = elemNew;
  }
  ++size_;
  return iterator(--pos);
}

template <typename T>
void List<T>::Erase(iterator pos) {
  Node *ptr = pos.GetPointer(), *del;
  if (ptr == nullptr) throw std::out_of_range("erase: iterator is nullptr");
  if (ptr == head_) {
    head_ = ptr->next_;
    del = ptr;
    ptr->prev_->next_ = ptr->next_;
    ptr->next_->prev_ = ptr->prev_;
  } else {
    del = ptr;
    ptr->prev_->next_ = ptr->next_;
    ptr->next_->prev_ = ptr->prev_;
  }
  --size_;
  if (size_ == 0) head_ = nullptr;
  delete del;
}

template <typename T>
void List<T>::PopBack() {
  if (!this->Empty()) {
    List<value_type>::iterator endIter = this->end();
    --endIter;
    this->Erase(endIter);
  }
}

template <typename T>
void List<T>::PopFront() {
  if (!this->Empty()) {
    List<value_type>::iterator _begin = this->begin();
    this->Erase(_begin);
  }
}

template <typename T>
void List<T>::Swap(List &other) {
  std::swap(head_, other.head_);
  std::swap(end_, other.end_);
  std::swap(first_, other.first_);
  std::swap(size_, other.size_);
}

template <typename T>
void List<T>::Merge(List &other) {
  List<value_type>::iterator iter = other.begin(), end = other.end();
  for (; iter != end; ++iter) {
    this->PushBack(*iter);
  }
}

template <typename T>
void List<T>::Splice(const_iterator pos, List &other) {
  List<value_type>::iterator end_ = other.end(),
                             iter = other.begin();  // unused temp
  for (; iter != end_; ++iter) {
    Insert(pos, *iter);
  }
}

template <typename T>
void List<T>::Reverse() {
  List<value_type> newlist;
  List<value_type>::iterator iter = this->end(), start = this->begin();
  --start;
  --iter;
  for (; iter != start; --iter) {
    newlist.PushBack(*iter);
  }
  *this = newlist;
}

template <typename T>
void List<T>::Unique() {
  List<value_type>::iterator iter = this->begin(), end = this->end();
  for (; iter != (end - 1); ++iter) {
    auto iter2 = iter + 1;
    while (iter2 != end && *iter == *(iter + 1)) {
      this->Erase(iter2);
      iter2 = iter + 1;
    }
  }
}

template <typename T>
void List<T>::PushBack() {
  if (first_ == nullptr) {
    this->InitList();
  }
  Node *elemNew = new Node;
  if (head_ == nullptr) {
    head_ = elemNew;
    head_->prev_ = first_;
    head_->next_ = end_;
    first_->next_ = head_;
    end_->prev_ = head_;
  } else {
    Node *last = end_->prev_;
    elemNew->prev_ = last;
    elemNew->next_ = end_;
    last->next_ = elemNew;
    end_->prev_ = elemNew;
  }
}

template <typename T>
void List<T>::PushBack(const_reference value) {
  if (first_ == nullptr) {
    this->InitList();
  }
  Node *elemNew = new Node;
  elemNew->value_ = value;
  if (head_ == nullptr) {
    head_ = elemNew;
    head_->prev_ = first_;
    head_->next_ = end_;
    first_->next_ = head_;
    end_->prev_ = head_;
  } else {
    Node *last = end_->prev_;
    elemNew->prev_ = last;
    elemNew->next_ = end_;
    last->next_ = elemNew;
    end_->prev_ = elemNew;
  }
}

template <typename T>
void List<T>::PushFront(const_reference value) {
  if (first_ == nullptr) {
    this->InitList();
  }
  Node *elemNew = new Node;
  elemNew->value_ = value;
  if (head_ == nullptr) {
    head_ = elemNew;
    head_->prev_ = first_;
    head_->next_ = end_;
    first_->next_ = head_;
    end_->prev_ = head_;
  } else {
    elemNew->next_ = head_;
    elemNew->prev_ = first_;
    first_->next_ = elemNew;
    head_->prev_ = elemNew;
    head_ = elemNew;
  }
}

template <typename T>
bool List<T>::Empty() const {
  return head_ == nullptr ? true : false;
}

template <typename T>
typename List<T>::const_reference List<T>::Back() const {
  return this->Empty() ? end_->value_ : end_->prev_->value_;
}

template <typename T>
typename List<T>::const_reference List<T>::Front() const {
  return this->Empty() ? first_->value_ : head_->value_;
}

template <typename T>
void List<T>::Clear() {
  Node *ptr = first_;
  while (ptr != nullptr) {
    Node *del = ptr;
    ptr = ptr->next_;
    delete del;
  }
  head_ = nullptr;
  first_ = nullptr;
  end_ = nullptr;
  size_ = 0;
}

template <typename T>
template <class Type, class... Args>
void List<T>::Emplace(iterator iter, Type value, Args... args) {
  Insert(iter, value);
  Emplace(iter, args...);
}

template <typename T>
template <class Type, class... Args>
void List<T>::EmplaceBack(Type value, Args... args) {
  PushBack(value);
  EmplaceBack(args...);
}

template <typename T>
template <class Type, class... Args>
void List<T>::EmplaceFront(Type value, Args... args) {
  Emplace(this->begin(), value, args...);
}
