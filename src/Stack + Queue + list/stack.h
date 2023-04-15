#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include "queue_stack.h"

namespace Study {
template <typename Type>
class Stack : public QueueStack<Type> {
  using QueueStack<Type>::QueueStack;

 public:
  void Pop() {
    if (QueueStack<Type>::Empty()) {
      throw std::out_of_range("No such element");
    }
    Top() = 0;
    QueueStack<Type>::DecreasePosition();
  }

  typename QueueStack<Type>::reference Top() {
    if (QueueStack<Type>::Empty()) {
      throw std::out_of_range("No such element");
    }
    return QueueStack<Type>::GetStore(QueueStack<Type>::GetPosition());
  }

  void EmplaceFront() {}
  template <class T, class... Args>
  void EmplaceFront(T data, Args... args) {
    QueueStack<Type>::Push(data);
    EmplaceFront(args...);
  }
};
}  // namespace Study

#endif  // SRC_STACK_H_