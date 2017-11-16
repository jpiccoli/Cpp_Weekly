#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <future>

std::set<int> make_sorted_random( size_t const& num_elems )
{
  std::set<int> retval;

  std::random_device rd;
  std::mt19937 gen( rd() );
  std::uniform_int_distribution<> dis( 0, num_elems - 1 );

  std::generate_n( std::inserter( retval, retval.end() ), num_elems,
			  [&]() { return dis(gen); });

  return retval;
}

int main()
{
  // std::cout << std::async( make_sorted_random(1000000).get().size() << "\n";
  // std::cout << std::async( make_sorted_random, 1000000).get().size() << "\n";

  // Does not block. Also may be faster since runtime should spawn new threads 
  //auto f1 = std::async( std::launch::async, make_sorted_random, 1000000);
  //auto f2 = std::async( std::launch::async, make_sorted_random, 1000000);
  //std::future<std::set<int>> f3 = std::async( std::launch::async, make_sorted_random, 1000000);
 
  // std::launch::async not necessary but slower since does not ALWAYS spawn a new thread
  // Thread creation is runtime decision
  // Default is std::launch::async | std::launch::deferred if flags not included
  auto f1 = std::async(make_sorted_random, 1000000);
  auto f2 = std::async(make_sorted_random, 1000000);
  std::future<std::set<int>> f3 = std::async( make_sorted_random, 1000000);
  auto f4 = std::async( std::launch::deferred, make_sorted_random, 1000000);
  auto f5 = std::async( std::launch::deferred, make_sorted_random, 1000000);


  // f4 and f5 never called since not requested with std::launch::deferred
  std::cout << f1.get().size() << " " << f2.get().size() << " " << f3.get().size() << "\n";

  // Call to "get()" is blocking
  //std::cout << std::async(make_sorted_random, 1000000).get().size();
  //std::cout << " ";
  //std::cout << std::async(make_sorted_random, 1000000).get().size();
  //std::cout << "\n"; 
}
