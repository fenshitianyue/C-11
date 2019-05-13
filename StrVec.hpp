#pragma once

#include <iostream>
#include <string>
#include <memory>

class StrVec{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){}
  StrVec(const StrVec&);
  StrVec& operator=(const StrVec&);
  ~StrVec(){
    free();
  }
  void push_back(const std::string&);
  inline size_t size() const {
    return first_free - elements;
  }
  inline size_t capacity() const {
    return cap - elements;
  }
  inline std::string* begin() const {
    return elements;
  }
  inline std::string* end() const {
    return first_free;
  }

private:
  static std::allocator<std::string> alloc; 
  void reallocate();
  void check_n_alloc(){
    if(size() == capacity()){
      reallocate();
    }
  }
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
  void free();

private:
  std::string* elements;
  std::string* first_free;
  std::string* cap;
};

