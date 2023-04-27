#include <iostream>

class Base {
private:
  float x;

protected:
  float y;

public:
  float z;

  float getX() {
    return x;
  }

  void setX(float newX) {
    x = newX;
  }
};

class Derived : public Base {
public:
  void foo() {
    std::cout /* << x */ << y << z << '\n';
  }
};

int main() {
  Derived d{};
  d.z;
}