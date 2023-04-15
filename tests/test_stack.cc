#include <gtest/gtest.h>
#include "../src/Stack + Queue + list/stack.h"
#include <stack>
using namespace Study;

Stack<int> myStack;

TEST(Stack_Empty, test1) { ASSERT_EQ(true, myStack.Empty()); }

TEST(Stack_Size, test1) { ASSERT_EQ(0, myStack.Size()); }

TEST(Stack_push, test1) {
  int k = 6;
  myStack.Push(k);
  ASSERT_EQ(k, myStack.Top());
  
  myStack.Push(k);
  ASSERT_EQ(k, myStack.Top());

  myStack.Top() = 11;
  ASSERT_EQ(11, myStack.Top());

  int &c = myStack.Top();
  c = 3;

  ASSERT_EQ(c, myStack.Top());

  myStack.Pop();
  ASSERT_EQ(6, myStack.Top());
}

TEST(Stack_malloc, test1) {
  int k = 3;
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);

  ASSERT_EQ(false, myStack.Empty());
  ASSERT_EQ(7, myStack.Size()); // Размер 7, пушей 6

  Stack<int> myStack1;
  myStack1.Swap(myStack);

  ASSERT_EQ(false, myStack1.Empty());
  ASSERT_EQ(7, myStack1.Size()); // То же самое
  ASSERT_EQ(3, myStack1.Top());
  ASSERT_EQ(true, myStack.Empty());
  ASSERT_EQ(0, myStack.Size());
}

TEST(Stack_size, test2) {
  int k = 3;
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  Stack<int> myStack1;
  myStack1.Swap(myStack);
  Stack<int> myStack2(std::move(myStack1));

  ASSERT_EQ(false, myStack2.Empty());
  ASSERT_EQ(7, myStack2.Size());
  ASSERT_EQ(3, myStack2.Top());
  ASSERT_EQ(true, myStack1.Empty());
  ASSERT_EQ(0, myStack1.Size());
}

TEST(Stack_size, test3) {
  int k = 3;
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  myStack.Push(k);
  Stack<int> myStack1;
  myStack1.Swap(myStack);
  Stack<int> myStack2(std::move(myStack1));
  Stack<int> myStack4(myStack2);

  ASSERT_EQ(false, myStack4.Empty());
  ASSERT_EQ(7, myStack4.Size());
  ASSERT_EQ(0, myStack4.Top());
}

TEST(stack_push_pop, test1) {
  int k = 5;
  Stack<int> myStack;
  std::stack<int> std_stack;
  myStack.Push(k);
  std_stack.push(k);
  ASSERT_TRUE(myStack.Top() == std_stack.top());
  myStack.Push(k);
  myStack.Pop();
  std_stack.push(k);
  std_stack.pop();
  ASSERT_TRUE(myStack.Top() == std_stack.top());
}

TEST(Stack_init, test1) {
  Stack<int> myStackInit({1, 5, 4, 3});
  ASSERT_EQ(false, myStackInit.Empty());
  ASSERT_EQ(4, myStackInit.Size());
  ASSERT_EQ(3, myStackInit.Top());

  Stack<int> myStackBad = {};
  ASSERT_EQ(true, myStackBad.Empty());
  ASSERT_EQ(0, myStackBad.Size());
}

TEST(Stack_operator, test1) {
  Stack<int> myStackInit({1, 5, 4, 3});
  Stack<int> moved(std::move(myStackInit));

  ASSERT_EQ(false, moved.Empty());
  ASSERT_EQ(4, moved.Size());
  ASSERT_EQ(3, moved.Top());

  moved.EmplaceFront(1, 6, 8, 1, 4);

  ASSERT_EQ(9, moved.Size());
  ASSERT_EQ(4, moved.Top());
}
