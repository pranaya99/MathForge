#ifndef DEQUE_H_
#define DEQUE_H_

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
 public:
  // Constructor
  Deque() : capacity_(0), size_(0), head_(0), tail_(0) {}

  // Destructor
  ~Deque() = default;

  // Capacity
  bool Empty() const noexcept { return size_ == 0; }
  size_t Size() const noexcept { return size_; }

  // Resize internal data structure to fit precisely the number of items
  void ShrinkToFit() {
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

  // Element access
  T& operator[](size_t pos) {
    if (pos >= size_) {
      throw std::out_of_range("Index out of range");
    }
    return data_[(head_ + pos) % capacity_];
  }

  T& Front() {
    if (Empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return data_[head_];
  }

  T& Back() {
    if (Empty()) {
      throw std::out_of_range("Deque is empty");
    }
    return data_[(tail_ == 0 ? capacity_ - 1 : tail_ - 1)];
  }

  // Modifiers
  void Clear() noexcept {
    data_.clear();
    capacity_ = size_ = head_ = tail_ = 0;
  }

  void PushFront(const T& value) {
    if (size_ == capacity_) {
      Resize();
    }
    head_ = (head_ == 0 ? capacity_ - 1 : head_ - 1);
    data_[head_] = value;
    ++size_;
  }

  void PushBack(const T& value) {
    if (size_ == capacity_) {
      Resize();
    }
    data_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
  }

  void PopFront() {
    if (Empty()) {
      throw std::out_of_range("Deque is empty");
    }
    head_ = (head_ + 1) % capacity_;
    --size_;
  }

  void PopBack() {
    if (Empty()) {
      throw std::out_of_range("Deque is empty");
    }
    tail_ = (tail_ == 0 ? capacity_ - 1 : tail_ - 1);
    --size_;
  }

 private:
  std::vector<T> data_;
  size_t capacity_;
  size_t size_;
  size_t head_;
  size_t tail_;

  void Resize() {
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
};

#endif  // DEQUE_H_