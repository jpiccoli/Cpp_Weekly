#include <iostream>
#include <optional>
#include <string>

// Compiler does not support std::optional
// Need at least g++ 7.1 or clang 5.0

struct S
{
  S(const S&) = delete;
  S(const S&&) = delete;
  S()= default;
};

int main()
{
  // std::optional does not do dynamic allocation on its own
  std::optional<int> i;
  i = 7;  // initializes unset value
  i = 11; // calling assignment operator

  std::optional<std::string> o;

  // Move assignment of value inside the optional
  o = std::string("Hello");

  // If move not available...
  std::optional<S> p;
  p.emplace();

  std::optional<int> j;
  return i.value() + j.value_or(2);
}
