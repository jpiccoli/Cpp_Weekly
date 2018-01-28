#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

struct MyData
{
  std::string key;
  std::string value;
};

// User-defined comparator function
// Applies to multiset, map, multimap
struct Compare
{
  bool operator()(const MyData &lhs, const MyData &rhs)
  {
    return lhs.key < rhs.key;
  }
};
    
int main()
{
  std::set<MyData, Compare> myset;
  myset.insert(MyData{"Bob"});
}
