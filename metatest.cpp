#include "metatest.hpp"

// matrix multiplication

// given square matrix
//  1 2 3 // 7 8 9
//  4 5 6 // 4 5 6
//  7 8 9 // 1 2 3

int main() {

  //              //k = 0, 1, 2
  std::vector<int> matA{1, 2, 3,  // i = 0
                        4, 5, 6,  // i = 1
                        7, 8, 9}; // i = 2

  //              //j = 0, 1, 2
  std::vector<int> matB{1, 2, 3,  // k = 0
                        4, 5, 6,  // k = 1
                        7, 8, 9}; // k = 2

  std::vector<int> result{};
  result.resize(9);

  int N = 3;

  for (int i{}; i < N; ++i) {
    for (int j{}; j < N; ++j) {
      int sum{};

      for (int k{}; k < N; ++k) {
        int a = matA[i * N + k];
        int b = matB[k * N + j];
        sum += a * b;
      }

      result[i * N + j] = sum;
    }
  }

  int count{0};
  for (auto const &n : result) {
    ++count;
    std::cout << n << " ";
    if (count % 3 == 0)
      std::cout << "\n";
  }

  // std::cout << "My varadic function\n";
  // const std::vector<std::string> vec = my_to_string('a', 23, "hello", 5.3);

  // for (auto const &words : vec) {
  //   std::cout << words << "\n";
  // }

  return 0;
}