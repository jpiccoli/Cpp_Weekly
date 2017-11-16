#include <type_traits>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <iostream>

// clang eliminates stack array
// gcc inline capability not as good
template<typename ... T>
int sum( T ... t )
{
  std::common_type_t<T...> array[sizeof...(T)]{t...};
  return std::accumulate(std::begin(array), std::end(array), 0);
}

int main()
{
  // "array" eliminated from final code
  int array[1000];
  array[0] = 5;
  array[999] = 11;
  // return array[0] + array[999];

  std::cout << sum( 9, 8, 7 ,6, 5, 4, 3, 2, 1) << "\n";

  return sum( 9, 8, 7 ,6, 5, 4, 3, 2, 1);
}
