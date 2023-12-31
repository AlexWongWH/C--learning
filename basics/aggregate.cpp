#include <iostream>
#include <vector>

// <Aggregate>
// Array or class with
// no user-declared constructor, inherited or explict constructor
// no private or protected non-static data members
// no base classes
// no virtual functions
// no default member initialization -> obj(val) : val_{0} {}

// Aggregate initialization

// Initalization

struct vec3 {
  float x;
  float y;
  float z;

  friend std::ostream &operator<<(std::ostream &os, const vec3 &v);
};

std::ostream &operator<<(std::ostream &os, const vec3 &v) {
  os << " x: " << v.x << " y: " << v.y << " z: " << v.z;
  return os;
}

struct line {
  vec3 start_pt;
  vec3 end_pt;
  friend std::ostream &operator<<(std::ostream &os, const line &v);
};

std::ostream &operator<<(std::ostream &os, const line &v) {
  os << "start:" << v.start_pt << "\n";
  os << "end: " << v.end_pt << "\n";
  return os;
}

int main() {

  // 1. Normal initialization
  vec3 v1 = {1, 2, 3}; // works

  // 2. List initialization
  vec3 v2{3, 3, 2};

  std::cout << v2 << std::endl;

  // 3. aggregrate initalization, since c++20
  // vec3 v3{.y = 2, .x = 9}; // error, has to follow declaration order
  vec3 v3{.x = 9, .y = 2};
  std::cout << v3 << std::endl;

  // line l1{.start_pt = v1, v2}; // error, initialization caluses should be
  // designated

  line l1{.start_pt = v1, .end_pt = v2};

  std::cout << l1 << std::endl;

  return 0;
}
