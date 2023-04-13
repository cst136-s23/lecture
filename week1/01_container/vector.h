#pragma once

#include "container.h"
#include <iostream>

template <typename T>
class Vector : public Container<T> {
public:
  Vector() = default;

  ~Vector() {
    delete[] items;
    items = nullptr;
    len = 0;
  }

  Vector(const Vector<T> & v) {
    for (size_t i{}; i < v.len; ++i) {
      append(v.items[i]);
    }
  }

  Vector<T> & operator=(const Vector<T> & v) {
    if (this == &v) {
      return *this;
    }

    delete[] items;
    for (size_t i{}; i < v.len; ++i) {
      append(v.items[i]);
    }

    return *this;
  }

  void append(const T & item) override {
    T * newItems = new T[len +1]{};

    for (size_t i{}; i < len; ++i) {
      newItems[i] = items[i];
    }
    newItems[len] = item;

    ++len;
    delete[] items;
    items = newItems;
  }

  void print() override {
    for (size_t i{}; i < len; ++i) {
      std::cout << items[i] << '\n';
    }
  }

private:
  size_t len{};
  T * items{};
};
