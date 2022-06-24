// ** Framework v0.7
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





const int ObjectID_Child	= 0;
const int ObjectID_Object	= 1;
const int ObjectID_A		= 2;
const int ObjectID_MAX		= 3;


int main(void)
{
	Parent* p[ObjectID_MAX][128];

	for (int i = 0; i < ObjectID_MAX; ++i)
	{
		for (int j = 0; j < 128; ++j)
		{
			p[i][j]->Output();
		}
	}

	for (int j = 0; j < 128; ++j)
	{
		p[ObjectID_Child][j]->Output();
		p[ObjectID_Object][j]->Output();
		p[ObjectID_A][j]->Output();
	}
	
	return 0;
}
