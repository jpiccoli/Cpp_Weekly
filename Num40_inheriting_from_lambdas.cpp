#include <iostream>
#include <type_traits>

template<typename L1, typename L2>
struct S : L1, L2
{
  S(L1 l1, L2 l2) : L1(std::move(l1)), L2(std::move(l2)) {}
  using L1::operator();
  using L2::operator();
};

template<typename L1, typename L2>
auto make_combined(L1 &&l1, L2 &&l2)
{
  return S<std::decay_t<L1>, std::decay_t<L2>>(std::forward<L1>(l1),
		  std::forward<L2>(l2));
}

int main()
{
  auto l = []() { return 4; };
  auto l2 = [](int i) { return i * 11; };

  auto combined = make_combined(l, l2);
  std::cout << combined() << "\n";
  std::cout << combined(9) << "\n";

  // Simpler version
  auto combined2 = S<decltype(l), decltype(l2)>(l, l2);
  std::cout << combined2() << "\n";
  std::cout << combined2(9) << "\n";
 
  // C++17 feature not supported by compiler
  // auto combined2 = S(l, l2);
}
