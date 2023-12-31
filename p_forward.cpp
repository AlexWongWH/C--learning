#include <algorithm>
#include <iostream>
#include <memory>

class A {
public:
  A() = default;
  A(const int &n) : my_num{n} {}
  int my_num{5};
};

// template function
template <typename T> std::shared_ptr<T> Factory() {
  return std::shared_ptr<T>(new T);
}

template <typename T, typename A1> std::shared_ptr<T> Factory(const A1 &a) {
  return std::shared_ptr<T>(new A1(a));
}

// generic wrapper class
template <typename T> class class_wrap : public wrapper_base {
private:
  T t_;

public:
  class_wrap() : t_{} {}
};

int main() {

  std::cout << "wow\n";

  // std::shared_ptr<A> p = Factory<A>(5);

  return 0;
}