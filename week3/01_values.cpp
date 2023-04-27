#include <iostream>

// rvalue = prvalue | xvalue
// lvalue = anything else

void print(int & x) {
  std::cout << "lvalue: " << x << '\n';
}

void print(int && x) {
  std::cout << "rvalue: " << x << '\n';
}

template <typename T>
void foo(T && arg) {
  std::cout << "foo: " << arg << '\n';
}

int main() {
  int x = 42;
  int && rx = 12;

  print(static_cast<int&&>(x));
  print(std::move(rx));
  print(1337);
  foo(x); // lvalue!!
}
