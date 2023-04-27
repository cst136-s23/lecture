#include <iostream>
#include <fstream>

class Point {
private:
  float x, y;

public:
  Point() = default;

  Point(const Point & other) = default;

  Point& operator++() { // prefix
    ++x;
    ++y;
    return *this;
  }

  Point operator++(int) { // postfix
    Point p{*this};
    ++(*this);
    return p;
  }

  friend std::ostream & operator<<(std::ostream & os, const Point & p);
};

std::ostream & operator<<(std::ostream & os, const Point & p) {
  os << p.x << ' ' << p.y << '\n';
  return os;
}

int main() {
  // int x{42};
  // std::cout << (x++) /* postfix */ << ' ' << (++x) /* prefix */ << '\n';

  Point p{};
  std::cout << (++p) << '\n';
  operator<<(operator<<(std::cout, ++p), ++p);
  std::cout << ++p << p++;
}