#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

// Replace with string_view => doesn't create a string on the stack
// or allocate space. Used if only need to look at string, not use
// a string.
std::size_t length( const std::string &s )
{
  return s.size();
}

int main()
{
  std::cout << length("hello world, long string") << "\n";
}
