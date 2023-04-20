#pragma once

#include <iostream>
#include <cstring>

class String {
private:
  char * str{};
  size_t len{};

public:
  String() = default;

  String(const char * cstr) {
    len = std::strlen(cstr);
    str = new char[len + 1]{};
    std::strcpy(str, cstr);
  }

  ~String() {
    delete[] str;
    str = nullptr;
    len = 0;
  }

  String(const String & other) {
    len = other.len;
    str = new char[len + 1]{};
    std::strcpy(str, other.str);
  }

  String(String && other) {
    std::cout << "move constructor\n";
    len = other.len;
    str = other.str;
    other.len = 0; // optional but recommended
    other.str = nullptr;
  }

  String & operator=(const String & other) {
    if (this == &other) {
      return *this;
    }

    delete[] str;

    len = other.len;
    str = new char[len + 1]{};
    std::strcpy(str, other.str);

    return *this;
  }

  String & operator=(String && other) {
    if (this == &other) {
      return *this;
    }

    std::cout << "move operator= (assignment)\n";

    delete[] str;

    len = other.len;
    str = other.str;
    other.len = 0; // optional but recommended
    other.str = nullptr;

    return *this;
  }

  bool operator==(const char * other) const {
    return !std::strcmp(this->str, other);
  }

  bool operator==(const String & other) const {
    return this->operator==(other.str);
  }

  operator const char * () const {
    return this->str;
  }
};
