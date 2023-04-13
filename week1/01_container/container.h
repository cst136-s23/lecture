#pragma once

// Abstract Base Class aka Interface
template <typename T>
class Container {
public:
  virtual void append(const T &item) = 0;
  virtual void print() = 0;
};
