#include <iostream>
#include <type_traits>

// C++14
template<typename ... T>
auto sum(T ... t)
{
  typename std::common_type<T...>::type result{};
  (void)std::initializer_list<int>{ (result += t, 0) ... };
  return result;
}

// C++17
template<typename ... T>
auto sum2(T ... t)
{
  return ( t + ... ); 
}

template<typename ... T>
auto div(T ... t)
{
  return ( t / ... ); 
}

template<typename ... T>
auto div2(T ... t)
{
  return ( ... / t ); 
}

template<typename ... T>
auto avg(T ... t)
{
  return ( t + ... ) / sizeof...(t);
}


int main()
{
  std::cout << sum(1,2,3.0,4,5.0) << "\n";
  std::cout << sum2(1,2,3.0,4,5.0) << "\n";
  std::cout << div(1.0,2.0,3.0) << "\n";	// (3/2)/1
  std::cout << div2(1.0,2.0,3.0) << "\n";	// (1/2)/3
  std::cout << avg(1.0,2.0,3.5) << "\n";
}
