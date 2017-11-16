#include <iostream>

struct B
{
  double q;
};

struct R : B 
{
  int i;
  float f;
};

struct S
{
  int i;
  float f;
};

int main()
{
  S s{1, 1.1};	   // Added in C++11

  // Default initialization of struct B => Added in C++17
  R r{{}, 1, 2.3};

  // Explicit initialization of struct B => Added in C++17
  R rr{{54.8}, 1, 2.3};

  std::cout << "rr.q + rr.f = " << static_cast<int>(rr.q + rr.f) << "\n";

  return r.q;
}
