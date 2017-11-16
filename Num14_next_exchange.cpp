#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

int main()
{
  std::vector<int> v{1,2,3,4,5,6,7};

  std::cout << std::is_sorted(v.begin(), v.end()) << "\n";

  std::vector<int> v1{3,2,3,4,5,6,7};
  auto iter = std::begin(v1); 
  ++iter;

  std::cout << std::is_sorted(iter, v1.end()) << "\n";

  std::list<int> l{3,2,3,4,5,6,7};
  // Won't compile since list iterators are not random access
  //std::cout << std::is_sorted(l.begin()+1,l.end()) << "\n";

  std::cout << std::is_sorted(std::next(v1.begin()), v1.end()) << "\n";


  auto a = 27;
  auto b = std::exchange( a, 29 );
  std::cout << "a = " << a << "\n";	// Prints "29"
  std::cout << "b = " << b << "\n";     // Prints "27"

  return 0;
}
