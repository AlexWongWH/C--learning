#include <algorithm>
#include <functional>
#include <iostream>
#include <ratio>
#include <sstream>
#include <stdio.h>
#include <string>
#include <type_traits>
#include <vector>

// “X-macros” technique is to encode that information in source code, which can
// be manipulated at compile time.

// #define process(mytype, member) mytype member

// // create enumeration type for monsters
// enum Monster {
// #define X(name, b, c, d, e) MON_##name,
// #include "monsters.h"
// #undef X
// };

// bool is_immune_to_poison(Monster m) {
//   switch (m) {
// #define X(name, b, c, d, imm) \
//   case MON_##name: \
//     return (imm == IMM_POISON)
// #include "monsters.h"
// #undef X
//   }
// };

#define MAX(a, b) (a > b ? a : b)

// # stringizing operator
#define mystr(x) std::printf_s(#x)

const std::size_t UnitConversion(const std::string &str) {
  char const c{static_cast<char>(std::tolower(*str.begin()))};

  switch (c) {
  case 'k':
    return std::kilo::num;
    break;
  case 'm':
    return std::mega::num;
    break;
  case 'g':
    return std::giga::num;
    break;

  default:
    break;
  }

  return std::size_t{};
}

void santise(std::string &s) {
  std::for_each(s.begin(), s.end(), [](char &c) {
    if (!std::isdigit(c)) {
      c = ' ';
    }
  });
}

int main() {

  //
  // Monster example = MON_centipede;

  // int a = MAX(5, 7);
  // std::cout << "max " << a << std::endl;

  // // still counts the escape sequences
  // int ncount = 0;
  // printf("How many characters? %n \n", &ncount);
  // printf("Number of characters printed: %d\n ", ncount);

  // printf("%*s", 25, "This is a test\n");
  // printf("%25s", "This is a test\n");
  // printf("%25d \n", 1);
  // printf("%*d \n", 25, 1);

  // std::string dspeed{"61.17KB\/s"};
  // std::string wspeed{"84.17MB\/s"};
  // std::stringstream ss{dspeed};

  // std::string unit{};
  // double d;
  // double w;
  // ss >> d;
  // ss >> unit;
  // std::cout << "dspeed " << d << unit << std::endl;

  // ss.clear();
  // ss.str(wspeed);

  // ss >> w >> unit;

  // std::cout << "wspeed " << w << unit << std::endl;

  // std::cout << "unit " << UnitConversion(unit) << std::endl;

  // uint16_t n{132};
  // std::cout << "casted: " << static_cast<float>(std::kilo::num) * 0.15F
  //           << std::endl;

  // static constexpr float div{1.f / std::mega::num};
  // std::cout << "div " << div * std::kilo::num << std::endl;

  // static constexpr std::size_t divor{1 / std::mega::num};
  // std::cout << "size t divor " << divor << std::endl;

  // std::vector<int> index;
  // std::generate_n(std::back_inserter(index), 10, [&index]() {
  //   auto idx = index.size();
  //   return ++idx;
  // });

  // for (auto const &n : index) {
  //   std::cout << "n: " << n << std::endl;
  // }

  // std::decay_t<decltype(*index.begin())> a{};

  // for (decltype(index)::iterator iter = index.begin(); iter <)

  std::string nuu{" 23 51 a65 ,48"};
  std::stringstream ss{nuu};
  int d{};
  santise(nuu);

  return 0;
}