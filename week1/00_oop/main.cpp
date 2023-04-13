#include <iostream>

/*
1. Scalars
2. Lists
3. Bags
4. Functions
*/

struct Animal {
  virtual void speak() = 0;
  virtual ~Animal() {}
};

struct Dog : public Animal {
  void speak() {
    std::cout << "woof woof\n";
  }
};

struct Cat : public Animal {
  void speak() {
    std::cout << "meow meow\n";
  }
};

void speak(Animal * animal) {
  animal->speak();
}

Animal * makeDog() {
  return new Dog{};
}

int main() {
  Animal * animal1 = makeDog();
  speak(animal1);

  delete animal1;

  Cat cat{};
  speak(&cat);
}
