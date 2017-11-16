#include <string>

struct S
{
  S() = default;
  S(const S&) = default;
  S(S&&) = delete;//default;
  ~S() = default;
  S& operator=(S const&) = default;
  S& operator=(S &&) = default;

  std::string s = "Hello world long string";
};

int main()
{
  // If const, below uses regular copy constructor
  const S s;
  
  // Fails if move constructor deleted
  S s2(std::move(s));
}
