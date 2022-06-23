// ** Framework v0.4
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
	virtual void Output() = 0;

	Parent() {}
	Parent(string _str) : Name(_str) {}
};

class Child : public Parent
{
public:
	void Output()
	{
		cout << Name << endl;
	}
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};


class Object : public Parent
{
public:
	void Output()
	{
		cout << Name << endl;
	}

public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};



int main(void)
{
	// ** 다형성
	Parent* p[2];

	p[0] = new Child("Child");
	p[1] = new Object("Object");

	for (int i = 0; i < 2; ++i)
		p[i]->Output();
		

	return 0;
}
