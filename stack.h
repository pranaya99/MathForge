#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
 private:
  std::vector<T> data;

 public:
  void Push(T value) { data.push_back(value); }

  T Pop() {
    if (IsEmpty()) {
      throw std::out_of_range("Stack is empty");
    }
    T value = data.back();
    data.pop_back();
    return value;
  }

  bool IsEmpty() const { return data.empty(); }

  size_t Size() const { return data.size(); }
};

#endif  // STACK_H
