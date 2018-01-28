#include <vector>
#include <string>
#include <set>
#include <iostream>

struct MyData
{
  std::string key;
  std::string value2;
};

struct Compare
{
  bool operator() (const MyData & lhs, const MyData & rhs) const
  {
    return lhs.key < rhs.key;
  }

  template<typename T>
  bool operator() (const MyData & lhs, const T & str) const
  {
    return lhs.key < str;
  }

  template<typename T>
  bool operator() (const T & str, const MyData & rhs) const
  {
    return str < rhs.key;
  }

  //bool operator() (const MyData & lhs, const std::string & str) const
  //{
  //  return lhs.key < str;
  //}

  //bool operator() (const std::string & str, const MyData & rhs) const
  //{
  //  return str < rhs.key;
  //}

  // Allows use of a type that is comparable with a container's key type
  // instead of the key type itself.OA
  using is_transparent = int;
};

int main()
{
  std::cout << "Just a test" << '\n';

  std::set<MyData, Compare> myset;
  myset.insert(MyData{"Bob"});
  //return myset.count(MyData{"Bob"}) > 0;
  return myset.count("Bob") > 0;	// Uses string comparator
}

