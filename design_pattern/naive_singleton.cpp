#include "singleton.hpp"

Singleton *Singleton::singleton_ = nullptr;

void fnc1() {
  std::cout << "FNC 1 calls\n";
  Singleton *sp = Singleton::GetInstance();
  std::cout << " value of datastore one: " << sp->GetDatabase().one
            << std::endl;
  std::cout << "Modifiying datastore one: \n";
  sp->GetDatabase().one = 3;
}

int main() {

  fnc1();
  Singleton *sp = Singleton::GetInstance();
  std::cout << " value of datastore one: " << sp->GetDatabase().one
            << std::endl;

  return 0;
}