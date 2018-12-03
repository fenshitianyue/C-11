#include <iostream>
#include <array>
void foo(int *p, int len) {
    for (int i = 0; i != len; ++i) {
        std::cout << p[i] << std::endl;
    }
}

int main() {
    std::array<int, 3> arr= {1,2,3};
    
    //int len = 4;
    //std::array<int, len> arr = {1,2,3,4}; // 非法，数组大小必须是常量表达式
    
    //和C风格数组的接口
    // foo(arr, arr.size());           // 非法，无法隐式转换
    foo(&arr[0], arr.size());
    foo(arr.data(), arr.size());
    
    return 0;
}
