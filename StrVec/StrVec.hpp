#pragma once

#include <iostream>
#include <string>
#include <memory>

class StrVec{
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){}
  StrVec(const StrVec&);
  StrVec& operator=(const StrVec&);
  ~StrVec();
  void push_back(const std::string&);
  inline size_t size() const;
  inline size_t capacity() const;
  inline std::string* begin() const;
  inline std::string* end() const; 

private:
  void reallocate();
  void check_n_alloc();
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
  void free();

private:
  static std::allocator<std::string> alloc; 
  std::string* elements;
  std::string* first_free;
  std::string* cap;
};

