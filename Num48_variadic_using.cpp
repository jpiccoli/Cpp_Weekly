#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>

// Need gcc 7.x to compile

template<typename B1, typename B2>
struct Merged : B1, B2
{
  Merged(B1 b1, B2 b2) : B1(std::move(b1)), B2(std::move(b2)) {}

  using B1::operator();
  using B2::operator();
};

template<typename ... B>
struct MergedV : B...
{
  template<typename ... T>
  MergedV(T && ... t) : B(std::forward<T>(t))...
  {
  }

  using B::operator()...;
};

template<typename ... T>
MergedV(T...) -> MergedV<std::decay_t<T>...>;


int main()
{
  const auto l1 = [](){ return 42; };
  const auto l2 = [](const int i){ return i * 9; };

  // Compiler does not support class template type deduction
  Merged<decltype(l1), decltype(l2)> merged(l1, l2);

  std::cout << merged() << "\n";	// returns "42"
  std::cout << merged(11) << "\n";	// returns "99"

  return merged(11);
}
