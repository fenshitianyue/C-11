#include <iostream>
#include <memory>
#include <string>

int main() {
  auto p = std::make_shared<int>(42); 
  std::cout << p.use_count() << std::endl;
  auto q(p);
  std::cout << p.use_count() << std::endl; 
  return 0;
}
