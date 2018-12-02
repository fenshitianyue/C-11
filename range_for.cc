#include <iostream>

int main(){
  int arr[] = {1, 2, 3, 4, 5};
  std::cout << "array[] = { ";
  //old
  //for(size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){
  //  std::cout << i
  //            << " ";
  //}
  
  //c++ 11
  for(auto& i : arr){
    std::cout << i
              << " ";
  }
  std::cout << "}" << std::endl;
  return 0;
}
