// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

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
  };

  Node* head;

 public:
  TPQueue();
  ~TPQueue();
  void push(const T& value);
  T pop();
  bool isEmpty() const;
};

#endif  
