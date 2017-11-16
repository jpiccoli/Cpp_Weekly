#include <algorithm>
#include <iostream>

// C++98
int my_min(int x, int y, int z)
{
  return std::min( std::min( x, y ), z );
}

// C++11
int my_min2(int x, int y, int z)
{
  // Accepts initializer list
  return std::min({x,y,z});
}

template<typename First, typename ... T>
decltype(auto) variadic_min( const First &f, const T& ... t )
{
  const First * retval = &f; 
  ( ( retval = &std::min( *retval, t ) ), ... );
  return *retval;
}

int main()
{
  // All arguments must be of the same type due to limitations
  // of std::min
  std::cout << variadic_min( 7, 9, 11, 15 ) << "\n";
}
