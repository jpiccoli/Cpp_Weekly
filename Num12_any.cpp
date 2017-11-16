#include <experimental/any>

#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include <type_traits>




struct S
{
  S(const S &s) = default;
  S() = default;
};

int main()
{
  // Won't work with copy constructor = delete since all objects have to be copy constructible 
  // std::vector< std::experimental::fundamentals_v1::any > v{ 7, 27.7, std::string("Hello World"), S()};
  std::vector< std::experimental::fundamentals_v1::any > v{ 7, 27.7, std::string("Hello World"), S()};

  static_assert( std::is_nothrow_move_constructible<S>::value, "no-throw" );

  std::cout << std::experimental::fundamentals_v1::any_cast<int>( v[0]) << "\n"; 
  std::cout << std::experimental::fundamentals_v1::any_cast<double>( v[1]) << "\n"; 
  std::cout << std::experimental::fundamentals_v1::any_cast<std::string>( v[2] ) << "\n"; 

  std::cout << typeid(v[0]).name() << "\n";
  std::cout << v[0].type().name() << "\n";
  std::cout << v[1].type().name() << "\n";
  std::cout << v[2].type().name() << "\n";

  int *i = std::experimental::fundamentals_v1::any_cast<int>( &v[0] ); 
  *i = 11;
  std::cout << std::experimental::fundamentals_v1::any_cast<int>( v[0]) << "\n"; 

  return 0;
}
