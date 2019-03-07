#include <iostream>
#include <mutex>

//懒汉模式
template <typename T>
class singleton_l{
  volatile static T* inst;
  static std::mutex lock;
public:
  static T* get_instance(){
    if(NULL == inst){
      lock.lock();
      if(NULL == inst){
        inst = new T();
      }
      lock.unlock();
    }
    return inst;
  }
};

//饿汉模式
template<typename T>
class singleton_e{
private:
  static T data;
public:
  static T* get_instance(){
    return &data;
  }
};

int main(){
  return 0;
}
