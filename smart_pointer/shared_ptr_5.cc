#include <iostream>
#include <memory>
#include <string>

using namespace std;

shared_ptr<string> factory(string&& p) {
  return make_shared<string>(p);
}

void use_factory() {
  shared_ptr<string> p = factory("hello world");
  cout << *p << endl;
}

shared_ptr<string> ret_shared_ptr() {
  auto p = factory("hello world");
  cout << *p << endl;
  return p;
}

int main() {
  use_factory();
  auto p = ret_shared_ptr();
  cout << p.use_count() << endl;
  return 0;
}
