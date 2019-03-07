#include <iostream>
#include <thread>

void output(int i){
  std::cout << i << std::endl;
}

int main() {
  for(int i = 0; i < 4; ++i){
    std::thread t(output, i);
    t.detach();
  } 
  return 0;
}
