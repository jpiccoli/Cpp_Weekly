#include <iostream>
#include <cmath>

int main()
{
  std::cout << 1 * 0 << "\n";
  std::cout << -1 * 0 << "\n";
  std::cout << -1.0 * 0 << "\n";

  std::cout << (-1.0 * 0 == 0.0 ) << "\n"; // True
  std::cout << (-1.0 * 0 > 0.0 ) << "\n";  // False 
  std::cout << (-1.0 * 0 < 0.0 ) << "\n";  // False
  std::cout << -0.0 << "\n";  // Prints "-0"; must be decimal

  std::cout << std::signbit( -0.0 ) << "\n";

  return 0;
}
