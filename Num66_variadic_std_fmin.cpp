#include <iostream>
#include <cmath>
#include <algorithm>
#include <initializer_list>

// C++11 version
template<typename First, typename ... T>
decltype(auto) variadic_fmin( const First &f, const T& ... t )
{
  // std::fmin returns a value, not a reference
  First retval = f; 
  std::initializer_list<First>{(retval = std::fmin(retval, t)) ...};
  return retval;
}

int main()
{
  std::cout << variadic_fmin( -3.0f, -6.0f, -7.0f, -2.0f ) << "\n"; // -7
}
