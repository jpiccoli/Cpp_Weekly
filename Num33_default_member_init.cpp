#include <iostream>

struct S
{
  // More efficient than using default constructor
  int value = 5;
  //int value{5};
};

int main()
{
  std::cout << S().value << "\n";
  return S().value;
}
