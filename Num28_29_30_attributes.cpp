#include <iostream>
#include <cassert>

// C++ Weekly, 28, 29, 30

void something(); 
int something1(); 
void do_something();
void do_something_else();

void something() {}
void do_something() {}
void do_something_else() {}

// Works for classes, structs, unions, enums, etc.
struct [[nodiscard]] MyError
{
};

MyError something2(); 

MyError something2()
{
  return {};
}

// Presence of attribute generates warning
[[nodiscard]] int something1() 
{
  return 1;
}

int main(int /*argc*/, [[maybe_unused]] const char *argv[])
{
	int j = 1;

	switch(j)
	{
          case 1:
	    do_something();
	    [[fallthrough]]; // Attribute eliminates warning
	  case 2:
	    do_something_else();
	}

	[[maybe_unused]] int i = 6; // Attribute eliminates warning
	//assert( i == 6 );

	something1();
	something2();

	return 0;
}
