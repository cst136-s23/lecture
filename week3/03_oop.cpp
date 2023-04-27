#include <iostream>
#include <vector>

namespace yeet {
  void foo() {
    std::cout << "foo from yeet\n";
  }
};

namespace jeter {
  void foo() {
    std::cout << "foo from jeter\n";
  }
};

class Base {
protected:
  float x, y;

public:
  virtual void foo() {
    std::cout << "i am base\n";
  }
};

class Derived : public Base {
private:
  float z;

public:
  Derived() {
    x = 42;
  }

  void foo() override {
    std::cout << "i am derived\n";
    Base::foo();
  }
};

int main() {
  Base base{};
  base.foo();

  Derived d{};
  d.foo();

  Base & another = d;
  another.foo();

  yeet::foo();
  jeter::foo();

  std::vector<Base> items{};
  items.push_back(base);
  items.push_back(d); // Object slicing!!

  std::vector<Base *> items2{};
  items2.push_back(new Base{});
  items2.push_back(new Derived{});

  for (size_t i{}; i < items2.size(); ++i) {
    delete items2[i];
  }
}
