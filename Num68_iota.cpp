#include <iostream>
#include <numeric>
#include <algorithm>
#include <array>

int main()
{
  std::array<int, 10> a;

  // C++11
  std::iota(begin(a), end(a), 3);

  std::cout << a.back() << "\n";

  std::array<int, 10> b;

  // Equivalent C++98 implementation
  std::generate(begin(b), end(b),
    [i = 0]() mutable { return i++; }
  );

  std::cout << b.back() << "\n";
}
