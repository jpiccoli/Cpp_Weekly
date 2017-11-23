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

int main()
{
  int i = 1;
  
  // Can omit parenthesis if no arguments
  auto k = [&i] { return ++i; };

  // mutable keyword required because i passed by value
  // Parenthesis also required in this case
  auto l = [i] () mutable { return ++i; };

  // Creating and mutating variable inside lambda
  // Count of how many times lambda is called
  auto m = [j = 0] () mutable { return ++j; };
  
  auto n = []{ return 5; }();

  auto o = []{ return 5; };
 
  // Create and invoke in the same expression
  std::cout << Lambda()() << "\n";

  // Parenthesis required
  std::cout << m() << "\n";

  // Parenthesis not allowed since are included in lambda definition
  std::cout << n << "\n";

  // Parenthesis required
  std::cout << o() << "\n";

  return []{ return 5; }();
}
