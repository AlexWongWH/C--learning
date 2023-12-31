#include <iostream>
#include <memory>

// singleton is a "god class" where only ONE exist. Basically a static class
// delete copy ctor, move ctor

// the default constructor should be static
// only instanciate the object only once

struct DataStore {
  int one{1};
  int two{2};
  int three{3};
};

class Singleton {
public:
  static Singleton *GetInstance();

  // copy ctor
  Singleton(Singleton &rhs) = delete;
  // copy assignement
  Singleton &operator=(Singleton &rhs) = delete;
  DataStore &GetDatabase() { return database; }

  // this destructor does not get called
  ~Singleton() {
    std::cout << "dealloc mem\n";
    delete singleton_;
  }

private:
  Singleton() = default;
  static Singleton *singleton_;
  DataStore database{};
};

// Initialize static class members

Singleton *Singleton::GetInstance() {

  if (nullptr == singleton_) {
    std::cout << " allocating mem\n";
    singleton_ = new Singleton(); // allocate mem & point to the memory
  }

  return singleton_;
}
