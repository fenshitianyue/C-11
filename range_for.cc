#include <iostream>

int main(){
  int arr[] = {1, 2, 3, 4, 5};
  std::cout << "array[] = { ";
  //c++ 11
  for(auto& i : arr){
    std::cout << i
              << " ";
  }
  std::cout << "}" << std::endl;
  return 0;
}
