#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <functional>

struct Person
{
  std::string name;
};

int main()
{
  std::cout << "Just a test" << '\n';

  // Original standalone lambda
  auto comparator = [](const Person &lhs, const Person& rhs) { return lhs.name < rhs.name; };

  // Function pointer declaration
  using fp = bool (*)(const Person &lhs, const Person& rhs);

  // Convert lambda to function pointer
  fp myFP = comparator;

  // Original with lambda
  std::set<Person, decltype(comparator)> set1{std::move(comparator)};

  // Use function pointer with concrete function that is a lambda
  std::set<Person, fp> set2{std::move(comparator)};

  // Use function pointer with "embedded" lambda
  std::set<Person, fp> set3{[](const Person &lhs, const Person& rhs) { return lhs.name < rhs.name; }};

  //std::vector<std::function<int (int, int)>> ops_on_ints;

  // Supposedly more efficient - avoids type erasure (?)
  std::vector<int (*)(int, int)> ops_on_ints;
  ops_on_ints.emplace_back([](int i, int j){return i * j;});
}
