#include <gtest/gtest.h>
#include "deque.h"

TEST(Deque, Empty) {
  Deque dq;
  EXPECT_TRUE(dq.IsEmpty());
  EXPECT_EQ(dq.Size(), 0);
  EXPECT_THROW(dq.PopBack(), std::out_of_range);
  EXPECT_THROW(dq.PopFront(), std::out_of_range);
}

TEST(Deque, PushBackPopBack) {
  Deque dq;
  dq.PushBack(1);
  dq.PushBack(2);
  EXPECT_EQ(dq.Size(), 2);
  EXPECT_EQ(dq.PopBack(), 2);
  EXPECT_EQ(dq.PopBack(), 1);
  EXPECT_TRUE(dq.IsEmpty());
}

TEST(Deque, PushFrontPopFront) {
  Deque dq;
  dq.PushFront(1);
  dq.PushFront(2);
  EXPECT_EQ(dq.Size(), 2);
  EXPECT_EQ(dq.PopFront(), 2);
  EXPECT_EQ(dq.PopFront(), 1);
  EXPECT_TRUE(dq.IsEmpty());
}

TEST(Deque, IndexOperator) {
  Deque dq;
  dq.PushBack(1);
  dq.PushBack(2);
  dq.PushBack(3);
  EXPECT_EQ(dq[0], 1);
  EXPECT_EQ(dq[1], 2);
  EXPECT_EQ(dq[2], 3);
  EXPECT_THROW(dq[3], std::out_of_range);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
