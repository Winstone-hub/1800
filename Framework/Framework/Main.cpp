// ** Framework v0.1
#include <iostream>


// ** namespace 
// ** ������ & �Ҹ��� & ��������� 
// ** �����Լ� & ���������Լ�
// ** �����ε� & �������̵�
// ** ������ �����ε�



struct Info
{
private:
	int iNumber;
};

class Object
{
// ** ����� ���·� ����� ��.
private:
	int iNumber;

// ** ��Ӱ��� ������ ����.
protected:

// ** ������ ���·� ����� ��.
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