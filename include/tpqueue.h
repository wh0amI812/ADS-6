// Copyright 2022 NNTU-CS
// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& value) : data(value), next(nullptr) { }
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (head != nullptr) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
  }
  void push(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr || value.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }
    Node* current = head;
    while (current->next != nullptr
      && current->next->data.prior >= value.prior) {
      current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
  T pop() {
    if (head == nullptr) {
      throw std::runtime_error("Queue is empty");
    }
    Node* temp = head;
    T value = head->data;
    head = head->next;
    delete temp;
    return value;
  }
  bool empty() const {
    return head == nullptr;
  }
  TPQueue(const TPQueue&) = delete;
  TPQueue& operator=(const TPQueue&) = delete;
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
