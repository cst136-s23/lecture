#include <iostream>

namespace yeet {

int x{42};

};

//using namespace yeet;

int main() {
  int x{1337};

  std::cout << yeet::x << '\n';
}
