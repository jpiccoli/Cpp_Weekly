#include <iostream>
#include <functional>

template<typename T>
void print(T i, const std::string& s)
{
  std::cout << i << ' ' << s << "\n";
}

int main()
{
  int i = 5;
  // const auto f = std::bind(&print<int>, std::placeholders::_2, std::placeholders::_1);
  const auto f = [](const std::string &arg1, auto &&arg2) {
    print(arg2, arg1);
  }; 

  // Lambda eliminates need for explicit template instantation that is required
  // by std::bind
  f("Float", 1.3);
  f("Hello", i);
  i = 6;
  f("World", i);

  //std::function<void (const std::string&, int)> f2(f);
  //f2("String", i); // More strongly typed than std::bind alone

  //const auto ff = [](auto &&arg1, auto &&arg2, auto && ...) {
  //  print(arg2, arg1);
  //}; 

  //ff("Hello variadic", i, 5);
  //i = 7;
  //ff("World variadic", i);	// doesn't work => gcc compiler bug

}

