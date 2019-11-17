#include <iostream>

///////////////////////////////////////////////////////
// 思路：
//    1.通过填充lambda表达式的函数体来实现将任何语句封装成一个可调用对象
//    2.将可调用对象作为模板类的成员，在析构函数中调用这个成员，这样就起到了在
//      作用域结束后自动调用指定语句的作用
///////////////////////////////////////////////////////

template <typename T>
class _Defer {
  public:
    _Defer(T&& d) : _d(std::move(d)){}  
    ~_Defer() { _d(); }
  private:
    T _d;
};

class Defer {
  public:
    template <typename T>
    _Defer<T> operator+(T&& d) {
      return _Defer<T>(std::forward<T>(d));
    }
};

#define CONCAT(perfix, suffix) prefix##suffix  // 拼接变量名
#define UNIQUE_NAME(prefix) CONCAT(prefix, __COUNTER__)  // 保证变量名不会重复，让我们可以在同一个作用域调用多个defer
#define DEFER auto UNIQUE_NAME(defer_) = Defer() + [&]

void test() {
  DEFER { std::cout << "func exit!" << std::endl;  };
}

int main(){
  std::cout << "Call test() function..." << std::endl;
  test();
  return 0;
}
