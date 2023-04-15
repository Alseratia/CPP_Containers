#ifndef SRC_QUEUESTACK_H_
#define SRC_QUEUESTACK_H_
//#include <initializer_list>
//#include <iostream>
#include <memory>

namespace Study {
template <typename Type>
class QueueStack {
 public:
  typedef std::size_t size_type;
  typedef Type value_type;
  typedef Type &reference;
  typedef Type &const_reference;

  QueueStack() {}

  explicit QueueStack(std::initializer_list<value_type> const &items) {
    Position = items.size() - 1;
    Store.reset(new Type[items.size()]{});
    auto iter{items.begin()};
    for (int i{0}; iter != items.end(); i++, iter++) {
      GetStore(i) = *iter;
    }
  }

  QueueStack(const QueueStack &old) {
    Position = old.Position;
    MoveStorePush(old);
  }

  QueueStack(QueueStack &&old) {
    Position = old.Position;
    Store.swap(old.Store);
    old.Position = -1;
  }

  ~QueueStack() {}

  void Push(const Type &value);
  bool Empty() const;
  void Swap(QueueStack &other);

  QueueStack &operator=(QueueStack &&old);

  size_type Size() const { return Position + 1; }

 protected:
  Type &GetStore(int pos) { return Store[pos]; };
  int GetPosition() { return Position; }
  void DecreasePosition() { Position -= 1; }
  void MoveStorePush(const QueueStack &old);
  void MoveStorePop(const QueueStack &old);

 private:
  int Position{-1};
  std::unique_ptr<Type[]> Store{new Type[1]{}};
};

template <typename Type>
typename QueueStack<Type>::QueueStack &QueueStack<Type>::operator=(
    QueueStack &&old) {
  Position = old.Position;
  MoveStorePush(old);
  return *this;
}

template <typename Type>
void QueueStack<Type>::Swap(QueueStack &other) {
  std::swap(Position, other.Position);
  Store.swap(other.Store);
}

template <typename Type>
void QueueStack<Type>::Push(const Type &value) {
  Position += 1;
  MoveStorePush(*this);
  Store[Position] = value;
}

template <typename Type>
bool QueueStack<Type>::Empty() const {
  bool result = false;
  if (Position < 0) {
    result = true;
  }
  return result;
}

template <typename Type>
void QueueStack<Type>::MoveStorePush(const QueueStack &old) {
  std::unique_ptr<Type[]> store{new Type[Position + 1]{}};
  for (int i{0}; i < Position; i++) {
    store[i] = old.Store[i];
  }
  Store = std::move(store);
}

template <typename Type>
void QueueStack<Type>::MoveStorePop(const QueueStack &old) {
  std::unique_ptr<Type[]> store{new Type[Position + 1]{}};
  for (int i{Position}, j{Position + 1}; i > 0; i--, j--) {
    store[i] = old.Store[j];
  }
  Store = std::move(store);
}
}  // namespace Study

#endif  // SRC_QUEUESTACK_H_
