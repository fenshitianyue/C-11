#include <iostream>
#include <utility>

struct S{
  double operator()(char, int&);
};

int main() {
  std::result_of<S(char, int&)>::type foo = 3.14; 
  using MyType = std::result_of<S(char, int&)>::type;
  std::cout << "foo's type is double: " << std::boolalpha << std::is_same<double, MyType>::value << std::endl;
  return 0;
}
