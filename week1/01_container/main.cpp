#include <iostream>
#include "container.h"
#include "vector.h"
#include "list.h"

template <typename T>
void print(Container<T> & container) {
  container.print();
}

int main() {
  Vector<int> v{};
  // append(v, 42);

  v.append(42);
  print(v);

  List<int> l{};

  l.append(1337);
  print(l);
}
