#include "tag_dispatch.hpp"

int main() {
  std::cout << "Hello\n";

  // isEqual(2, 2);
  // isEqual(2.4, 5.2);
  vec2 p1, p2{2, 1};
  vec3 v3;

  Lane<vec2> L{};

  std::cout << "only type triats, compare_value val : "
            << L.compare_value<vec2>() << "\n";

  std::cout << "get_value val : " << L.get_value<vec2>() << "\n";

  return 0;
}