#include <algorithm>
#include <iostream>
#include <memory>
#include <type_traits>

/*
template< bool B, class T, class F >
struct conditional;
*/

double addfive(double p) { return p + 5; }

/*
template, don’t need to be specific about what exactly ptrFnc is (it can be a
function, a functor, or a method bound to an object instance).
*/

// Problem -> have more than one function and more than one parameter..
//  Have to guess the type of function and manipulate the type to
//  correctly extract the values

// Type manipulation
// Working with arbitrary number of parameters and working with them

// Type traits are basically a way to just examine these types and get
// information about them.
// you might want to know whether a type is a pointer or a reference, or whether
// it is const-qualified

// ask questions about a type at compile time

// given this function, where it takes a ptr and deferences it for it's value
// passing it a reference will fail to compile
template <typename T> //
T GetValueFromPointer(T *ptr) {
  std::cout << "this is ptr " << std::is_pointer<decltype(ptr)>::value << "\n";
  // static_assert(std::is_pointer<T *>::value, "Argument must be a pointer");
  static_assert(std::is_pointer<decltype(ptr)>::value,
                "Argument must be a pointer");
  std::cout << "Getting value from ptr: " << *ptr << std::endl;
  return *ptr;
}

// std::enable_if<true, T>

template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type
Multiply(const T &x, const T &y) {
  return x * y;
}

template <typename T>
typename std::enable_if<!std::is_arithmetic<T>::value, T>::type
Multiply(const T x, const T y) {
  std::cout << "Cannot multiply non-arithmetic types\n";
  return T{"ahh screaming into the void\n"};
}

// under the hood, checking the type
/* struct is_floating_point_int {
    static const bool value = false;
}; */

template <typename ptrFnc>
double magic_ptr(ptrFnc mg_ptr, double sample_parameter) {
  double magic_result = mg_ptr(sample_parameter);
  std::cout << "Parameter " << sample_parameter << " magic result "
            << magic_result << "\n";

  return magic_result;
};

// taking arbitrary num of function
