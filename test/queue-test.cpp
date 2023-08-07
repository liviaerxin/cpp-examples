#include "queue.h"
// #include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(queueTest, testFullQueue) {
  my::Queue q(10);
  for (int i = 0; i < 10; i++) {
    q.enqueue(i);
  }
  try {
    q.enqueue(11);
  } catch (int e) {
    EXPECT_EQ(e, 10);
  }
}

TEST(queueTest, testEmptyQueue) {
  my::Queue q(10);

  try {
    auto item = q.dequeue();
  } catch (int e) {
    EXPECT_EQ(e, 20);
  }
}

TEST(queueTest, test1) {
  my::Queue q(10);
  int expected = 2;
  q.enqueue(expected);
  EXPECT_EQ(q.dequeue(), expected);
}

TEST(queueTest, testEnqueueDequeue) {
  my::Queue q(10);

  q.enqueue(2);
  q.enqueue(4);
  EXPECT_EQ(q.dequeue(), 2);
  q.enqueue(8);
  q.enqueue(16);
  q.enqueue(32);
  EXPECT_EQ(q.dequeue(), 4);
  EXPECT_EQ(q.dequeue(), 8);
  EXPECT_EQ(q.dequeue(), 16);
  EXPECT_EQ(q.dequeue(), 32);
  q.enqueue(64);
  EXPECT_EQ(q.dequeue(), 64);
}