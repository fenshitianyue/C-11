#include <iostream>
#include <memory>

class Bad{
public:
  std::shared_ptr<Bad> getptr(){
    return std::shared_ptr<Bad>(this);
  }
  ~Bad(){std::cout << "Bad::~Bad() called" << std::endl;}
};

class Nice : public std::enable_shared_from_this<Nice> {
public:
  std::shared_ptr<Nice> getptr(){
    return shared_from_this();
  } 
  ~Nice(){ std::cout << "Bad::~Bad() callded" << std::endl;  }
};

void test_1(){
  std::shared_ptr<Bad> bp1(new Bad()); 
  std::shared_ptr<Bad> bp2 = bp1->getptr();
  std::cout << "bp1.use_count():" << bp1.use_count() << std::endl;
  std::cout << "bp2.use_count():" << bp2.use_count() << std::endl;
}

void test_2(){
  std::shared_ptr<Nice> bp1(new Nice()); 
  std::shared_ptr<Nice> bp2 = bp1->getptr();
  std::cout << "bp1.use_count():" << bp1.use_count() << std::endl;
  std::cout << "bp2.use_count():" << bp2.use_count() << std::endl;
}

int main() {
  //test_1();
  test_2(); 
  return 0;
}
