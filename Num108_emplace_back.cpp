#include <vector>
#include <iostream>
#include <cstdio>

struct S
{
  S(int) { puts("S(int)"); }
  S() { puts("S()"); }
  S(const S&) { puts("S(const S&)"); }
  S(S&&) { puts("S(S&&)"); }
  S &operator=(const S&) { puts("operator=(const S&)"); return *this; }
  S &operator=(S&&) { puts("operator=(const &&S)"); return *this; }
  ~S() { puts("~S()"); }
};

int main()
{
  std::vector<S> vec;
  vec.push_back(S(3));
  vec.emplace_back(3); // Calls constructor in place, eliminates move operation
}

