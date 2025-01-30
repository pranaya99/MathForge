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
  void PushFront(const T& value);
  void PushBack(const T& value);
  void PopFront();
  void PopBack();

 private:
  std::vector<T> data_;
  size_t capacity_;
  size_t size_;
  size_t head_;
  size_t tail_;

  void Resize();
};

template <typename T>
Deque<T>::Deque() : capacity_(0), size_(0), head_(0), tail_(0) {}

template <typename T>
bool Deque<T>::Empty() const noexcept {
  return size_ == 0;
}

template <typename T>
size_t Deque<T>::Size() const noexcept {
  return size_;
}

template <typename T>
void Deque<T>::ShrinkToFit() {
  if (size_ == 0) {
    data_.clear();
    capacity_ = 0;
    head_ = tail_ = 0;
  } else if (size_ < capacity_) {
    std::vector<T> new_data(size_);
    for (size_t i = 0; i < size_; ++i) {
      new_data[i] = data_[(head_ + i) % capacity_];
    }
    data_ = new_data;
    capacity_ = size_;
    head_ = 0;
    tail_ = size_;
  }
}

template <typename T>
T& Deque<T>::operator[](size_t pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[(head_ + pos) % capacity_];
}

template <typename T>
T& Deque<T>::Front() {
  if (Empty()) {
    throw std::out_of_range("Deque is empty");
  }
  return data_[head_];
}

template <typename T>
T& Deque<T>::Back() {
  if (Empty()) {
    throw std::out_of_range("Deque is empty");
  }
  return data_[(tail_ == 0 ? capacity_ - 1 : tail_ - 1)];
}

template <typename T>
void Deque<T>::Clear() noexcept {
  data_.clear();
  capacity_ = size_ = head_ = tail_ = 0;
}

template <typename T>
void Deque<T>::PushFront(const T& value) {
  if (size_ == capacity_) {
    Resize();
  }
  head_ = (head_ == 0 ? capacity_ - 1 : head_ - 1);
  data_[head_] = value;
  ++size_;
}

template <typename T>
void Deque<T>::PushBack(const T& value) {
  if (size_ == capacity_) {
    Resize();
  }
  data_[tail_] = value;
  tail_ = (tail_ + 1) % capacity_;
  ++size_;
}

template <typename T>
void Deque<T>::PopFront() {
  if (Empty()) {
    throw std::underflow_error("Deque is empty, cannot pop from front");
  }
  head_ = (head_ + 1) % capacity_;
  --size_;
}

template <typename T>
void Deque<T>::PopBack() {
  if (Empty()) {
    throw std::underflow_error("Deque is empty, cannot pop from back");
  }
  tail_ = (tail_ == 0 ? capacity_ - 1 : tail_ - 1);
  --size_;
}

template <typename T>
void Deque<T>::Resize() {
  size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
  std::vector<T> new_data(new_capacity);
  for (size_t i = 0; i < size_; ++i) {
    new_data[i] = data_[(head_ + i) % capacity_];
  }
  data_ = new_data;
  capacity_ = new_capacity;
  head_ = 0;
  tail_ = size_;
}

#endif  // DEQUE_H_
