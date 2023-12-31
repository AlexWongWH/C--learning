#include <iostream>
#include <memory>

// templated singleton

template <typename T> class Singleton {
public:
private:
  // arguements have to be forwarded
  template <typename... args> //
  static T *createSingleton(args...);

  Singleton() = default;

  static std::unique_ptr<T> singleton_;
};
