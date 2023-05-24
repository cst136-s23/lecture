#include <iostream>
#include <vector>

int main() {
  int xs[]{2, 4, 6, 8};
  auto nums = {2, 4, 6, 8};
  std::initializer_list<int> items{2, 4, 6, 8};

  std::vector<int> points{2};

  for (auto item : {10, 20, 30}) {
    std::cout << item << '\n';
  }
}
