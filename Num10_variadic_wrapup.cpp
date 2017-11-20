// C++ Weekly #10
// Created: 11/19/2017

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>
#include <utility>

// Cases where compiler will evaluate in order:
// 1. std::initializer_list explicit
// 2. Grouped function calls (f1(), f2())
template<typename T>
void print_impl(const T &t)
{
  std::cout << t << "\n";
}

int f1()
{
  std::cout << "f1\n";
  return 1;
}

int f2()
{
  std::cout << "f2\n";
  return 2;
}

template<typename ... T>
void print(const T& ... t)
{
  // Initializer list will execute in specified order including
  // parameter pack expansion 	
  // Comma-delimited sequence items will also be executed in order
  // Zero is result value
  (void)std::initializer_list<int>{ (print_impl(t), 0)...};
}

template<typename ... T>
std::vector<std::string> print2(const T& ... t)
{
  std::vector<std::string> retval;
  std::stringstream ss;
  (void)std::initializer_list<int>{ (ss.str(""), ss << t, retval.push_back(ss.str()), 0)...};
  return retval;
}

template<typename ... T>
void print_no_impl(const T& ... t)
{
  (void)std::initializer_list<int>{ (std::cout << t << "\n", 0)...};
}

int main()
{
  print("Hello", "World", 1 , 2, 3, 4.2f);

  // gcc: f2() called before f1()
  // clang: f1() called before f2()
  print(f1(), f2());

  // f1() and next f2() called
  int i = (f1(), f2());
  std::cout << "i = " << i << "\n";

  // Initializer list will execute in specified order including
  // parameter pack expansion 	
  (void)std::initializer_list<int>{ f1(), f2() }; 

  std::cout << "----------" << "\n";

  // Order of f1() and f2() is correct for "print()" call
  print("Hello", "World", 1.1, 2.2, 4.2f, 7, f1(), f2());

  std::cout << "----------" << "\n";

  // Order of f1() and f2() is correct for "print()" call
  for( auto const& s : print2("Hello", "World", 1.1, 2.2, 4.2f, 7, f1(), f2()) )
  {
    std::cout << s << "\n";
  }
}
