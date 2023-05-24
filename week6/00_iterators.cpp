#include <iostream>

class Example {
private:
  int value;

public:
  Example(int value) : value{value} {}

  // the iterator class can be called anything
  // it's weird having a class inside of a class, right?
  class Bob {
  private:
    // the iterator can contain anything,
    // normally it has a reference to _something_,
    // but here I'm just storing a simple value
    // Note: because this is storing its _own_ data,
    //   it won't be referencing or modifying the Example class's data.
    //   But you could pass in the Example class itself as a reference!
    int value;

  public:
    // four things required *inside* of an iterator:
    //  1. must be able to create it (some kind of ctor)
    //  2. operator!=, so that it knows how to compare
    //  3. operator++, so that it can move to the next one
    //  4. operator*, to retreive the current value

    // two things are required *outside* of the iterator:
    //  1. a begin() that creates an iterator
    //  2. an end() that creates another of this kind of iterator

    // again, this could take anything we want (see begin() and end() below)
    Bob(int value) : value{value} {

    }

    bool operator!=(const Bob & other) {
      return value != other.value;
    }

    Bob & operator++() {
      ++value;
      return *this;
    }

    int & operator*() { // return by reference unless you want a copy to be returned
      return value;
    }
  };

  // this will be called to start the current iterator
  Bob begin() {
    return Bob{this->value};
  }

  // this will be called to compare against the current iterator
  Bob end() {
    return Bob{this->value + 10};
  }
};

int main() {
  Example e{42}; // start at 42

  // explicitly
  std::cout << "Explicitly calling the iterator:\n";
  for (Example::Bob it = e.begin(); it != e.end(); ++it) {
    std::cout << *it << '\n';
  }

  // implicitly with for-range loop
  std::cout << "\nImplicitly calling the iterator with for-range loop:\n";
  for (int & val : e) { // notice this directly grabs the value
    std::cout << val << '\n';
  }
}
