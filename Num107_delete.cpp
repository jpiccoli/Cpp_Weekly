#include <vector>
#include <iostream>
#include <cstdio>
#include <utility>

struct S
{
  S() = default;
  S(S&&) = default;
  S(const S&) = default;
  S(const S&&) = delete;
  S &operator=(const S&) = default;
  S &operator=(S&&) = default;
  S &operator=(const S&&) = delete;

  // Use = delete to remove an overload from the set of overloads
 
  //constexpr void do_something(int) const noexcept {}

  template<typename T>
  constexpr void do_something(T) const noexcept {}

  void do_something(double) const noexcept = delete;
};

int main()
{
  S s;
  S s2;
  s2 = std::move(s);

  s2.do_something(1);	// no warning
  s2.do_something(1.0); // error
  s2.do_something(1.f); // error with explicit function; works with template
  s2.do_something(1ll);	// ambiguous overload with explicit function; works with template
}

