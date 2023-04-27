#include <iostream>

class MyClass {
public:
  MyClass() {
    std::cout << "ctor\n";
  }

  MyClass(const MyClass & other) {
    std::cout << "copy ctor\n";
  }

  ~MyClass() {
    //std::cout << "dtor\n";
  }
};

// RVO, NRVO
MyClass foo(MyClass thing) {
  std::cout << "foo\n";
  return thing;
}

// RVO
MyClass bar() {
  return MyClass{};
}

// NRVO
MyClass bar2() {
  MyClass thing{};
  return thing;
}

int main() {
  MyClass mything{};
  MyClass anotherthing{foo(mything)};
  MyClass yat = bar();
  MyClass yat2 = bar2();
}