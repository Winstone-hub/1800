// ** Framework v0.8
#include <iostream>
#include <Windows.h>

using namespace std;


// ** [&] 사용 용도
// ** 1. 2항 연산자로 사용
// **	- & <- 1번만 쓰였다면 [비트연산]
// **	- && <- 2번 쓰였다면 [비교연산 & 논리연산]

// ** 2. 단항 연산자로 사용
// **	- &변수 <- 변수 앞쪽에 붙은경우 [주소반환 연산자]
// **	- 자료형(형태)& <- 자료현 뒷쪽에 붙은 경우 [레퍼런스 연산자] 

/*
int Add(const int& _i)
{
	return _i + 1;
}

int main(void)
{
	int i = 10;
	int n = Add(i);
	cout << n << endl;

	return 0;
}
*/






// ** 연산자 오버로딩
// ** Operator

/*
class Object
{
private:
	int Number;

public:
	int GetNumber() { return Number; }


	Object& operator+=(Object& _obj)
	{
		this->Number += _obj.Number;
		return (*this);
	}
	Object& operator+=(int _number)
	{
		this->Number += _number;
		return (*this);
	}

	Object operator+(Object _Obj)
	{
		return Object(this->Number + _Obj.Number);
	}
	
public:
	Object() {}
	Object(int _number) : Number(_number) { }
	~Object() {}
};
*/






/*
class Vector3
{
private:
	float x, y, z;
public:
	void Output()
	{
		cout << x << ", " << y << ", " << z << endl;
	}
	Vector3 operator+(Vector3 _v1)
	{
		return Vector3(
			this->x + _v1.x, 
			this->y + _v1.y, 
			this->z + _v1.z);
	}
public:
	Vector3() {}
	Vector3(float _x, float _y, float _z) 
		: x(_x) , y(_y) , z(_z) { }
	~Vector3() {}
};
*/




int main(void)
{
	/*
	int i1(1), i2(2);
	i1 += i2;
	i1 += 7;
	cout << i1 << endl;
	*/





	

	/*
	Object o1(1), o2(2);
	//o1 += o2;
	//o1 += 7;
	//++o1;

	Object o3 = o1 + o2;

	cout << o3.GetNumber() << endl;
	*/









	/*
	Vector3 V1, V2;

	V1 = Vector3(10, 20, 30);
	V2 = Vector3(100, 200, 300);

	Vector3 V3 = V1 + V2;

	V3.Output();
	*/

	return 0;
}
