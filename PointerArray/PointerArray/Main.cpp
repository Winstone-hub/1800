#include <iostream>
#include <vector>

using namespace std;

/*
template <typename T>
class List
{
private:
	T Value;
public:
	void Setter(const T _Value) { Value = _Value; }
	T Getter() const { return Value; }
};


class TempClass
{
public:
	template <typename T>
	T TemplateClass(T _typeValue)
	{
		return _typeValue;
	}
};


// ** 데이터 타입을 전달할 수 있게 해준다.
*/
template <typename T>
class Vector
{
private:
	T* Value;
	int m_size;
	int m_capacity;
public:
	void push_back(T _value)
	{
		if (m_size >= m_capacity)
		{	
			if (m_capacity < 3)
				m_capacity += 1;
			else
				m_capacity += (m_capacity * 0.5f);

			int* Temp = new T[m_size];

			for (int i = 0; i < m_size; ++i)
				Temp[i] = Value[i];

			delete Value;

			Value = new T[m_capacity];

			for (int i = 0; i < m_size; ++i)
				Value[i] = Temp[i];
		}

		Value[m_size] = _value;
		m_size += 1;
	}

	// ** 원하는 위치에 데이터 삽입.
	void insert(int _where, T _value)
	{
		if ((m_size + 1) >= m_capacity)
		{
			if (m_capacity < 3)
				m_capacity += 1;
			else
				m_capacity += (m_capacity * 0.5f);

			int* Temp = new T[m_size];

			for (int i = 0; i < m_size; ++i)
				Temp[i] = Value[i];

			delete Value;

			Value = new T[m_capacity];

			for (int i = 0; i < m_size; ++i)
				Value[i] = Temp[i];
		}

		++m_size;

		for (int i = m_size; i > (_where - 1); --i)
			Value[i] = Value[i - 1];

		Value[_where - 1] = _value;
	}

	// ** 첫번째 원소를 가르키는 함수
	T front() const { return Value[0]; }

	// ** 마지막 원소를 가르키는 함수
	T back() const { return Value[m_size - 1]; }

	// ** 원소삭제
	void erase(int _where)
	{
		for (int i = _where - 1; i < m_size; ++i)
			Value[i] = Value[i + 1];

		m_size--;
	}

	// ** 전체 삭제
	void clear()
	{
		delete Value;
		Value = nullptr;
	}

	int size() const { return m_size; }
	int capacity() const { return m_capacity; }

	void Output(int _where) 
	{ 
		if (_where < m_size)
			cout << Value[_where] << endl;
	}

public:
	Vector()
	{
		m_size = 0;
		m_capacity = 0;
		Value = new T[m_capacity];
	}
};


int main(void)
{
	Vector<int> vecNumbers;

	for (int i = 0; i < 10; ++i)
	{
		vecNumbers.push_back(10 * i + 10);
		vecNumbers.Output(i);
		cout << "size : " << vecNumbers.size() << endl;
		cout << "capacity : " << vecNumbers.capacity() << endl << endl;
	}
	cout << endl;



	vecNumbers.insert(3, 25);


	for (int i = 0; i < vecNumbers.size(); ++i)
		vecNumbers.Output(i);
	cout << endl << endl;


	cout << vecNumbers.front() << endl;
	cout << vecNumbers.back() << endl << endl;


	vecNumbers.erase(3);


	for (int i = 0; i < vecNumbers.size(); ++i)
		vecNumbers.Output(i);
	cout << endl << endl;

	/*********************************************************
	// ** template 은 class에 사용할 경우 class 이름 뒤에 붙혀 사용한다.
	// ** class_name<DataType>
	Vector<int> vecTemp;
	vecTemp.Setter(10);

	cout << vecTemp.Getter() << endl;
	**********************************************************/

	/****************************************************
	List<int> liTemp;
	liTemp.Setter(10);

	cout << liTemp.Getter() << endl;

	******************************************************/

	/****************************************************
	TempClass TC;

	// ** template 은 함수에 사용할 경우 함수 이름 뒤에 붙혀 사용한다.
	// ** Function_name<DataType>()
	cout << TC.TemplateClass<int>(10) << endl;
	******************************************************/

	return 0;
}