#include <iostream>
#include <string>
#include <typeinfo>

auto func_args = [](const std::string& s) {
  std::cout << s << std::endl;
};

auto func_non_args = [] {
  std::cout << "call func_non_args()..." << std::endl;
};

int main() {
  func_args("call func_args()..."); 
  func_non_args();
  
  std::cout << "func_args type is: "<< typeid(func_args).name() << std::endl;
  std::cout << "func_non_args type is: " << typeid(func_non_args).name() << std::endl;
  return 0;
}
