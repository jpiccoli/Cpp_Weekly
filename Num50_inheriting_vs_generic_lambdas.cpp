#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>
#include <variant>
#include <array>

// Need gcc 7.x to compile

// Generic lambda: C++14

template<typename ... B>
struct Visitor: B...
{
  template<typename ... T>
  Visitor(T && ... t) : B(std::forward<T>(t))...
  {
  }

  using B::operator()...;
};

template<typename ... T>
Visitor(T...) -> MergedV<std::decay_t<T>...>;

int main()
{
  std::array<std::variant<double, int>, 2> a(3.2, 2);

  int intTotal = 0;
  double doubleTotal = 0.0;
  std::common_type_t<decltype(intTotal), decltype(doubleTotal)> grandTotal = 0;

  // Uses initializer list
  // Inheriting lambda
  Visitor visitor
  { 
    [&intTotal, &grandTotal](const int i){ intTotal += i; grandTotal += i;},
    [&doubleTotal, &grandTotal](const double d){ intDouble += d; grandTotal += d; } 
  };

  std::for_each( std::begin(a), std::end(a), 
		  [&visitor](const auto &v){ std::visit(visitor, v); } );

  // Generic lambda
  auto generic_visitor = [&intTotal, &doubleTotal, &grandTotal](const auto v)
  {
    grandTotal += v;
    if( constexpr(std::is_same<(double, decltype(v)>{})
    {
      doubleTotal += v;
    }
    else
    {
      intTotal += v;
    }
  };

  std::for_each( std::begin(a), std::end(a), 
		  [&generic_visitor](const auto &v){ std::visit(generic_visitor, v); } );

  return intTotal;
}
