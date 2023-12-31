
#include "metalearn.hpp"

int main() {

  // std::conditional<condition, true,false>
  static const std::uint64_t default_buffer_size = std::conditional<
      sizeof(void *) == 8,
      std::integral_constant<std::uint64_t, 100 * 1024 * 1024>,
      std::integral_constant<std::uint64_t, 1024 * 1024 * 1024>>::type::value;

  std::cout << "default buf size " << default_buffer_size << std::endl;

  using Type1 = std::conditional<true, int, double>::type;
  using Type2 = std::conditional<false, int, double>::type;
  using Type3 =
      std::conditional<sizeof(int) >= sizeof(double), int, double>::type;

  using double_ptr_type = std::add_pointer<double>::type;  // result: double*
  using double_type = std::remove_pointer<double *>::type; // result: double
  // removing pointer from non-pointer is safe.
  using double_too_type = std::remove_pointer<double>::type; // result:

  // basic building blocks and extremely useful when dealing with type
  // constraints

  // If the template parameter is a const value but you need the value, can
  // ensure it's the type

  auto const val = magic_ptr(addfive, 5);

  std::cout << "val " << val << std::endl;

  // What is type traits
  int i{250};
  int *ip{&i};
  int &rp{i};

  GetValueFromPointer(ip);
  // GetValueFromPointer(rp); //error: no matching function for call to
  // ‘GetValueFromPointer(int&)’

  std::cout << "Multiplying " << Multiply(4, 5) << "\n";
  std::cout << "Wow multiplying: " << Multiply("23", "2");

  return 0;
}