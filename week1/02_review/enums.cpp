#include <iostream>

enum Stuff {
  thing1,
  thing2,
  thing3
};

int main() {
  int nums[]{2, 4, 6};

  nums[Stuff::thing1] = 42;
  nums[Stuff::thing2] = 37;
}
