#include <iostream>

struct Base {
  void foo() { std::cout << "base\n"; }
};

struct Derived : public Base {
  void foo() { std::cout << "derived\n"; }
};

int main() {
  Derived d;
  d.foo(); // derived
  Base & b = d;
  b.foo(); // base
}
