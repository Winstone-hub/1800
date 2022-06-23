// ** Framework v0.1
#include <iostream>


// ** namespace 
// ** 생성자 & 소멸자 & 복사생성자 
// ** 가상함수 & 순수가상함수
// ** 오버로딩 & 오버라이딩
// ** 연산자 오버로딩



struct Info
{
private:
	int iNumber;
};

class Object
{
// ** 비공개 형태로 만들어 줌.
private:
	int iNumber;

// ** 상속간의 접근이 가능.
protected:

// ** 공개된 형태로 만들어 줌.
public:
	int zzz;

public:
	void Setter(int _Number) { iNumber = _Number; }
	int Getter() { return iNumber; }
};

/*
class Object
{


};
*/



int main(void)
{
	Object o1, o2;
	
	o1.Setter(10);
	o2.Setter(20);

	std::cout << o1.Getter() << std::endl;
	std::cout << o2.Getter() << std::endl;
	

	return 0;
}