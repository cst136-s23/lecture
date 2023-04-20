#include <iostream>

void print(int & x) {
  std::cout << "lvalue: " << x << '\n';
}

void print(int && x) {
  std::cout << "rvalue: " << x << '\n';
}

int main() {
  int x{42};
  // int * p = &x;

  int & y = x;
  ++x;
  ++y;
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';

  const int & z = x;
  x += 1000;
  std::cout << "z: " << z << '\n';
  // z++;

  int && w = 42;
  print(x); // passed as lvalue
  print(w); // passed as lvalue (confusingly)
  print(std::move(w)); // passed as rvalue
  print(27); // passed as rvalue
}