#include <iostream>
#include <string>
#include <vector>
#include <memory>

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


//Abstract idea of coffee
class Coffee
{
  public:
  virtual std::string GetCoffeeName() {return name_;}
  std::string name_ {"Coffee\n"};
};

class Expresso :public Coffee
{
  std::string GetCoffeeName() override {return name_;}
  std::string name_ {"Expresso"};
};

class Latte :public Coffee
{
  std::string GetCoffeeName() override {return name_;}
  std::string name_ {"Latte"};
};

//Abstract Coffee machine 
class CoffeeMachine
{
private:
  /* data */
public:

  virtual Coffee* MakeCoffee() {return new Coffee;}

  std::string CreateCoffee()
  {
    Coffee* cof = this->MakeCoffee();
    std::cout << "Abstract class creating coffee: " << cof->GetCoffeeName() << std::endl;
    return cof->GetCoffeeName();
  }

};

class ExpressoMachine : public CoffeeMachine
{
  Coffee * MakeCoffee() override {return new Expresso;}
};

class LatteMachine : public CoffeeMachine
{
  Coffee * MakeCoffee() override {
    std::cout << "making Latte \n";
    return new Latte;
    }
};

int main() {
  std::cout << "starting factory pattern\n";
  // LatteMachine LatteMachine;
  std::unique_ptr<CoffeeMachine> MyLatteMachine = std::make_unique<LatteMachine>();
  auto* coffee = MyLatteMachine->MakeCoffee();
  std::cout << "main: getting coffee name: " << coffee->GetCoffeeName() << std::endl;


  return 0;
};