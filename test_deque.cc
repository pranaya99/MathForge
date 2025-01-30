// Copyright 2025 Pranaya Rao Ganta
#include <gtest/gtest.h>
#include "./deque.h"

TEST(Deque, Empty) {
  Deque<int> dq;
  EXPECT_TRUE(dq.Empty());
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_THROW(dq.PopBack(), std::out_of_range);
  EXPECT_THROW(dq.PopFront(), std::out_of_range);
}

TEST(Deque, PushBackPopBack) {
  Deque<int> dq;
  dq.PushBack(1);
  dq.PushBack(2);
  EXPECT_EQ(dq.Size(), 2);

  dq.PopBack();  // Just call PopBack
  EXPECT_EQ(dq.Size(), 1);  // Check the size after PopBack
  EXPECT_EQ(dq.Back(), 1);  // Check the remaining element
  dq.PopBack();  // Just call PopBack
  EXPECT_EQ(dq.Size(), 0);  // Check if the deque is empty now
  EXPECT_TRUE(dq.Empty());  // Check if the deque is empty
}

TEST(Deque, PushFrontPopFront) {
  Deque<int> dq;
  dq.PushFront(1);
  dq.PushFront(2);
  EXPECT_EQ(dq.Size(), 2);

  dq.PopFront();  // Just call PopFront
  EXPECT_EQ(dq.Size(), 1);  // Check the size after PopFront
  EXPECT_EQ(dq.Front(), 1);  // Check the remaining element
  dq.PopFront();  // Just call PopFront
  EXPECT_EQ(dq.Size(), 0);  // Check if the deque is empty now
  EXPECT_TRUE(dq.Empty());  // Check if the deque is empty
}

TEST(Deque, IndexOperator) {
  Deque<int> dq;
  dq.PushBack(1);
  dq.PushBack(2);
  dq.PushBack(3);
  EXPECT_EQ(dq[0], 1);
  EXPECT_EQ(dq[1], 2);
  EXPECT_EQ(dq[2], 3);
  EXPECT_THROW(dq[3], std::out_of_range);
}
