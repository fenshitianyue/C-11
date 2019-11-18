#include <iostream>
#include <string>
#include <memory>

int main() {
  /*--------- 空指针 ----------*/
  // std::shared_ptr<std::string> p1;  //默认初始化的智能指针中保存的是一个空指针，而不是""
  // if (!p1)
  //   std::cout << "p1 is NULL" << std::endl;
  /*--------- 初始化 ----------*/
  // std::shared_ptr<std::string> p2(new std::string);
  // if (p2 && p2->empty()) { //empty属于string的成员函数，而不是智能指针的操作
  //   *p2 = "hello world";
  //   std::cout << *p2 << std::endl;
  // } 
  // std::shared_ptr<int> p3 = new int(1);  //不允许以暴露裸露的指针进行赋值操作
  
  //一般的初始化方式
  std::shared_ptr<std::string> p4(new std::string("hello world"));
  std::cout << *p4 << std::endl;

  return 0;
}
