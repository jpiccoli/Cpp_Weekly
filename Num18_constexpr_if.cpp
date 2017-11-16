#include <iostream>
#include <type_traits>
#include <limits>

template<typename T>
constexpr bool is_both()
{
  if constexpr(std::is_integral<T>::value && 
              !std::is_same<bool, T>::value) 
  {
    if constexpr(std::numeric_limits<T>::max() < 1000)
      return true;
  }

  return false;
}

template<typename T>
auto print_type_info(const T&t)
{
  // Compiler must evaluate entire expression for all types
  // if constexpr(std::is_integral<T>::value && 
  //            !std::is_same<bool, T>::value) 
  // {
    // if constexpr(std::numeric_limits<T>::max() < 1000)
    //  return t+1;
    // Compile time error if below is not present because "void"
    // is returned => no "return" statement with expression
    // else
    //  return t+100;
    //
  //  Workaround
  if constexpr(is_both<T>())
  {
    return t+1;
  }
  else if constexpr(std::is_floating_point<T>::value)
  {
    return t+0.1;
  } 
  else 
  {
    return t;
  }
}

int main()
{
  std::cout << print_type_info(5) << "\n";
  std::cout << print_type_info(5ll) << "\n";
  std::cout << print_type_info(1.2) << "\n";
  std::cout << print_type_info(true) << "\n";
  std::cout << print_type_info("Hello") << "\n";
}
