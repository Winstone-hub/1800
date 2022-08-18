#include <iostream>
#include <list>
#include <vector>
#include <Windows.h>


using namespace std;


bool Compare(int _Temp, int _Dest);

int main(void)
{
	/*
	// ** iterator (반복자) 1
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6 , 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter + i) << endl;
		cout << endl;
	}
	*/

	/*
	// ** iterator (반복자) 2
	{
		int Array[8] = { 1, 2, 3, 4, 5, 6 , 7, 8 };

		int* iter = Array;

		for (int i = 0; i < 8; ++i)
			cout << *(iter++) << endl;
		cout << endl;
	}
	*/

	/*
	// ** iterator (반복자) 3
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
	// ** iterator (반복자) 4
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

		// ** 첫번째 원소를 가르키는 반복자
		//Numbers.begin();

		// ** 첫번째 원소를 반환한다.
		//Numbers.front();

		// ** 마지막을 가르키는 반복자
		//Numbers.end();

		// ** 마지막 원소를 반환한다.
		//Numbers.back();



		// ** 마지막 위치에 값을 추가한다.
		//Numbers.push_back();

		// ** 첫번째 위치에 값을 추가한다.
		//Numbers.push_front();


		// ** _Where 위치에 value 값을 포함시킨다.
		// ** _Where 은 반복자
		//Numbers.insert(_Where, value);


		// ** 반복자가 있는 위치에 원소를 삭제한다. 그리고 다음 반복자를 반환한다.
		//iter = Numbers.erase(iter);





		// ** 첫번째 원소 삭제한다. 
		//Numbers.pop_front();

		// ** 마지막 원소 삭제한다.
		//Numbers.pop_back();

		// ** 전체 원소를 삭제한다.1
		//Numbers.clear();





		// ** 현재 노드의 총 개수를 반환한다.
		//Numbers.size();

		// ** 리스트에 값이 있는지 없는지 확인한다.
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				cout << "False : 데이터가 삽입 됩니다." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : 출력" << endl;
				for (list<int>::iterator iter = Numbers.begin()
					; iter != Numbers.end(); ++iter)
					cout << *iter << endl;
			}

			cout << endl;
		}
		*/


		/*
		// ** 리스트를 정렬한다.
		{
			for (int i = 0; i < 10; ++i)
			{
				srand(GetTickCount64() * (i + 1) * GetTickCount64());
				Numbers.push_back(rand()%100 + 1);
			}

			cout << "[정렬전]" << endl;
			for (list<int>::iterator iter = Numbers.begin()
				; iter != Numbers.end(); ++iter)
				cout << *iter << endl;
			cout << endl;

			Numbers.sort(Compare);

			cout << "[정렬후]" << endl;
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

		// ** 첫번째 원소를 가르키는 반복자
		//Numbers.begin();

		// ** 첫번째 원소를 반환한다.
		//Numbers.front();

		// ** 마지막을 가르키는 반복자
		//Numbers.end();

		// ** 마지막 원소를 반환한다.
		//Numbers.back();


		// ** 마지막 위치에 값을 추가한다.
		//Numbers.push_back();


		// ** _Where 위치에 value 값을 포함시킨다.
		// ** _Where 은 반복자
		//Numbers.insert(_Where, value);


		// ** 반복자가 있는 위치에 원소를 삭제한다. 그리고 다음 반복자를 반환한다.
		//iter = Numbers.erase(iter);

		// ** 마지막 원소 삭제한다.
		//Numbers.pop_back();

		// ** 전체 원소를 삭제한다.
		//Numbers.clear();





		// ** 현재 노드의 총 개수를 반환한다.
		//Numbers.size();

		// ** 노드가 삽입될 수 있는 여유 공간의 수.
		//Numbers.capacity();

		// ** 배열처럼 접근 가능
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





		// ** 리스트에 값이 있는지 없는지 확인한다.
		//Numbers.empty();

		/*
		for (int i = 0; i < 2; ++i)
		{
			if (Numbers.empty())
			{
				cout << "False : 데이터가 삽입 됩니다." << endl;
				Numbers.push_back(10);
			}
			else
			{
				cout << "True : 출력" << endl;
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