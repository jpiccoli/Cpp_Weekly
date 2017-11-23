#include <iostream>
#include <memory>
#include <future>

int main()
{
  auto l = [] () { 
	  static auto val = 0;
	  return val++; 
  };

  // Two lambdas share same static variable. Also not thread safe.
  auto l2 = l;

  // Force to run in separate thread
  auto f = std::async(std::launch::async, l);
  f.get();

  l2();
  l2();
  l();
  l();

  // Output is "5"
  std::cout << "l = " << l() << "\n"; 

  auto m = [] () { 
	  thread_local auto val = 0;
	  return val++; 
  };

  auto m2 = m;

  // Force to run in separate thread
  auto g = std::async(std::launch::async, m);
  g.get();

  m2();
  m2();
  m();
  m();

  // Output is "4" since threaded version is separate
  std::cout << "m = " << m() << "\n";
}
