#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#include "queue_stack.h"

namespace Study {
template <typename Type>
class Queue : public QueueStack<Type> {
  using QueueStack<Type>::QueueStack;

 public:
  typename QueueStack<Type>::reference Front() {
    if (QueueStack<Type>::Empty()) {
      throw std::out_of_range("No such element");
    }
    return QueueStack<Type>::GetStore(0);
  }

  typename QueueStack<Type>::reference Back() {
    if (QueueStack<Type>::Empty()) {
      throw std::out_of_range("No such element");
    }
    return QueueStack<Type>::GetStore(QueueStack<Type>::GetPosition());
  }

  void EmplaceBack() {}
  template <class T, class... Args>
  void EmplaceBack(T data, Args... args) {
    QueueStack<Type>::Push(data);
    EmplaceBack(args...);
  }

  void Pop() {
    if (QueueStack<Type>::Empty()) {
      throw std::out_of_range("No such element");
    }
    Front() = 0;
    QueueStack<Type>::DecreasePosition();
    QueueStack<Type>::MoveStorePop(*this);
  }
};
}  // namespace Study

#endif  // SRC_QUEUE_H_