#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <array>

int main()
{
  std::cout << "Just a test" << '\n';

  // Template arguments required because compilers do not support deduction
  std::array<double, 5> values{1.1, 2.2, 3.3, 4.4, 5.5};

  auto result1 = std::accumulate(std::begin(values), std::end(values), 0);

  // gcc and clang do not warn; MSVC does.
  std::cout << "Result 1 = " << result1 << '\n'; // Returns "15" because of "0"

  auto result2 = std::accumulate(std::begin(values), std::end(values), 0.0);

  std::cout << "Result 2 = " << result2 << '\n'; // Returns "16.5" because of "0.0"
}
