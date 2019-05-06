//此文件的作用是测试g++对C++11标准的支持程度
//编译命令：g++ filename.cc -std=c++11
//如果编译后的可执行程序运行出错，表示当前版本的g++对C++11标准支持并不完全，需要升级至少至4.9以上的版本

#include <iostream>
#include <regex>


int main() {
  std::regex r1("S");
  std::cout << "S works." << std::endl;
  std::regex r2(".");
  std::cout << ". works." << std::endl;
  std::regex r3(".+");
  std::cout << ".+ works." << std::endl;
  std::regex r4("[0-9]");
  std::cout << "[0-9] works." << std::endl;
  return 0;
}
