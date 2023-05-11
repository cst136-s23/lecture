#include <iostream>

class Fruit {
public:
  Fruit() {
    p = new int{42};
  }

  virtual ~Fruit() {}

  virtual void doStuff() {

  }

private:
  int * p;
};

class Apple : public Fruit {
public:
  Apple() {
    p2 = new int{42};
  }

  ~Apple() {
    delete p2;
  }

  void doStuff() override {

  }

private:
  int * p2;
};

int main() {
  Fruit f;
  Apple apple;

  Fruit & f = apple;
}