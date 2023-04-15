#include <gtest/gtest.h>
#include "../src/Stack + Queue + list/queue.h"
#include <queue>
using namespace Study;

Queue<int> myqueue;
int k = 5;

TEST(Queue_Empty, test1) { ASSERT_EQ(true, myqueue.Empty()); }

TEST(Queue_Size, test1) { ASSERT_EQ(0, myqueue.Size()); }

TEST(Queue_Construct, test2) {
  Queue<int> myqueue({2, 456, 8});
  std::queue<int> queue;
  queue.push(2);
  queue.push(456);
  queue.push(8);
  ASSERT_TRUE(myqueue.Size() == queue.size());
  ASSERT_TRUE(myqueue.Back() == queue.back());
  ASSERT_TRUE(myqueue.Front() == queue.front());
}

TEST(Queue_push, test1) {
  myqueue.Push(k);

  ASSERT_EQ(k, myqueue.Back());
  k = 6;
  myqueue.Push(k);

  ASSERT_EQ(k, myqueue.Back());

  myqueue.Back() = 11;
  ASSERT_EQ(11, myqueue.Back());

  int &c = myqueue.Back();
  c = 3;

  ASSERT_EQ(c, myqueue.Back());
  ASSERT_EQ(5, myqueue.Front());

  myqueue.Front() = 11;
  ASSERT_EQ(11, myqueue.Front());

  int &d = myqueue.Front();
  d = 4;

  ASSERT_EQ(d, myqueue.Front());
}

TEST(Queue_pop, test1) {
  myqueue.Push(k);
  ASSERT_EQ(6, myqueue.Back());
  ASSERT_EQ(3, myqueue.Size());
  myqueue.Pop();
  ASSERT_EQ(6, myqueue.Back());
  ASSERT_EQ(2, myqueue.Size());
  ASSERT_EQ(0, myqueue.Front());
}

TEST(Malloc, test1) {
  k = 4;
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);

  ASSERT_EQ(false, myqueue.Empty());
  ASSERT_EQ(8, myqueue.Size());
}

TEST(Queue_swap, test1) {
  Queue<int> myqueue1;
  myqueue1.Swap(myqueue);

  ASSERT_EQ(false, myqueue1.Empty());
  ASSERT_EQ(8, myqueue1.Size());
  ASSERT_EQ(4, myqueue1.Back());
  ASSERT_EQ(true, myqueue.Empty());
  ASSERT_EQ(0, myqueue.Size());
}

TEST(Queue_move, test1) {
  k = 4;
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);
  myqueue.Push(k);

  Queue<int> myqueue1;
  myqueue1.Swap(myqueue);

  Queue<int> myqueue2(std::move(myqueue1));

  ASSERT_EQ(false, myqueue2.Empty());
  ASSERT_EQ(7, myqueue2.Size());
  ASSERT_EQ(4, myqueue2.Back());
  ASSERT_EQ(true, myqueue1.Empty());
  ASSERT_EQ(0, myqueue1.Size());

  Queue<int> myqueue4(myqueue2);

  ASSERT_EQ(false, myqueue4.Empty());
  ASSERT_EQ(7, myqueue4.Size());
}

TEST(Queue_init, test1) {
  Queue<int> myqueueInit({1, 2, 4, 5});
  ASSERT_EQ(false, myqueueInit.Empty());
  ASSERT_EQ(4, myqueueInit.Size());
  ASSERT_EQ(5, myqueueInit.Back());
  ASSERT_EQ(1, myqueueInit.Front());
}

TEST(Queue_Emplace, test1) {
  Queue<int> myqueueBad({});
  ASSERT_EQ(true, myqueueBad.Empty());
  ASSERT_EQ(0, myqueueBad.Size());

  myqueueBad.EmplaceBack(6, 4, 3, 2);

  ASSERT_EQ(2, myqueueBad.Back());
  ASSERT_EQ(6, myqueueBad.Front());
}

TEST(Queue_operator, test1) {
  Queue<int> myqueueInit({1, 2, 4, 5});
  Queue<int> Moved(std::move(myqueueInit));

  ASSERT_EQ(false, Moved.Empty());
  ASSERT_EQ(4, Moved.Size());
  ASSERT_EQ(5, Moved.Back());
  ASSERT_EQ(1, Moved.Front());
}
