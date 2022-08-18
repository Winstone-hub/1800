#include <iostream>
#include <list>
#include <vector>
#include <Windows.h>


using namespace std;


bool Compare(int _Temp, int _Dest);

int main(void)
{
	/*
	// ** iterator (�ݺ���) 1
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6 , 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter + i) << endl;
		cout << endl;
	}
	*/

	/*
	// ** iterator (�ݺ���) 2
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6 , 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter++) << endl;
		cout << endl;
	}
	*/

	/*
	// ** iterator (�ݺ���) 3
	{
		list<int> Numbers;

		Numbers.push_back(10);
		Numbers.push_back(20);
		Numbers.push_back(30);
		Numbers.push_back(40);
		Numbers.push_back(50);

		list<int>::iterator iter = Numbers.begin();

		for (int i = 0; i < 5; ++i)
			cout << *(iter++) << endl;
		cout << endl;
	}
	*/




	/*
	// ** iterator (�ݺ���) 4
	{
		list<int> Numbers;

		Numbers.push_back(10);
		Numbers.push_back(20);
		Numbers.push_back(30);
		Numbers.push_back(40);
		Numbers.push_back(50);

		for (list<int>::iterator iter = Numbers.begin();
			iter != Numbers.end(); ++iter)
			cout << *iter << endl;
		cout << endl;
	}
	*/



	//=====================================================
	//=====================================================



	// ** List Function
	{
		list<int> Numbers;

		// ** ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ** ù��° ���Ҹ� ��ȯ�Ѵ�.
		//Numbers.front();

		// ** �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ** ������ ���Ҹ� ��ȯ�Ѵ�.
		//Numbers.back();



		// ** ������ ��ġ�� ���� �߰��Ѵ�.
		//Numbers.push_back();

		// ** ù��° ��ġ�� ���� �߰��Ѵ�.
		//Numbers.push_front();


		// ** _Where ��ġ�� value ���� ���Խ�Ų��.
		// ** _Where �� �ݺ���
		//Numbers.insert(_Where, value);


		// ** �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����Ѵ�. �׸��� ���� �ݺ��ڸ� ��ȯ�Ѵ�.
		//iter = Numbers.erase(iter);





		// ** ù��° ���� �����Ѵ�. 
		//Numbers.pop_front();

		// ** ������ ���� �����Ѵ�.
		//Numbers.pop_back();

		// ** ��ü ���Ҹ� �����Ѵ�.1
		//Numbers.clear();





		// ** ���� ����� �� ������ ��ȯ�Ѵ�.
		//Numbers.size();

		// ** ����Ʈ�� ���� �ִ��� ������ Ȯ���Ѵ�.
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				cout << "False : �����Ͱ� ���� �˴ϴ�." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : ���" << endl;
				for (list<int>::iterator iter = Numbers.begin()
					; iter != Numbers.end(); ++iter)
					cout << *iter << endl;
			}

			cout << endl;
		}
		*/


		/*
		// ** ����Ʈ�� �����Ѵ�.
		{
			for (int i = 0; i < 10; ++i)
			{
				srand(GetTickCount64() * (i + 1) * GetTickCount64());
				Numbers.push_back(rand()%100 + 1);
			}

			cout << "[������]" << endl;
			for (list<int>::iterator iter = Numbers.begin()
				; iter != Numbers.end(); ++iter)
				cout << *iter << endl;
			cout << endl;

			Numbers.sort(Compare);

			cout << "[������]" << endl;
			for (list<int>::iterator iter = Numbers.begin()
				; iter != Numbers.end(); ++iter)
				cout << *iter << endl;
			cout << endl;
		}
		*/
	}

	

	//=====================================================
	//=====================================================



	// ** vector Function
	{
		vector<int> Numbers;

		// ** ù��° ���Ҹ� ����Ű�� �ݺ���
		//Numbers.begin();

		// ** ù��° ���Ҹ� ��ȯ�Ѵ�.
		//Numbers.front();

		// ** �������� ����Ű�� �ݺ���
		//Numbers.end();

		// ** ������ ���Ҹ� ��ȯ�Ѵ�.
		//Numbers.back();


		// ** ������ ��ġ�� ���� �߰��Ѵ�.
		//Numbers.push_back();


		// ** _Where ��ġ�� value ���� ���Խ�Ų��.
		// ** _Where �� �ݺ���
		//Numbers.insert(_Where, value);


		// ** �ݺ��ڰ� �ִ� ��ġ�� ���Ҹ� �����Ѵ�. �׸��� ���� �ݺ��ڸ� ��ȯ�Ѵ�.
		//iter = Numbers.erase(iter);

		// ** ������ ���� �����Ѵ�.
		//Numbers.pop_back();

		// ** ��ü ���Ҹ� �����Ѵ�.
		//Numbers.clear();





		// ** ���� ����� �� ������ ��ȯ�Ѵ�.
		//Numbers.size();

		// ** ��尡 ���Ե� �� �ִ� ���� ������ ��.
		//Numbers.capacity();

		// ** �迭ó�� ���� ����
		//Numbers[index]


		/*
		// int 
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);

			for (int i = 0; i < 10; ++i)
				cout << Numbers[i] << endl;
		}
		cout << endl;
		*/


		/*
		// size_t
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);

			for (size_t i = 0; i < Numbers.size(); ++i)
				cout << Numbers[i] << endl;
		}
		cout << endl;
		*/


		/*
		// iterator
		{
			for (int i = 0; i < 10; ++i)
				Numbers.push_back(i * 10 + 10);

			for (vector<int>::iterator iter = Numbers.begin()
				; iter != Numbers.end(); ++iter)
				cout << *iter << endl;
		}
		cout << endl;
		*/





		// ** ����Ʈ�� ���� �ִ��� ������ Ȯ���Ѵ�.
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				cout << "False : �����Ͱ� ���� �˴ϴ�." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : ���" << endl;
				for (vector<int>::iterator iter = Numbers.begin()
					; iter != Numbers.end(); ++iter)
					cout << *iter << endl;
			}
			cout << endl;
		}
		*/
	}

	return 0;
}

bool Compare(int _Temp, int _Dest)
{
	return _Temp > _Dest;
}