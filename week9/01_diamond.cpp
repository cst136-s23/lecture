#include <iostream>

class Animal {
public:
  virtual ~Animal() = default;

  virtual void speak() {
    std::cout << "I am an Animal\n";
  }
};

class Cat : virtual public Animal {
public:
  virtual void meow() {
    std::cout << "I am an Cat\n";
  }
};

class Dog : virtual public Animal {
public:
  virtual void woof() {
    std::cout << "I am an Dog\n";
  }
};

class Catdog : public Cat, public Dog {
public:

};

void foo(Cat & cat) {

}

void foo2(Dog & dog) {

}

int main() {
  Dog dog;

  Catdog catdog;
  catdog.speak();
  catdog.meow();
  catdog.woof();
  foo(catdog);
  foo2(catdog);
}
