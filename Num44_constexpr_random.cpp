#include <cstdint>
#include <limits>
#include <iostream>

constexpr uint64_t seed()
{
  uint64_t shifted = 0;

  for( auto const c : __TIME__ )
  {
    shifted <<= 8;
    shifted |= c;
  }

  return shifted;
}

struct PCG
{
  // Get different value every time program is compiled
  struct pcg32_random_t { std::uint64_t state = 0; std::uint64_t inc = seed(); };
  pcg32_random_t rng;
  typedef std::uint32_t result_type;

  constexpr result_type operator()()
  {
    return pcg32_random_r();
  }

  constexpr static result_type min()
  {
    return std::numeric_limits<result_type>::min();
  }
 
  constexpr static result_type max()
  {
    return std::numeric_limits<result_type>::max();
  }

  private:
  constexpr std::uint32_t pcg32_random_r()
  {
    std::uint64_t oldstate = rng.state;

    // Advance internal state
    rng.state = oldstate * 6364136223846793005ULL + (rng.inc|1); 

    // Calculate output function (XSH RR), uses old state for max ILP
    std::uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    std::uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
  }

};

constexpr auto call_random(int i)
{
  PCG pcg;
  while (i > 0) {
    pcg();
    --i;
  }

  return pcg();
}

int main()
{
  std::cout << call_random(11) << "\n";
}
