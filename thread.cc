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


///////////////////////////////////////////////////////
//推荐使用 RAII 机制 
//线程库提供了一个lock_guard模板类
//在某个lock_guard对象的生命周期内，它所管理的对象
//会一直保持上锁状态；当离开生命周期后，它所管理的
//锁对象就会被自动解锁
///////////////////////////////////////////////////////

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

volatile int counter(0);
std::mutex mtx;
void func_3(void){
  for(int i = 0; i < 5; ++i){
    if(mtx.try_lock()){
      ++counter;
      mtx.unlock();
    }
  }
}
void test_4(){
  std::thread threads[5];
  for(int i = 0; i < 10; ++i){
    threads[i] = std::thread(func_3);
  }
  for(auto& t : threads)  t.join();
  std::cout << "count" << counter << std::endl;
}

//并发编程中推荐使用std::unique_lock
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
