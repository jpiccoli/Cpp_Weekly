#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <functional>

int main()
{
  std::string s = "some rather long string";
  std::string to_find = "ath";

  auto found_at = std::search(s.begin(), s.end(), 
		              to_find.begin(), to_find.end());

  std::cout << std::distance(s.begin(), found_at) << "\n";

  std::vector<int> v = {1,2,3,4,5,6};
  std::vector<int> t = {3,4,5};

  auto found_vec = std::search(v.begin(), v.end(), 
		              t.begin(), t.end());

  std::cout << std::distance(v.begin(), found_vec) << "\n";

  // Not supported by compiler
  /*
  auto found_bm = std::search(s.begin(), s.end(), 
		  std::boyer_moore_searcher(
			  to_find.begin(), to_find.end()));

  std::cout << std::distance(v.begin(), found_bm) << "\n";
  */
}

