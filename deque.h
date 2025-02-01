// Copyright 2025 Pranaya Rao Ganta
#ifndef DEQUE_H_
#define DEQUE_H_

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
 public:
  // Constructor
  Deque();

  // Destructor
  ~Deque() = default;

  // Capacity
  bool Empty() const noexcept;
  size_t Size() const noexcept;
  // Resize internal data structure to fit precisely the number of items
  void ShrinkToFit();
  // Element access
  T& operator[](size_t pos);
  T& Front();
  T& Back();
  // Modifiers
  void Clear() noexcept;
  void push_front(const T& value);
  void push_back(const T& value);
  void pop_front();
  void pop_back();
 private:
  std::vector<T> data;
  size_t  capacity;
  size_t size;
  size_t head;
  size_t tail;
  void Resize();
};
template <typename T>
Deque<T>::Deque() : capacity(0), size(0), head(0), tail(0) {}
template <typename T>
bool Deque<T>::Empty() const noexcept {
  return size == 0;
}
template <typename T>
size_t Deque<T>::Size() const noexcept {
  return size;
}
template <typename T>
void Deque<T>::ShrinkToFit() {
  if (size== 0) {
     data.clear();
    capacity= 0;
     head = tail = 0;
  } else if (size<  capacity) {
    std::vector<T> new_data(size);
    for (size_t i = 0; i < size; ++i) {
      new_data[i] =  data[(head+ i) % capacity];
    }
    data = new_data;
     capacity = size;
    head= 0;
    tail= size;
  }
}
template <typename T>
T& Deque<T>::operator[](size_t pos) {
  if (pos >= size) {
    throw std::out_of_range("Index out of range");
  }
  return  data[(head + pos) % capacity];
}
template <typename T>
T& Deque<T>::Front() {
  if (Empty()) {
    throw std::out_of_range("Deque is empty");
  }
  return data[head];
}
template <typename T>
T& Deque<T>::Back() {
  if (Empty()) {
    throw std::out_of_range("Deque is empty");
  }
  return  data[(tail== 0 ? capacity- 1 : tail- 1)];
}

template <typename T>
void Deque<T>::Clear() noexcept {
  data.clear();
   capacity = size =  head = tail = 0;
}

template <typename T>
void Deque<T>::push_front(const T& value) {
  if (size==  capacity) {
    Resize();
  }
   head = ( head == 0 ?  capacity - 1 :  head - 1);
   data[ head] = value;
  ++size;
}

template <typename T>
void Deque<T>::push_back(const T& value) {
  if (size ==  capacity) {
    Resize();
  }
   data[ tail] = value;
   tail = ( tail + 1) %  capacity;
  ++size;
}

template <typename T>
void Deque<T>::pop_front() {
  if (Empty()) {
    throw std::underflow_error("Deque is empty, cannot pop from front");
  }
   head = ( head + 1) %  capacity;
  --size;
}

template <typename T>
void Deque<T>::pop_back() {
  if (Empty()) {
    throw std::underflow_error("Deque is empty, cannot pop from back");
  }
   tail = ( tail == 0 ?  capacity - 1 :  tail - 1);
  --size;
}

template <typename T>
void Deque<T>::Resize() {
  size_t new_capacity = ( capacity == 0) ? 1 :  capacity * 2;
  std::vector<T> new_data(new_capacity);
  for (size_t i = 0; i < size; ++i) {
    new_data[i] =  data[( head + i) %  capacity];
  }
   data = new_data;
   capacity = new_capacity;
   head = 0;
   tail = size;
}

#endif 
