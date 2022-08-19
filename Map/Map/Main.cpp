#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;



/*
namespace std
{
	template<typename T1, typename T2>
	class map
	{
	public:
		T1 Key;
		T2 Value;
	};
}
*/


int main(void)
{
	/*
	{
		map<string, int> Number;

		//Number.Key = "홍길동";
		//Number.Value = 32;

		// ** 데이터 삽입 1.
		Number.insert(make_pair("홍길동", 32));
		Number.insert(make_pair("임꺽정", 35));

		// ** 데이터 삽입 2.
		Number["이몽룡"] = 38;


		// **find
		map<string, int>::iterator iter = Number.find("이몽룡");
		cout << iter->second << endl;
	}
	*/

	/*
	{
		{
			//map<string, list<int>> Number;
		}

		{
			//map<string, vector<int>> Number;
		}

		{
			vector<map<int, string>> Number;

			for (int i = 0; i < 10; ++i)
			{
				map<int, string> Temp;
				Temp.insert(make_pair(i, "홍길동 임꺽정"));
				Number.push_back(Temp);

				map<int, string>::iterator iter = Number[i].find(i);

				if(!Number.empty())
					cout << iter->second.find("정") << endl;
			}
		}
	}
	*/






	{
		class Object
		{
		private:
			string Key;
			int Attack;

		public:
			void Initialize() { Key = ""; Attack = rand()%250 + 50; }
			void Render() { cout << "공격력 : " << Attack << endl; }

		public:
			string Getkey() const { return Key; }
			void Setkey(const string& _Key) { Key = _Key; }
			void SetAttack(const int& _Attack) { Attack = _Attack; }
		};



		{
			// ** map 생성
			map<string, list<Object*>> ObjectList;

			// ** 데이터 입력을 위한 반복문
			for (int i = 0; i < 5; ++i)
			{
				// ** 색체 생성
				Object* pObj = new Object;

				// ** 객체 초기화
				pObj->Initialize();

				// ** 객체의 이름을 입력받기 위해
				string str = "";

				// ** 입력
				cout << "이름 입력 : "; cin >> str;

				// ** 입력받은 값으로 아이템 이름을 셋
				pObj->Setkey(str);

				// ** 아이템을 탐색
				map<string, list<Object*>>::iterator iter = ObjectList.find(str);

				// ** 만약 아이템이 없다면....
				if (iter == ObjectList.end())
				{
					// ** 리스트를 새롭게 생성
					list<Object*> TempList;

					// ** 리스트에 아이템을 삽입
					TempList.push_back(pObj);

					// ** 리스트를 map 에 추가
					ObjectList.insert(make_pair(pObj->Getkey(), TempList));
				}
				else // ** 탐색된 키값이 있다면....
					// ** 기존에 삽입된 아이템이 있다는 것이기 때문에 기존 리스트에 push_back
					iter->second.push_back(pObj);
			}
			cout << "** 입력 종료 **" << endl << endl;

			cout << "** 탐색 시작 **" << endl;
			while (true)
			{
				// ** map 자료 탐색
				string str = "";
				cout << "이름 입력 : "; cin >> str;

				if (str == "q")
					break;

				map<string, list<Object*>>::iterator iter = ObjectList.find(str);
				
				if (iter == ObjectList.end())
				{
					cout << "무기가 없습니다." << endl;
					continue;
				}
				else
				{
					iter->second.front()->Render();

				}
			}	
			cout << "** 탐색 종료 **" << endl << endl;
		}
	}


	return 0;
}