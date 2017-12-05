#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <functional>

//////////////////////////////////////////////////////
// Lippincott function
//////////////////////////////////////////////////////
// Saves compile time, compile size, runtime by not
// overloading instruction cache if exceptions not
// used for control flow handling.
void lippincott()
{
  try
  {
    throw;
  }
  catch( std::range_error & )
  {
    std::clog << "range error";
  }
  catch( std::runtime_error & )
  {
    std::clog << "runtime error";
  }
  catch( std::bad_function_call & )
  {
    std::clog << "bad function call";
  }
}

//////////////////////////////////////////////////////
// Version 1
//////////////////////////////////////////////////////
void do_thing() {}
void do_thing2() {}

void func()
{
  try
  {
    do_thing();
  }
  catch(...)
  {
    lippincott();
  }
}

void func2()
{
  try
  {
    do_thing2();
  }
  catch(...)
  {
    lippincott();
  }
}

//////////////////////////////////////////////////////
// Version 2
//////////////////////////////////////////////////////
template<typename T>
void func3(T)
{
}

template<typename T>
struct S
{
  static void do_thing()
  {
    try
    {
      func3(T{});
    }
    catch(...)
    {
      lippincott();
    }
  }
};

int main()
{
  S<std::integral_constant<int, 1>> s;
  s.do_thing();
  S<std::integral_constant<int, 2>> s2;
  s2.do_thing();
  S<std::integral_constant<int, 3>> s3;
  s3.do_thing();
  S<std::integral_constant<int, 4>> s4;
  s4.do_thing();
  S<std::integral_constant<int, 5>> s5;
  s5.do_thing();
  S<std::integral_constant<int, 6>> s6;
  s6.do_thing();
}
