#include <iostream>
#include <memory>

// Additional code start
int factorial(int num)
{
  if(num == 0 || num == 1)
    return 1;

  return num*factorial(num-1);
}

int fib_recursive(int num)
{
  if( num == 0 || num == 1 )
    return num;

   return fib_recursive(num-1) + fib_recursive(num-2);
}

int fib_iterative(int num)
{
  if( num == 0 || num == 1 )
    return num;

  auto val_prev1 = 1;
  auto val_prev2 = 1;
  auto result = 1;

  for(auto i = 3; i <= num; ++i )
  {
    result = val_prev1 + val_prev2;
    val_prev2 = val_prev1;
    val_prev1 = result;
  }

  return result;
}

// Fibonacci via lambda with additional call for last value
int fib_lambda1(int num)
{
  if( num == 0 )
    return num;

  auto n = [r = 0, s = 1]() mutable {
    r = std::exchange(s, s+r);
    return r;
  };

  for( int i = 0; i < num - 1; ++i ) { n(); }

  return n();
}

// Fibonacci via lambda with cached result
int fib_lambda2(int num)
{
  if( num == 0 )
    return num;

  auto ans = 0;

  auto n = [r = 0, s = 1]() mutable {
    r = std::exchange(s, s+r);
    return r;
  };

  for( int i = 0; i < num; ++i ) { ans = n(); }

  return ans;
}
// Additional code end

int main()
{
  int i = 1;
  
  // Can omit parenthesis if no arguments
  auto j = [&i] { return ++i; };

  // mutable keyword required because i passed by value
  // If "mutable" present, parenthesis are required 
  auto k = [i] () mutable { return ++i; };

  // Stateful lambda - creating and mutating variable inside lambda
  // Count of how many times lambda is called
  auto l = [j = 0] () mutable { return ++j; };

  l();
  l();
  std::cout << "l = " << l() << "\n"; // Prints "3"

  // lambda cannot be copied due to unique pointer
  auto m = [q = 0, p = std::make_unique<int>(2)] () mutable { return ++q; };
  m();
  m();
  std::cout << "m = " << m() << "\n"; // Prints "3"

  // BASIS for generating fibonacci sequence
  auto n = [w = 0, x = 1]() mutable {
    w = std::exchange(x, x+w);
    return w;
  };

  for( int i = 0; i < 10; ++i ) { n(); }
  std::cout << "n = " << n() << "\n"; // Prints "89"

  std::cout << "fib_lambda1 12 = "   << fib_lambda1(12)   << "\n"; //Prints "144"
  std::cout << "fib_lambda2 12 = "   << fib_lambda2(12)   << "\n"; //Prints "144"
  std::cout << "fib_recursive 12 = " << fib_recursive(12) << "\n"; //Prints "144"
  std::cout << "fib_iterative 12 = " << fib_iterative(12) << "\n"; //Prints "144"

  std::cout << "factorial = " << factorial(5) << "\n"; //Prints "120"

  return l();
}
