#include <iostream>
#include <cstring>

template<typename T>
const T& Max(const T& left, const T& right){
  return left > right ? left : right;
}

//特化版本
template<>
char* const& Max<char*>(char* const& left, char* const& right){
  if(strcmp(left, right) > 0)
    return left;
  return right;
}

int main(){
  const char* p1 = "hello";
  const char* p2 = "world";
  std::cout << Max(p1, p2) << std::endl;
  std::cout << Max("hello", "world") << std::endl;
  return 0;
}
