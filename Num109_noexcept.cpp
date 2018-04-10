#include <vector>
#include <iostream>
#include <cstdio>

// 04/09/2018
// Using noexcept allows the compiler to use move instead of copy
struct S
{
  //S(int) { puts("S(int)"); }
  S(int) noexcept { puts("S(int)"); }
  //S() { puts("S()"); }
  S() noexcept { puts("S()"); }
  //S(const S&) noexcept { puts("S(const S&)"); }
  S(const S&) { puts("S(const S&)"); }
  //S(S&&) { puts("S(S&&)"); }
  S(S&&) noexcept { puts("S(S&&)"); }
  //S &operator=(const S&) { puts("operator=(const S&)"); return *this; }
  S &operator=(const S&) noexcept { puts("operator=(const S&)"); return *this; }
  //S &operator=(S&&) { puts("operator=(const &&S)"); return *this; }
  S &operator=(S&&) noexcept { puts("operator=(const &&S)"); return *this; }
  //~S() {puts("~S()"); }
  ~S() noexcept {puts("~S()"); }
};

int main()
{
  std::vector<S> vec;
  std::cout << vec.capacity() << '\n';
  //vec.push_back(S(3));
  vec.emplace_back(3);
  std::cout << vec.capacity() << '\n';
  vec.emplace_back(3);
  std::cout << vec.capacity() << '\n';
  vec.emplace_back(3);
  std::cout << vec.capacity() << '\n';
}

