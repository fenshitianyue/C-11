#include "StrVec.hpp"

///////////////////////////////////////////////////////
//工具函数
void StrVec::free(){
  if(elements){
    std::string* dst = first_free;
    for(size_t i = 0; i != size(); ){
      alloc.destroy(--dst); 
    }
    alloc.deallocate(elements, first_free - elements);
  }
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* begin, const std::string* end){
  auto data = alloc.allocate(end - begin);
  return {data, std::uninitialized_copy(begin, end, data)};
}

void StrVec::reallocate(){
  ///////////////////////////////////////////////////////
  // 1.确定新的容量大小
  // 2.分配新空间
  // 3.将旧空间上的元素移动到新空间
  // 4.释放旧空间
  // 5.重新确定类成员指针指向
  ///////////////////////////////////////////////////////
  auto new_capacity = size() ? size() * 2 : 1;
  auto new_data = alloc.allocate(new_capacity);
  auto dest = new_data;
  for(auto tmp = elements; tmp != first_free;){
    alloc.construct(dest++, std::move(*tmp++));
  }
  free();
  elements = new_data;
  first_free = dest;
  cap = new_data + new_capacity;
}

void StrVec::check_n_alloc(){
  if(size() == capacity()){
    reallocate();
  }
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//接口
void StrVec::push_back(const std::string& s){
  check_n_alloc();
  alloc.construct(first_free++, s);
}

size_t StrVec::size() const {
  return first_free - elements;
}

size_t StrVec::capacity() const {
  return cap - elements;
}

std::string* StrVec::begin() const {
  return elements;
}

std::string* StrVec::end() const {
  return first_free;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//拷贝构造函数
StrVec::StrVec(const StrVec& sv){
  auto new_data = alloc_n_copy(sv.begin(), sv.end());
  elements = new_data.first;
  first_free = new_data.second;
}

//赋值运算符重载函数
StrVec& StrVec::operator=(const StrVec& sv){
  auto data = alloc_n_copy(sv.begin(), sv.end());
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

//析构函数
StrVec::~StrVec(){
  free();
}
///////////////////////////////////////////////////////
