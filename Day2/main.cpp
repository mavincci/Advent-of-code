#include <iostream>
#include <vector>

int main() {
  long long inp{};
  char dummy;
  std::vector<int> buff;

  while(std::cin >> inp >> dummy)
    buff.push_back(inp);
    
  buff.push_back(inp);

  std::vector<int> temp(buff.size());

  std::copy(buff.begin(), buff.end(), temp.begin());

  for(auto c1{0}; c1<=99; ++c1) {
    for(auto c2{0}; c2<=99; c2++) {
      buff[1] = c1;
      buff[2] = c2;
      
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

      if(buff[0] == 19690720) {
	c1 = 100;
	c2 = 100;
	break;
      }

      std::copy(temp.begin(), temp.end(), buff.begin());
    }
  }

  std::cout << (100 * buff[1]) + buff[2] << '\n';
  
  return 0;
}
