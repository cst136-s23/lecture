#include <iostream>

class Base {
public:
  virtual void foo() {
    std::cout << "i am base\n";
  }
};

class Derived : public Base {
public:
  void foo() override {
    std::cout << "i am derived\n";
  }

  void bar() {
    std::cout << "i am derived\n";
  }
};

int main() {
  Derived derived{};
  // ...
  Base * b = &derived;
  // ...
  Derived * d = dynamic_cast<Derived *>(b);
  if (d) {
    d->bar();
  }

  Base base{};
  Base & bref = base;

  try {
    Derived & dref = dynamic_cast<Derived &>(bref);
  } catch(std::bad_cast & e) {
    std::cout << e.what() << '\n';
  }
}
