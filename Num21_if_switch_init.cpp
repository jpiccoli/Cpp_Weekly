#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> make_vec()
{
   return {1,2,3,4};
}

int main()
{
  auto vec = make_vec();

  const auto iter1 = std::find(vec.begin(), vec.end(), 2);
  if (iter1 != vec.end())
  {
    *iter1 = 3;
  }
  else
  {
    const auto front = vec.front();
    if (front == 2)
    {
      vec.insert(iter1, 4);
    }
    else
    {
      return front;
    }
  }


  // Equivalent, but not supported by compiler yet
  //if (const auto iter3 = std::find(vec.begin(), vec.end(), 2);
  //   iter3 != vec.end())
  //{
  //  *iter3 = 3;
  //}
  //else if (const auto front = vec.front(); front != 2) 
  //{
  //  vec.insert(iter3, 4);
  // }
  //else
  //{
  // return front;
  //}

  //switch(const auto obj = get_obj();
  //	obj.value()) {
	  //
  //}

}
