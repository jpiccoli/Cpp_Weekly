#include <iostream>
#include <utility>

struct S
{
  S() = default;
  S(S &&) = default;
  S(const S&) = default;
  S(const S&&) = delete;
  S &operator=(const S&) = default;
  S &operator=(const S&&) = default;

};

int main()
{
  const S s;
  S s2 = std::move(s); // doesn't compile due to deleted function
}
