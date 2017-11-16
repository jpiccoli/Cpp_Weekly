#include <iostream>
#include <vector>
#include <list>

int main()
{
  // Sequence Containers: array, vector, deque, forward_list, list
  // Supports polymorphic allocator in C++17

  std::vector<std::vector<int>> v, w, x;
  
  // v.push_back(std::vector<int>());
  // Replaces above
  v.emplace_back();
  w.emplace_back(3, 1);
  //new_vec.push_back(4);

  // Compiler doesn't support
  //auto &new_vec1 = x.emplace_back(3,1).push_back(4);
  //new_vec1.push_back(4);
  //x.emplace_back(3,1).push_back(4);

  // Returns reference to object created inside the container
  std::list<int> l;
  l.emplace_front(2);

  // Returns iterator since C++11
  std::list<int>::iterator i = l.emplace(l.begin(), 5);
}
