#include <iostream>
#include <memory>
#include <array>
#include <utility>
#include <cmath>

int fib_recursive(int num)
{
  if( num == 0 ) 
    return 0;

  if( num == 1 ) 
    return 1;

   return fib_recursive(num-1) + fib_recursive(num-2);
}

int fib_lambda(int num)
{
  auto n = [r = 0, s = 1]() mutable {
    r = std::exchange(s, s+r);
    return r;
  };

  for( int i = 0; i < num-1; ++i ) { n(); }

  return n();
}

template<int I>
struct fib_template
{
  static const int val = fib_template<I-1>::val + fib_template<I-2>::val;
};

template<>
struct fib_template<0>
{
  static const int val = 0;
};

template<>
struct fib_template<1>
{
  static const int val = 1;
};

template <size_t ... I>
int fib_impl(std::index_sequence<I...>, const int i)
{
  constexpr std::array<int, sizeof...(I)> a
   = { fib_template<I>::val... };

  return a[i];
}

int fib_compile_time(const int i)
{
  return fib_impl(std::make_index_sequence<47>(), i);
}

constexpr int fib_binet(int i)
{
  if( i == 0 ) 
    return 0;

  if( i == 1 ) 
    return 1;

  constexpr auto sqrt_5 = sqrt(5);

  return static_cast<int>( ( pow( 1 + sqrt_5, i ) - pow( 1 - sqrt_5, i ) ) /
	   ( pow( 2, i ) * sqrt_5 ) ); 
}

int main()
{

  // 10 => 55
  // std::cout << "fib = " << fib(10) << "\n";

  std::cout << "fib_recursive = " << fib_recursive(10) << "\n";

  // Problem: Can only use template version if argument is known
  // at compile time. Argument must be a constant expression.
  // Also: using constexpr with recursion doesn't help.
  // Value of 46 is upper limit that will fit in an integer.
  std::cout << "fib_template = " << fib_template<10>::val << "\n";

  // Very complex solution
  std::cout << "fib_compile_time = " << fib_compile_time(10) << "\n";

  std::cout << "fib_binet = " << fib_binet(10) << "\n";
}















