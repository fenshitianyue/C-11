#include <iostream>
#include <memory>
#include <string>


int main() {
  std::shared_ptr<int> p = std::make_shared<int>(42); 
  std::cout << *p << std::endl;

  std::shared_ptr<std::string> pStr = std::make_shared<std::string>("0000");
  std::cout << *pStr << std::endl;

  std::shared_ptr<int> pInt = std::make_shared<int>(); // 默认初始化为0
  std::cout << *pInt << std::endl;

  auto pau = std::make_shared<std::string>("auto"); //使用auto来推导智能指针返回的数据类型更为常见
  std::cout << *pau << std::endl;
  return 0;
}
