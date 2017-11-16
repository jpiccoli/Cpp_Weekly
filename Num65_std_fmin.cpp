#include <iostream>
#include <algorithm>
#include <cmath>

template<typename First, typename ... T>
decltype(auto) variadic_fmin( const First &f, const T& ... t )
{
  // std::fmin returns a value, not a reference
  First retval = f; 
  ( ( retval = std::fmin( retval, t ) ), ... );
  return retval;
}

int main()
{
  // If two values are equal, the first one is returned
  std::cout << std::min( -3.0f, 2.0f ) << "\n";
  std::cout << std::min( -3.0f, NAN ) << "\n"; 	// -3
  std::cout << std::min( NAN, -3.0f ) << "\n"; 	// NAN 

  // NAN is treated as missing data in std::fmin
  std::cout << std::fmin( NAN, -3.0f ) << "\n"; // -3 
  std::cout << std::fmin( -3.0f, NAN ) << "\n"; // -3

  std::cout << variadic_fmin( -3.0f, -6.0f, -7.0f, -2.0f ) << "\n"; // -7
}
