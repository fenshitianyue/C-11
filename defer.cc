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

#include <cstdio>

int main(){
  FILE* fp = fopen("/bin/ls", "r");
  if (NULL == fp) {
    return 1;
  }
  DEFER { fclose(fp); };
  FILE* fp1 = fopen("/bin/ls", "r");
  DEFER {
    if (fp1) {
      printf("fclose(fp1)\n");
      fclose(fp1);
    }
  };
  printf("exit\n");
  return 0;
}
