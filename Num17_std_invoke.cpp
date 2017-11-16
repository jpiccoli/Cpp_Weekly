#include <iostream>
#include <functional>

int do_something(const int i)
{
  return 5 + i;
}

struct S
{
  int j = 5;

  int do_something(const int i)
  {
    return j + i;
  }

  int do_something_2(const int i)
  {
    return j * i;
  }
};

int main()
{
  std::cout << std::invoke(&do_something, 5) << "\n";
  S s;
  std::cout << s.do_something(3) << "\n";

  auto fp = &S::do_something;
  int (S::*fp2)(int) = nullptr; 

  if (true ) {
    fp2 = &S::do_something_2;
  } else {
    fp2 = &S::do_something;
  }

  std::cout << (s.*fp)(2) << "\n";
  std::cout << (s.*fp2)(1) << "\n";

  // Alternative
  std::cout << std::invoke(&S::do_something  , s, 11) << "\n";
  std::cout << std::invoke(&S::do_something_2, s, 11) << "\n";

  // Can use to access member data
  std::cout << std::invoke(&S::j, s) << "\n";
}
