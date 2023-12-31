#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

// // floating type
// template <typename T> bool is_equal_impl(T lhs, T rhs, std::true_type tt) {
//   std::cout << " floating type \n";
//   return true;
// }

// // non floating
// template <typename T> bool is_equal_impl(T lhs, T rhs, std::false_type ft) {
//   std::cout << " non floating type \n";
//   return rhs == lhs;
// }

// // generic rule on what to do
// template <typename T> bool isEqual(T lhs, T rhs) {
//   return is_equal_impl(
//       lhs, rhs,
//       typename std::conditional<std::is_floating_point<T>::value,
//                                 std::true_type, std::false_type>::type{});
// }

// SFINE
struct vec3 {
  float x{};
  float y{};
  float z{};
};

struct vec2 {
  float x{};
  float y{};
};

// void matmul() {
//   int width = 3;
//   for (int i{0}; i < width; ++i) {
//     for (int j{0}; j < width; ++j) {
//       int sum = 0;
//       for (int k{0}; k < width; ++k) {
//         int a = mat[i * width + k];
//         int b = mat[k * width + j];
//       }
//     }
//   }
// }

template <typename T> //
class Lane {
public:
  // normal type traits;
  template <typename N> //
  auto const compare_value() {
    std::cout << "comparing values \n ";
    return std::is_same<N, T>::value;
  }

  template <typename N> //
  auto get_value() {
    return get_value_impl<N>();
  }

  template <typename N,
            typename std::enable_if_t<std::is_same<N, T>::value>::value = true>
  auto get_value_impl() {
    std::cout << "get_val impl TRUE \n";
    return true;
  }

  // template <typename N,
  //           typename std::enable_if_t<std::is_same<N, T>::value>::value =
  //           false>
  // auto get_value_impl() {
  //   std::cout << "get_val impl FALSE\n";
  //   return false;
  // }
};
