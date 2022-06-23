// ** Framework v0.5
#include <iostream>

using namespace std;

// ** 연산자 오버로딩
// ** 가상함수 & 순수가상함수
// ** 오버로딩 & 오버라이딩


// ** 상속
class Parent
{
protected:
	string Name;
public:
	void Output() { cout << Name << endl; }

	Parent() {}
	Parent(string _str) : Name(_str) {}
};

class Child : public Parent
{
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};



int main(void)
{
	// ** 상속
	Child c = Child("Child");
	c.Output();

	Object o = Object("Object");
	o.Output();

	return 0;
}
