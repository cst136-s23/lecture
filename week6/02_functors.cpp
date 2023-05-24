#include <iostream>

// "functor", Function Object
struct _foo {
  int & _x;

  _foo(int & x) : _x(x) {}

  void operator()(int val) {
    std::cout << "foo\n" << val;
  }
};

int main() {
  int x{42};
  auto foo = [&](int y) {
    x += y;
    std::cout << x << '\n';
  };

  foo(2);

  _foo f{x};
  f(2);
}
