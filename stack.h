// Copyright 2025 Pranaya Rao Ganta
#ifndef STACK_H_
#define STACK_H_

#include <stdexcept>
#include <vector>

template <typename T>
class Stack
{
private:
  std::vector<T> data;

public:
  void Push(T val) { data.push_back(val); }

  T Pop()
  {
    if (IsEmpty())
    {
      throw std::out_of_range("Stack is empty");
    }
    T val = data.back();
    data.pop_back();
    return val;
  }
  bool IsEmpty() const { return data.empty(); }
  size_t Size() const { return data.size(); }
};
#endif
