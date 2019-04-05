#include <iostream>
#include <map>
#include <random>


int
main ()
{
  std::map<int, double> m;

  std::random_device generator;
  std::uniform_int_distribution<int> intdist (0, 100);
  std::uniform_real_distribution<double> doubdist (0.0, 1.0);

  for (int ii = 0; ii < 10; ++ii)
    m[intdist (generator)] = doubdist (generator);

  std::cout << "initial contents" << std::endl;
  for (auto& jj : m)
    std::cout << jj.first << " " << jj.second << std::endl;
std::map<int, double> m2(m);
  for (auto jj = m2.begin (); jj != m2.end (); ++jj)
    if (jj->second < .5)
      m.erase (jj->first);

  std::cout << "final contents" << std::endl;
  for (auto& jj : m)
    std::cout << jj.first << " " << jj.second << std::endl;

}
