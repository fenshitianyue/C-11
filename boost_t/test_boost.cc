#include <iostream>
#include <vector>
#include <string>
#include "util.hpp"

int main() {
  std::vector<std::string> first_line;  
  std::string line("GET /wwwroot/index.html HTTP/1.1");
  StringUtil::Split(line, " ", &first_line);
  for(const auto &it : first_line){
    std::cout << it << std::endl;
  }
  return 0;
}
