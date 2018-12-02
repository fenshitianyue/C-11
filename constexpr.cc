#include <iostream>

//c++14 standard
//constexpr int fibonacci(const int n){
//  if(n == 0) return 1;
//  if(n == 1) return 1;
//  return fibonacci(n - 1) + fibonacci(n - 2);
//}

//c++11 standard
//constexpr int fibonacci(const int n ){
//  return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
//}

//c++11 standard
//constexpr int len(){
//  return 2;
//}

int len_old(){
  return 2;
}

int main(){
  //std::cout << "fibonacci(3) = ";
  //std::cout << fibonacci(3) << std::endl;
  int arr_old[len_old() + 3];
  //int arr[len() + 3]; 
  return 0;
}
