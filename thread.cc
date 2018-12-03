#include <iostream>
#include <thread>
#include <mutex>

void func_1(void){
  std::cout << "thread 1" << std::endl;
}

void test_1(void){
  std::thread t1(func_1);
  t1.join();
}

///////////////////////////////////////////////////////
// 互斥量对象 std::mutex
// 手动上锁 lock()
// 手动解锁 unlock()
///////////////////////////////////////////////////////


//推荐使用 RAII 机制
void test_2(const std::string& s){
  static std::mutex mutex;
  std::lock_guard<std::mutex> lock(mutex);
  std::cout << s << std::endl;
  //some operation
  ///////////////////////////////////////////////////////
  // 在这个函数的内部被认为是临界区，离开了这个函数
  // 互斥锁就会被自动解开
  ///////////////////////////////////////////////////////
}

//并发编程中推荐使用std::unique_lock
std::mutex mtx;
void func_2(void){
  std::unique_lock<std::mutex> lock(mtx);
  //一下函数作用域内为临界区
}

void test_3(void){
  std::thread t3(func_2);
  t3.join();
}

int main() {
  //test1();
  //test2();
  //test3();
  
  return 0;
}
