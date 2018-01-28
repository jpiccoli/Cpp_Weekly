#include <iostream>
#include <vector>

struct ThrowingThing
{
  ThrowingThing(int i)
  {
    if( i > 2 )
      throw i;
  }
};

struct S
{
  // Can't escape from function try block of a constructor
  // without throwing an exception
  S(int val) try : tt(val)
  {
  }
  catch(int)
  {
    std::cout << "Caught the exception\n";
  }

  ThrowingThing tt;
};

int main()
{
  // s not left in a valid state
  S s{5};
}
