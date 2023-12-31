#include <iostream>
#include <string>
#include <vector>

/* usage: Not knowing the exact types and dependencies of the objects your code
is working with */

// Seperates product construction code from code that actually uses the product

// declares the interface all concrete product must implement
class Product {
public:
  virtual ~Product() {}                      // virtual dtor
  virtual std::string Operation() const = 0; // pure virtual method
};

/*
Various concrete product
*/
class ConcreteProduct1 : public Product {
public:
  std::string Operation() const override {
    return "Return from concrete product 1\n";
  }
};

class ConcreteProduct2 : public Product {
public:
  std::string Operation() const override {
    return "return from concrete product 2\n";
  }
};

/* creator/factory has a method which must return an object of a product class
subclasses/children would provide the implementation of this creator/factory
method */

class Factory {
  virtual ~Factory() {}
  // pure virtual func, returns ptr to concrete method
  virtual Product *FactoryMethod() const = 0;
};

int main() {

  std::cout << "starting factory pattern\n";

  return 0;
};