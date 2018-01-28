#include <vector>
#include <string>
#include <set>
#include <iostream>

struct Person
{
  std::string name;
};

template<typename T, typename Comparator>
auto make_set(Comparator &&comparator)
{
  return std::set<T, std::decay_t<Comparator>>{std::forward<Comparator>(comparator)};
}

int main()
{
  std::cout << "Just a test" << '\n';

  auto set1 = make_set<Person>([](const Person &lhs, const Person& rhs)
                               { return lhs.name < rhs.name; });
}
