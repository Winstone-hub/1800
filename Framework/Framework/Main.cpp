// ** Framework v0.6
#include <iostream>
#include <Windows.h>

using namespace std;

// ** 연산자 오버로딩


// ** 상속 & 다형성
// ** 가상함수 & 순수가상함수
struct Vector3
{
	float x, y, z;

	Vector3() {}

	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}
};

// ** 오버로딩 & 오버라이딩

class Parent // 추상 클래스
{
protected:
	string Name;
public://								관계 : 오버로딩
	virtual void Output()PURE;	// <─────────────────┐ 
	virtual void Output(string _str)PURE; // <───────┘   <────────────────────────────────────────────────┐
//																									      │
	Parent() {}//																						  │
	Parent(string _str) : Name(_str) {}//																  │
};//																									  │
//																							   [관계 : 오버 라이딩]
class Child : public Parent//																			  │
{//																										  │
public://																	관계 : 오버로딩				  │
	virtual void Output() override { cout << "Child : " << Name << endl; }	// <─────────────────┐ 		  │
	virtual void Output(string _str) override { cout << "Child : " << Name << endl; } // <───────┘   <────┘
	void Input() {  }
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};


class A : public Child
{
public:
	virtual void Output() override { cout << "A : " << Name << endl; }
	virtual void Output(string _str) override { cout << "A : " << Name << endl; }
public:
	A() {}
	A(string _str) : Child(_str) {}
};







class Object : public Parent
{
public:
	virtual void Output() { cout << "Object : " << Name << endl; }
	virtual void Output(string _str) override { cout << "Object : " << Name << endl; }
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};



int main(void)
{
	Parent* p[3];

	p[0] = new Child("홍길동");
	p[1] = new Object("임꺽정");
	p[2] = new A("이몽룡");


	p[0]->Output();
	p[1]->Output();

	p[2]->Output();

	return 0;
}
