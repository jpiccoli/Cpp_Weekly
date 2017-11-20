// C++ Weekly #6
// Created: 11/19/2017

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>

template<typename T>
void print( const T& t )
{
   std::cout << t << "\n";
}

template<typename T>
std::string to_string( const T& t )
{
  std::stringstream ss;
  ss << t;
  return ss.str();
}

// Variadic versions
// Implementation - common to versions 1 and 2
template<typename T>
std::string to_string_impl1( const T& t )
{
  std::stringstream ss;
  ss << t;
  return ss.str();
}

// Version 1 - "Classic" example using recursion
// Add call to support case with zero parameters
std::vector<std::string> to_string_v1()
{
  return {};
}

// Separate function generated for each combination of arguments - inefficient
template<typename P1, typename ... Param>
std::vector<std::string> to_string_v1(const P1 &p1, const Param& ... param)
{
  std::vector<std::string> v;
  v.push_back(to_string_impl1(p1));

  const auto remainder = to_string_v1(param...);
  v.insert(v.end(), remainder.begin(), remainder.end());
  return v;
}

// Version 2 - Preferred approach -> no recursion - more efficient in
// compile time and size compared to recursive approach
template<typename ... Param>
std::vector<std::string> to_string_v2(const Param& ... param)
{
  return {to_string_impl1(param)...};
}

// Version 3 - Lambda version - not more efficient in terms of 
// compile time or size compared to version 2
template<typename ... Param>
std::vector<std::string> to_string_v3(const Param& ... param)
{
  const auto to_string_impl = [](const auto &p){
    std::stringstream ss;
    ss << p;
    return ss.str();
  };
  return {to_string_impl(param)...};
}

int main()
{
  //print(1);
  //print("Hello World");
  //print(5.2);

  //std::cout << to_string(1) << "\n";
  //std::cout << to_string("Hello World") << "\n";
  //std::cout << to_string(5.2) << "\n";

  const auto vec1 = to_string_v1("Hello", 1, 5.2, "World");
  std::cout << "-------" << "\n";
  for(const auto &o : vec1)
  {
    std::cout << o << "\n";
  }
  std::cout << "-------" << "\n";

  const auto vec2 = to_string_v2("Test", 7, 27.9, "Program");
  for(const auto &o : vec2)
  {
    std::cout << o << "\n";
  }
  std::cout << "-------" << "\n";

  const auto vec3 = to_string_v3("LambdaTest", 11, 33.9, "LambdaProgram");
  for(const auto &o : vec3)
  {
    std::cout << o << "\n";
  }
  std::cout << "-------" << "\n";
}
