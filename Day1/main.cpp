#include <iostream>
#include <cmath>

int main() {
  int mass{}, temp{};
  long long total{};

  while(std::cin >> mass)
    for(;; mass=temp) {
      temp = std::round(mass / 3) - 2;
      if(temp < 0) break;
      total += temp;
    }

  std::cout << total;
  
  return 0;
}
