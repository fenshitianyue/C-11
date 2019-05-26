#include <iostream>
using namespace std;

typedef void(*PVFT)();

class Base{
public:
	virtual void TestVirtual1(){
		cout << "Base::TestVirtual1()" << endl;
	}
	virtual void TestVirtual2(){
		cout << "Base::TestVirtual2()" << endl;
	}
	virtual void TestVirtual3(){
		cout << "Base::TestVirtual3()" << endl;
	}
	int _data;
};

void PrintVFT(Base& b){
	PVFT* p = (PVFT*)(*((int*)&b));
	while (*p){
		(*p)();
		++p;
	}
}

class Derived : public Base {
public:
	virtual void TestVirtual1(){
		cout << "Derived::TestVirtual1()" << endl;
	}
	virtual void TestVirtual2(){
		cout << "Derived::TestVirtual2()" << endl;
	}
	virtual void TestVirtual3(){
		cout << "Derived::TestVirtual3()" << endl;
	}
};

void TestVirtual(Base& b){
	b.TestVirtual1();
	b.TestVirtual2();
	b.TestVirtual3();
}

void TestPtrVirtual(Base* b){
	b->TestVirtual1();
	b->TestVirtual2();
	b->TestVirtual3();
}

int main(){
	cout << sizeof(Base) << endl;
	Base b;
	b._data = 10;
	//PrintVFT(b);
	TestVirtual(b);
	Derived d;
	TestVirtual(d);
	cout << "--------" << endl;
	//TestPtrVirtual((Base*)&d);
	return 0;
}

