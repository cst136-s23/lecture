#include <catch2/catch_test_macros.hpp>

#include "vector.h"

TEST_CASE("Vector basics", "[vector]") {
  Vector<int> items{};
  REQUIRE(items.size() == 0);
  items.append(42);
  items.append(1337);
  REQUIRE(items.size() == 2);

  SECTION("copy ctor") {
    Vector<int> items2{items};
    items.append(10000);
    REQUIRE(items2.size() == 2);
    REQUIRE(items.size() == 3); // make sure it's a deep copy
  }

  SECTION("operator=") {
    Vector<int> items2{};
    items2.append(21);
    items2 = items;
    REQUIRE(items2.size() == 2);
    items2.append(22);
    REQUIRE(items2.size() == 3);
    REQUIRE(items.size() == 2); // make sure it was a deep copy
  }
}

TEST_CASE("Vector removeIf", "[vector]") {
  Vector<int> v{};
  v.append(2);
  v.append(4);
  v.append(5);
  v.append(6);
  REQUIRE(v.size() == 4);
  v.removeIf([](auto & n) {
    return n % 2 != 0;
  });
  REQUIRE(v.size() == 3);
}
