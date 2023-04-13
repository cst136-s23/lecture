#pragma once

#include "container.h"
#include <iostream>

template <typename T>
struct Node {
  T data;
  Node * next;
};

template <typename T>
class List : public Container<T> {
public:
  List() = default;

  ~List() {
    Node<T> * cur{head};
    while (cur) {
      Node<T> * temp = cur;
      cur = temp->next;
      delete temp;
    }

    head = nullptr;
    tail = nullptr;
    len = 0;
  }

  List(const List<T> & other) {
    Node<T> * cur = other.head;
    while (cur) {
      append(cur->data);
      cur = cur->next;
      ++len;
    }
  }

  List<T> & operator=(const List<T> & other) {
    if (this == &other) {
      return *this;
    }

    Node<T> * cur{head};
    while (cur) {
      Node<T> * temp = cur;
      cur = temp->next;
      delete temp;
    }

    head = nullptr;
    tail = nullptr;
    len = 0;

    cur = other.head;
    while (cur) {
      append(cur->data);
      cur = cur->next;
      ++len;
    }

    return *this;
  }

  void append(const T & item) override {
    Node<T> * node = new Node<T>{item};
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
    ++len;
  }

  template <typename F>
  void remove_if(F fn) {
    // loop through here, and remove the item, if fn(cur->data)
  }

  void print() override {
    Node<T> * cur = head;
    while (cur) {
      std::cout << cur->data << '\n';
      cur = cur->next;
    }
  }

private:
  Node<T> * head{};
  Node<T> * tail{};
  size_t len{};
};
