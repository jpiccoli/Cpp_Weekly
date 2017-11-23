#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <utility>
#include <variant>
#include <array>

// Need gcc 7.x to compile

// Why: To allow a visitor to walk over a variant with different types

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

  // Each type supported requires a separate lambda function
  Visitor visitor{ [&intTotal](const int i){ intTotal += i; },
                   [&doubleTotal](const double d){ intDouble += d; } };

  std::for_each( std::begin(a), std::end(a), 
		  [&visitor](const auto &v){ std::visit(visitor, v); } );
}
