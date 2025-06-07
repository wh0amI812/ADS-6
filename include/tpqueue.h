// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>

template<typename T>
class TPQueue {
 private:
  struct Item {
    T element;
    Item* following;
    explicit Item(const T& value) : element(value), following(nullptr) {}
  };
  Item* front;

 public:
  TPQueue() : front(nullptr) {}
  ~TPQueue() {
    while (front != nullptr) {
      Item* tmp = front;
      front = front->following;
      delete tmp;
    }
  }
  void push(const T& value) {
    Item* newItem = new Item(value);
    if (front == nullptr || value.prior > front->element.prior) {
      newItem->following = front;
      front = newItem;
      return;
    }
    Item* current = front;
    while (current->following != nullptr
           && current->following->element.prior >= value.prior) {
      current = current->following;
    }
    newItem->following = current->following;
    current->following = newItem;
  }
  T pop() {
    if (front == nullptr) {
      throw std::runtime_error("Queue is empty");
    }
    Item* tmp = front;
    T value = front->element;
    front = front->following;
    delete tmp;
    return value;
  }
  bool empty() const {
    return front == nullptr;
  }
  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;
};

struct Symbol {
  char character;
  int priority;
};

#endif  // INCLUDE_TPQUEUE_H_
