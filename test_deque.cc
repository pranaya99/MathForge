// Copyright 2025 Pranaya Rao Ganta
#include <gtest/gtest.h>
#include "./deque.h"

TEST(Deque, Empty)
{
  Deque<int> dq;
  EXPECT_TRUE(dq.Empty());
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_THROW(dq.pop_back(), std::out_of_range);
  EXPECT_THROW(dq.pop_front(), std::out_of_range);
}

TEST(Deque, push_backpop_back)
{
  Deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  EXPECT_EQ(dq.Size(), 2);
  dq.pop_back();
  EXPECT_EQ(dq.Size(), 1);
  EXPECT_EQ(dq.Back(), 1);
  dq.pop_back();
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_TRUE(dq.Empty());
}

TEST(Deque, push_frontpop_front)
{
  Deque<int> dq;
  dq.push_front(1);
  dq.push_front(2);
  EXPECT_EQ(dq.Size(), 2);
  dq.pop_front();
  EXPECT_EQ(dq.Size(), 1);
  EXPECT_EQ(dq.Front(), 1);
  dq.pop_front();
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_TRUE(dq.Empty());
}

TEST(Deque, IndexOperator)
{
  Deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_back(3);
  EXPECT_EQ(dq[0], 1);
  EXPECT_EQ(dq[1], 2);
  EXPECT_EQ(dq[2], 3);
  EXPECT_THROW(dq[3], std::out_of_range);
}
