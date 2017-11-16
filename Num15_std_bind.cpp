#include <iostream>
#include <functional>
#include <string>

// C++ Weekly #15

// std::bind binds parameters to functions

void print(int i)
{
  std::cout << i << "\n";
}

void print2(int i, const std::string& s)
{
  std::cout << i << ' ' << s << "\n";
}

template<typename T>
void print3(T i, const std::string& s)
{
  std::cout << i << ' ' << s << "\n";
}

int main()
{
  // std::bind makes a copy of the argument passed in
  int i = 5;
  const auto f = std::bind(&print, i);
  f();
  i = 6;
  f();	// prints 5 and 5

  int j = 6;
  const auto g = std::bind(&print, std::ref(j));
  g();
  j = 7;
  g(); // prints 6 and 7

  int k = 5;
  const auto h = std::bind(&print2, std::ref(k), std::placeholders::_1);
  h("Hello 1", 3, 4, 5); // std::bind consumes extra arguments
  k = 6;
  h("World 1");

  int m = 5;
  const auto ff = std::bind(&print2, std::placeholders::_2, std::placeholders::_1);
  ff("Hello 2", m);
  m = 6;
  ff("World 2", m);

  // Need to identify type of template function since std::bind needs a concrete
  // function for the argument
  int n = 5;
  const auto gg = std::bind(&print3<int>, std::placeholders::_2, std::placeholders::_1);
  gg("Hello 3", n);
  n = 6;
  gg("World 3", n);

  // std::bind creates a callable item that can be passed to std::function
  std::function<void (const std::string&, int)> f2(gg);
  f2("String", 42); // More strongly typed than std::bind alone
}

















