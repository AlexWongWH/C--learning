#include <iostream>
#include <optional>
#include <utility>
#include <variant>
#include <vector>

// since c++ 17

// does optinal take space when the values are invalid?

struct foo {
  std::optional<int> space_;
  std::variant<int, float> v, w;
  // int *wow;
  // int packed;
};

int main() {

  foo f;
  std::cout << " the size: " << sizeof(f) << "\n ";
  return 0;
}
