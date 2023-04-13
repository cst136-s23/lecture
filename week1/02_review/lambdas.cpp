#include <iostream>

/*
Fundamental Categories of Data
1. Scalars/atoms
2. Lists
3. Bags
4. Functions/lambdas
*/

template <typename F>
void forEach(int nums[], size_t len, F fn) {
  for (size_t i{}; i < len; ++i) {
    fn(nums[i]);
  }
}

int main() {
  size_t len{3};
  int xs[]{2, 4, 6};

  auto print = [=](int num) {
    std::cout << len << ':' << num << '\n';
  };

  forEach(xs, len, print);
}
