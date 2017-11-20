// C++ Weekly #88
// Created: 11/19/2017

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <sstream>
#include <utility>
#include <cstdio>

int main()
{
  std::cout << "Hello World\n";

  // Automatic conversion to std::puts if '\n' is present
  std::printf("Hello World\n");

  // More efficient than using iostream for string + newline
  // Requires a null terminated string
  // Won't work for std::string_view
  std::puts("Hello World");
}
