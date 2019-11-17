#include <iostream>
#include <string>
#include <memory>

int main() {
  /*--------- 空指针 ----------*/
  // std::shared_ptr<std::string> p1; 
  // if (!p1)
  //   std::cout << "p1 is NULL" << std::endl;
  /*--------- 初始化 ----------*/
  std::shared_ptr<std::string> p2(new std::string);
  if (p2 && p2->empty()) {
    *p2 = "hello world";
    std::cout << *p2 << std::endl;
  } 
  
  

  return 0;
}
