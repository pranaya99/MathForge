#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>
#include <vector>

class Deque {
 private:
  std::vector<int> data;
  size_t head = 0;
  size_t tail = 0;
  size_t capacity = 0;
  size_t size = 0;

  void Resize() {
    size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
    std::vector<int> new_data(new_capacity);
    for (size_t i = 0; i < size; ++i) {
      new_data[i] = data[(head + i) % capacity];
    }
    data = new_data;
    head = 0;
    tail = size;
    capacity = new_capacity;
  }

 public:
  Deque() : capacity(0), size(0) {}

  void PushBack(int value) {
    if (size == capacity) {
      Resize();
    }
    data[tail] = value;
    tail = (tail + 1) % capacity;
    ++size;
  }

  void PushFront(int value) {
    if (size == capacity) {
      Resize();
    }
    head = (head == 0) ? capacity - 1 : head - 1;
    data[head] = value;
    ++size;
  }

  int PopBack() {
    if (size == 0) {
      throw std::out_of_range("Deque is empty");
    }
    tail = (tail == 0) ? capacity - 1 : tail - 1;
    int value = data[tail];
    --size;
    return value;
  }

  int PopFront() {
    if (size == 0) {
      throw std::out_of_range("Deque is empty");
    }
    int value = data[head];
    head = (head + 1) % capacity;
    --size;
    return value;
  }

  int& operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return data[(head + index) % capacity];
  }

  size_t Size() const { return size; }

  bool IsEmpty() const { return size == 0; }
};

#endif  // DEQUE_H
