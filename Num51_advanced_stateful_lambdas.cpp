#include <iostream>
#include <memory>


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

int main()
{
  // BASIS for generating fibonacci sequence
  auto fib = [a = 0, b = 1]() mutable {
    struct Results 
    {
      int &a;
      int &b;

      // Version 1
      //Results next() 
      //{ 
      //  a = std::exchange(b, b+a);
      //  return *this;
      //}

      // Version 2
      // There is a bug here - gives the value for one number greater
      Results next(int num = 1) 
      { 
	while(num > 0)
	{
          a = std::exchange(b, b+a);
          --num;
	}
	return *this;
      }

      // NOT recommended
      operator int()
      {
	return a;
      }
    };
    return Results{a, b}.next();
  };

  // Find fibonacci of 12
 
  // Explcit return value
  //for( int i = 0; i < 11; ++i ) { fib(); }
  //std::cout << "fib = " << fib().a << "\n"; // Prints "144"

  // Implied return value
  //for( int i = 0; i < 11; ++i ) { fib(); }
  //std::cout << "fib = " << fib() << "\n"; // Prints "144"

  std::cout << "fib = " << fib().next(11) << "\n"; // Prints "144"

  std::cout << "fib_lambda1 12 = "   << fib_lambda1(12)   << "\n"; //Prints "144"
  std::cout << "fib_lambda2 12 = "   << fib_lambda2(12)   << "\n"; //Prints "144"
}
