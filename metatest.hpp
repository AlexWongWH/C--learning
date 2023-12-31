#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

// test writing a template class with a function
//  the function might or might not exist within the class
// have to validate check execute

// template <typename T> //
// std::string my_to_string_impl(const T &t) {
//   std::stringstream ss;
//   ss << t;
//   return ss.str();
// }

// base case to end the recursive function call,  the zeroth case, where there
// is no more parameters
std::vector<std::string> my_to_string() { return {}; }

// make a print function, which instantiates templates recursively [bloats
// space]
// template <typename P1, typename... Param>
// std::vector<std::string> my_to_string(const P1 &p1, const Param &...para) {
//   std::vector<std::string> v;
//   // my_to_string_impl(p1); // P1, at least one parameter
//   v.emplace_back(my_to_string_impl(p1));

//   // this line expands out to my_to_string_impl(para1, para,2);
//   // Basically tells the compiler to automatically expand out when declaring
//   ...
//   // recursively call the function to insert it to the vector
//   const auto remain = my_to_string(para...);
//   v.insert(v.end(), remain.begin(), remain.end());
//   return v;
// }

class test {

  using Lane = std::unordered_map<std::string, size_t>;
  Lane::value_type LaneLookUpFind();

private:
  Lane lane_lookup_;
};

template <typename... Param>
std::vector<std::string> my_to_string(const Param &...param) {

  // try using generic lambda
  const auto my_to_string_impl = [](const auto &t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
  };

  return {my_to_string_impl(
      param)...}; // expands out the param, creates initalization list
}

template <typename... items> class Store {
public:
  std::tuple<items...> t_stocks_;
  std::vector<items...> a_stocks_;

private:
};
