#include <vector>
#include <string>
#include <set>
#include <iostream>

struct MyData
{
  std::string key;
  std::string value2;
};

int main()
{
  // Cannot put a lambda inside a template <>
  // This is why a lambda can't be a comparator in that form
  // Also, a lambda does not have a default constructor

  const auto lambda = []( const MyData & lhs, const MyData & rhs)
  {
    return lhs.key < rhs.key;
  };

  // Workaround:
  // Make the lambda a parameter of the std::set constructor
  std::set<MyData, decltype(lambda)> myset{lambda};

  // Slightly cleaner alternative that doesn't work with current
  // versions of gcc and clang - template argument deduction is
  // not supported
  // std::set myset{{MyData{"Bob"}}, lambda};
  myset.insert(MyData{"Bob"});
  std::cout << "Just a test" << '\n';
}

