#include <iostream>
#include <typeinfo>

auto divider = [] {
  for(auto i = 0; i < 10; ++i) std::cout << '-';
  std::cout << std::endl;
};

int main() {
  auto a = 10; 
  std::cout << typeid(a).name() << std::endl;
  divider();
  auto b = 1.2;
  std::cout << typeid(b).name() << std::endl;
  return 0;
}
