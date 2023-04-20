#include <iostream>

class Animal {
public:
  virtual void speak() {
    std::cout << "I am an animal!\n";
  }
};

class Dog : public Animal {
public:
  void speak() override {
    std::cout << "woof woof!\n";
  }
};

class Pug : public Dog {
public:
  void speak() override {
    std::cout << "zzz...\n";
  }
};

void algo(Animal & animal) {
  animal.speak();
}

int main() {
  Animal animal{};
  algo(animal);

  Dog dog{};
  algo(dog);

  Pug pug{};
  algo(pug);

  Animal & a = pug;
  a.speak();
}