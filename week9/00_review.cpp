// inheritance
// polymorphism (interface)
// encapsulation

class Base {
public:
  virtual void foo1() {};
  virtual void foo2() {};

protected:
  int x, y;
};

class Derived : public Base {

};

void forEach(Collection col, std::function<void(Item)> fn) {
  // loop over col
  // for a given item:
  fn(item);
}

int main() {
  int x{42};
  auto foo = [&](int val) {
    ++x;
    std::cout << "hi, " << x << '\n';
    return val * x;
  };

  foo(4);
}
