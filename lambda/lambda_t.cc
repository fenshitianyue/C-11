#include <iostream>
#include <string>

auto func_args = [](const std::string& s) {
  std::cout << s << std::endl;
};

auto func_non_args = [] {
  std::cout << "call func_non_args()..." << std::endl;
};

int main() {
  func_args("call func_args()..."); 
  func_non_args();
  return 0;
}
