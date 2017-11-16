#include <iostream>
#include <memory>

// Equivalent to lambda function
struct Lambda
{
  auto operator()() const
  {
    return 5;
  }
};

int factorial(int num)
{
  if(num == 0 || num == 1)
    return 1;

  return num*factorial(num-1);
}

int fib_recursive(int num)
{
  if( num == 0 || num == 1 )
    return 1;

   return fib_recursive(num-1) + fib_recursive(num-2);
}

int fib(int num)
{
  auto n = [r = 0, s = 1]() mutable {
    r = std::exchange(s, s+r);
    return r;
  };

  for( int i = 0; i < num; ++i ) { n(); }

  return n();
}

int main()
{
  int i = 1;
  
  // Can omit parenthesis if no arguments
  auto k = [&i] { return ++i; };

  // mutable keyword required because i passed by value
  // Parenthesis also required in this case
  //auto l = [i] () mutable { return ++i; };

  // Creating and mutating variable inside lambda
  // Count of how many times lambda is called
  auto l = [j = 0] () mutable { return ++j; };

  //return []{ return 5; }();
  //return Lambda()();
  l();
  l();
  l();
  std::cout << "l = " << l() << "\n"; // Prints "4"

  auto m = [q = 0, p = std::make_unique<int>(2)] () mutable { return ++q; };
  m();
  m();
  std::cout << "m = " << m() << "\n"; // Prints "3"

  std::cout << "fib = " << fib(11) << "\n"; //Prints "144"

  std::cout << "fib_recursive = " << fib_recursive(11) << "\n"; //Prints "144"

  std::cout << "factorial = " << factorial(5) << "\n"; //Prints "120"

  return l();
}
