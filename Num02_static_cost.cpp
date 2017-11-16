// C++Weekly.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <typeinfo>
#include <exception>
#include <cxxabi.h>
#include <experimental/any>

////////////////
// C++ Weekly #2
////////////////
struct C
{
  static const std::string & magic_static()
  {
    std::cout << "Inside magic_static()" << std::endl;
    static const std::string s = "bob";
    return s;
  }

  const std::string &s = magic_static();

  const std::string & magic_static_ref()
  {
    return s;
  }
};

int main(int argc, char *argv[])
{
  std::cout << "Prior to option 1\n";
  C::magic_static().size();
  C::magic_static().size();
  C::magic_static().size();
  auto x = C::magic_static().size();

  std::cout << "Prior to option 2\n";
  C c;
  c.magic_static_ref().size();
  c.magic_static_ref().size();
  c.magic_static_ref().size();
  auto y = c.s.size();

}

