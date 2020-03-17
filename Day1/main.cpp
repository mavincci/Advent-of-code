#include <iostream>
#include <cmath>

int main() {
  int mass{};
  long long total{};

  while(std::cin >> mass)
    total += std::round(mass / 3) - 2;

  std::cout << total;
  
  return 0;
}
