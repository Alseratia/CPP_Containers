#ifndef SRC_LIST_H_
#define SRC_LIST_H_
#include <cstdint>
#include <stdexcept>

namespace Study {

template <typename T>
class List {
 public:
  class Listiterator;
  typedef Listiterator iterator;
  typedef const Listiterator const_iterator;

 private:
  typedef T value_type;
  typedef T &reference;
  typedef const T &const_reference;
  typedef std::size_t size_type;

  struct Node {
    value_type value_{};
    Node *next_ = nullptr;
    Node *prev_ = nullptr;
  };

  Node *first_ = nullptr;
  Node *end_ = nullptr;
  Node *head_ = nullptr;

  size_type size_ = 0;

  void InitList() {
    first_ = new Node;
    end_ = new Node;
    first_->next_ = end_;
    end_->prev_ = first_;
  }

 public:
  List() { this->InitList(); }
  explicit List(std::initializer_list<value_type> const &items);
  List(const List &other) { *this = other; }
  explicit List(size_type size);
  List(List &&other);
  ~List();

  List &operator=(const List &other);
  List &operator=(List &&other);

  iterator Insert(iterator pos, const_reference value);

  void Erase(iterator pos);
  void PopBack();
  void PopFront();
  void Swap(List &other);
  void Merge(List &other);
  void Splice(const_iterator pos, List &other);
  void Reverse();
  void Unique();
  void Sort();
  void PushBack();
  void PushBack(const_reference value);
  void PushFront(const_reference value);

  bool Empty() const;

  const_reference Back() const;
  const_reference Front() const;

  void Clear();

  size_type Size() const { return size_; }
  size_type MaxSize() const { return SIZE_MAX / sizeof(Node); }

  iterator begin() {
    iterator ret(head_, 0);
    return ret;
  }

  iterator end() {
    iterator ret(end_, size_);
    return ret;
  }

  void Emplace(iterator pos) {}
  template <class Type, class... Args>
  void Emplace(iterator iter, Type value, Args... args);

  void EmplaceBack() {}
  template <class Type, class... Args>
  void EmplaceBack(Type value, Args... args);

  void EmplaceFront() {}
  template <class Type, class... Args>
  void EmplaceFront(Type value, Args... args);

  class Listiterator {
   private:
    Node *ptr_ = nullptr;
    int pos_ = 0;

   public:
    Listiterator() {}
    Listiterator(Node *ptr, int pos) {
      ptr_ = ptr;
      pos_ = pos;
    }

    Listiterator(const_iterator &other) {
      ptr_ = other.ptr_;
      pos_ = other.pos_;
    }

    Listiterator &operator=(const_iterator other) {
      ptr_ = other.ptr_;
      pos_ = other.pos_;
      return *this;
    }

    bool operator!=(const_iterator other) {
      return ptr_ != other.ptr_ ? true : false;
    }

    bool operator==(const_iterator other) {
      return ptr_ == other.ptr_ ? true : false;
    }

    iterator operator++() {
      if (ptr_ == nullptr) {
        throw std::out_of_range("operator ++: iterator is nullptr");
      }
      ptr_ = ptr_->next_;
      pos_++;
      return *this;
    }

    iterator operator++(int ghost) {
      if (ptr_ == nullptr) {
        throw std::out_of_range("operator ++: iterator is nullptr");
      }
      ptr_ = ptr_->next_;
      pos_++;
      return *this;
    }

    iterator operator--() {
      if (ptr_ == nullptr) {
        throw std::out_of_range("operator --: iterator is nullptr");
      }
      ptr_ = this->ptr_->prev_;
      pos_--;
      return *this;
    }

    iterator operator--(int ghost) {
      if (ptr_ == nullptr) {
        throw std::out_of_range("operator --: iterator is nullptr");
      }
      ptr_ = this->ptr_->prev_;
      pos_--;
      return *this;
    }

    iterator operator-(int number) {
      iterator ret = *this;
      if (number < 0) {
        ret = *this - number;
      }
      for (int i = 0; i < number; i++) {
        if (ret.ptr_ == nullptr) {
          throw std::out_of_range("operator -: iterator is nullptr");
        }
        ret.ptr_ = this->ptr_->prev_;
        ret.pos_--;
      }
      return ret;
    }

    iterator operator+(int number) {
      iterator ret = *this;
      if (number < 0) {
        *this = *this - number;
      }
      for (int i = 0; i < number; i++) {
        if (ret.ptr_ == nullptr) {
          throw std::out_of_range("operator +: iterator is nullptr");
        }
        ret.ptr_ = ret.ptr_->next_;
        ret.pos_++;
      }
      return ret;
    }

    reference operator*() {
      if (ptr_ == nullptr) {
        throw std::out_of_range("operator *: iterator is nullptr");
      }
      return ptr_->value_;
    }

    Node *GetPointer() { return ptr_; }
  };
};
#include "list.inl"

}  // namespace Study
#endif  // SRC_LIST_H_