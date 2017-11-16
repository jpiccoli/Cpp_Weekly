#include <iostream>
#include <algorithm>

namespace org {
  namespace group {
    namespace project {
      namespace internal {
	struct MyStruct {
	};
      }	
    }
  }
}

// C++17
namespace org::group::project::internal {
  struct MyStruct1{ };
}

int main(const int argc, const char *[])
{
  org::group::project::internal::MyStruct s;
  org::group::project::internal::MyStruct1 s1;

  std::cout << ((argc < 2)?2:(argc > 5)?5:argc) << "\n";

  // C++17
  // Not supported in compiler
  // std::cout << std::clamp( argc, 2, 5 ) << "\n";
}

