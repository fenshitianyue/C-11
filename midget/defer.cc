#include <iostream>
#include <utility>

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

#define PP_CONCAT_IMPL(perfix, suffix) prefix##suffix
#define PP_CONCAT(prefix, suffix) PP_CONCAT_IMPL(prefix, suffix)
#define UNIQUE_NAME(prefix) PP_CONCAT(prefix, __COUNTER__)
#define DEFER auto UNIQUE_NAME(defer_) = Defer() + [&]

void test() {
  DEFER { std::cout << "func exit!" << std::endl;  };
}

int main(){
  std::cout << "Enter main function->" << std::endl;
  std::cout << "Call test() function..." << std::endl;
  test();
  return 0;
}
