#include <iostream>
#include <vector>

int main() {
  int inp{};
  char dummy;
  std::vector<int> buff;
  while(std::cin >> inp >> dummy) {
    buff.push_back(inp);
  }
  buff.push_back(inp);
  buff[1] = 12;
  buff[2] = 2;
  
  for(auto i{0}; i<buff.size(); ++i) {
    if(buff[i] == 1) {
      buff[buff[i+3]] = buff[buff[i+1]] + buff[buff[i+2]];
      i += 3;
      continue;
    } else if(buff[i] == 2) {
      buff[buff[i+3]] = buff[buff[i+1]] * buff[buff[i+2]];
      i += 3;
      continue;
    } else if(buff[i] == 99) {
      break;
    }
  }

  for(auto i: buff)
    std::cout << i <<',';

  return 0;
}
