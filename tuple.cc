#include <iostream>
#include <tuple>

///////////////////////////////////////////////////////
//std::make_tuple : 构造元组
//std::get : 获取元组指定位置的值
//std::tie : 元组拆包
///////////////////////////////////////////////////////

auto get_student(int id) ->std::tuple<double, char, std::string>{
  if(0 == id) {
    return std::make_tuple(3.0, 'A', "小明");
  } else if (1 == id) {
    return std::make_tuple(2.9, 'B', "小乐");
  } else if (2 == id) {
    return std::make_tuple(1.1, 'C', "小王");
  } 
  return std::make_tuple(0.0, 'D', "null");
}

int main() {
  auto student = get_student(0);  
  std::cout << "ID : 0, "
            << "GPA : " << std::get<0>(student) << ", "
            << "GRADE : " << std::get<1>(student) << ", "
            << "NAME : " << std::get<2>(student)
            << std::endl;
  double gpa;
  char grade;
  std::string name;
  std::tie(gpa, grade, name) = get_student(1); //tuple 拆包
  std::cout << "ID : 1, "
            << "GPA : " << gpa << ", "
            << "GRADE : " << grade << ", "
            << "NAME : " << name
            << std::endl;
  //C++14 标准增加了使用类型获取元组中的成员
  //std::tuple<std::string, double, double, int> test("test", 2.1, 3.4, 9527);
  //std::cout << std::get<std::string>(test) << std::endl;
  //std::cout << std::get<double>(test) << std::endl; //冲突，编译期错误
  //std::cout << std::get<int>(test) << std::endl;
  return 0;
}
