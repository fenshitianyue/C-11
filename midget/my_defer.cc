#include <iostream>
#include <string>
#include <memory>

using defer = std::shared_ptr<void>;

void test() {
  defer _(nullptr, std::bind([]{ std::cout << ",world" << std::endl; }));
  defer n(nullptr, std::bind([]{ std::cout << "test() function exit..." << std::endl; }));
  std::cout << "hello";
}

int main() {
  test();
  return 0;
}
