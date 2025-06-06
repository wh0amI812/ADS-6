// Copyright 2022 NNTU-CS
// include/tpqueue.h
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept> 

struct SYM {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
  struct Node {
    T data;
    Node* next;

    Node(const T& data, Node* next) : data(data), next(next) {} 
  };

  Node* head;

 public:
  TPQueue() : head(nullptr) {}

  ~TPQueue() {
    Node* current = head;
    while (current != nullptr) {
      Node* next = current->next;
      delete current;
      current = next;
    }
    head = nullptr; 
  }

  void push(const T& value) {
    if (value.prior < 1 || value.prior > 10) {
      throw std::invalid_argument("Приоритет должен быть в диапазоне от 1 до 10.");
    }

    Node* newNode = new Node(value, nullptr); 

    if (!head) {
      head = newNode;
      return;
    }

    if (value.prior > head->data.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }

    Node* current = head;
    while (current->next && value.prior <= current->next->data.prior) {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }


  T pop() {
    if (!head) {
      throw std::runtime_error("");
    }

    Node* temp = head;
    head = head->next;
    T value = temp->data;
    delete temp;
    return value;
  }

  bool isEmpty() const {
    return head == nullptr;
  }
};

#endif  // INCLUDE_TPQUEUE_H_
