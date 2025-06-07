// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <stdexcept>
template<typename T>
class TPQueue {
 private:
    struct Knot {
        T data;
        Knot* next;
        explicit Knot(const T& d) : data(d), next(nullptr) {}
    };
    Knot* head;

 public:
    TPQueue() : head(nullptr) {}
    ~TPQueue() {
        while (head) {
            Knot* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void push(const T& item) {
        Knot* newKnot = new Knot(item);
        if (!head || head->data.prior < item.prior) {
            newKnot->next = head;
            head = newKnot;
            return;
        }
        Knot* current = head;
        while (current->next && current->next->data.prior >= item.prior) {
            current = current->next;
        }
        newKnot->next = current->next;
        current->next = newKnot;
    }

    T pop() {
        if (!head) {
            throw std::runtime_error("Queue is empty");
        }
        Knot* tmp = head;
        T result = head->data;
        head = head->next;
        delete tmp;
        return result;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
