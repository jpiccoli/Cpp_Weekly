#include <iostream>
#include <type_traits>
#include <typeinfo>

auto val()
{
  return -0xFFFFFFFF;
}

int main()
{
  // Negation results in rollover - 2's complement
  static_assert( -0xFFFFFFFF == 1, "Error 1" );
  static_assert( std::is_same<decltype( val() ), unsigned int>::value, "Error 2" );

  int val1 = 1, val2 = 1;

  val1 |= 1 << 0;
  val2 |= 1 << 6;

  std::cout << val1 << "\n";
  std::cout << val2 << "\n";

  return 0;
}
