#include <iostream>

template <typename F>
void foo(F fn) {
  std::cout << fn() << '\n';
}

int main() {
  int x{};

  auto inc = [&]() {
    ++x;
    return x;
  };

  foo(inc);

  auto add = [](auto initial) {
    return [&](auto value) {
      return [=]() {
        return initial + value;
      };
    };
  };

  auto add42 = add(42);
  auto myadd = add42(3);
  foo(myadd);
}