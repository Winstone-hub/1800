// ** Framework v0.6
#include <iostream>
#include <Windows.h>

using namespace std;

// ** ������ �����ε�


// ** ��� & ������
// ** �����Լ� & ���������Լ�
struct Vector3
{
	float x, y, z;

	Vector3() {}

	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}
};

// ** �����ε� & �������̵�

class Parent // �߻� Ŭ����
{
protected:
	string Name;
public://								���� : �����ε�
	virtual void Output()PURE;	// <������������������������������������ 
	virtual void Output(string _str)PURE; // <����������������   <��������������������������������������������������������������������������������������������������
//																									      ��
	Parent() {}//																						  ��
	Parent(string _str) : Name(_str) {}//																  ��
};//																									  ��
//																							   [���� : ���� ���̵�]
class Child : public Parent//																			  ��
{//																										  ��
public://																	���� : �����ε�				  ��
	virtual void Output() override { cout << "Child : " << Name << endl; }	// <������������������������������������ 		  ��
	virtual void Output(string _str) override { cout << "Child : " << Name << endl; } // <����������������   <����������
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

	p[0] = new Child("ȫ�浿");
	p[1] = new Object("�Ӳ���");
	p[2] = new A("�̸���");


	p[0]->Output();
	p[1]->Output();

	p[2]->Output();

	return 0;
}
