#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std::placeholders;

//升序排序
bool isShoter(const std::string& s1, const std::string& s2){
  return s1.size() < s2.size();
}

int main() {
  std::vector<std::string> ve{"a", "aa", "aaa", "aaaa"}; 
  //升序排序
  std::sort(ve.begin(), ve.end(), isShoter);
  std::for_each(ve.begin(), ve.end(),
                [](const std::string& s){std::cout << s << " ";});
  std::cout << std::endl;
  std::cout << "-----" << std::endl;
  //降序排序
  std::sort(ve.begin(), ve.end(), bind(isShoter, _2, _1));
  std::for_each(ve.begin(), ve.end(),
                [](const std::string& s){std::cout << s << " ";});
  std::cout << std::endl;
  return 0;
}
