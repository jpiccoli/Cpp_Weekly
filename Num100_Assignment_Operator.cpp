#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

struct S
{
  // Possible
  S &operator=(const S &) & = default;
  S &operator=(S &&) & = default;
  S &operator=(S &) & = default;

  S &operator=(const S &) && = default;
  S &operator=(S &&) && = default;
  S &operator=(S &) && = default;

  // Not possible
  S &operator=(const S &&) & = delete;
  S &operator=(const S &&) && = delete;
};

int main()
{
  S s{};
  S s2{};
  S s3{};
  s = s2;
  s = std::move(s3);
}

