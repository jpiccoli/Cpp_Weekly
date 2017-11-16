#include <iostream>
#include <iomanip>

int main()
{
  std::cout << std::quoted( "Say \"Hello World!\"") << "\n"; 

  // auto k = [val = 0] () mutable { val++; };

  auto l = [] () -> int { 
    static auto val = 0;
    val++;
  };

  auto l2 = l;
  l2();
  l2();
  l();
  l();
  std::cout << l() << "\n";









  return 0;
}
