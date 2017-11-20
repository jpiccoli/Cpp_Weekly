#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// C++03
int &add_local_03(std::map<std::string, int> vars, const std::string &new_var_name)
{
  std::pair<std::map<std::string, int>::iterator, bool> new_var 
    = vars.insert(std::make_pair(new_var_name, 0));

  if(new_var.second == false)
  {
    throw std::runtime_error("Variable already exists");
  }
  else
  {
    return new_var.first->second;
  }
}

// C++11
int &add_local_11(std::map<std::string, int> vars, const std::string &new_var_name)
{
   auto new_var = vars.insert(std::make_pair(new_var_name, 0));

  if(new_var.second == false)
  {
    throw std::runtime_error("Variable already exists");
  }
  else
  {
    return new_var.first->second;
  }
}

struct S
{
  int i = 4;
  int j = 5;
};

// C++17 - requires clang++ compiler
int &add_local_17(std::map<std::string, int> vars, const std::string &new_var_name)
{
  if( auto [itr, success] = vars.insert(std::make_pair(new_var_name, 0));
	success == false )
  {
    throw std::runtime_error("Variable already exists");
  }
  else
  {
    auto [key, value] = *itr;
    return value;
  }
}

int main()
{
  std::map<std::string, int> locals;

  int &i = add_local_03(locals, "my_var");

  i = 5;

  auto [x, y] = S();

  return i;
}

