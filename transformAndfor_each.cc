#include <iostream>
#include <vector>
#include <algorithm>

void func_transform(){
  std::vector<int> ve{1, -2, 3, -4, 5, -6};
  std::transform(ve.begin(), ve.end(), ve.begin(), 
                 [](int n) { if(n < 0) return -n; else return n;  });
  for(const auto& it : ve){
    std::cout << it << " ";
  }
  std::cout << std::endl;
}

void func_for_each(){
  std::vector<int> ve{1, -2, 3, -4, 5, -6};
  std::for_each(ve.begin(), ve.end(), 
                [](int& n){ if(n < 0) n = -n; });
  for(const auto& it : ve){
    std::cout << it << " ";
  }
  std::cout << std::endl;
}
int main() {
  func_transform();
  std::cout << "------------------" << std::endl;
  func_for_each();
  return 0;
}
