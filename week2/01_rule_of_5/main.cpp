#include <iostream>

#include "string.h"

int main() {
  String s{"bob"};
  String s2{std::move(s)};

  String s3{"hi"};
  s3 = std::move(s2);

  std::cout << s3 << '\n';
}
