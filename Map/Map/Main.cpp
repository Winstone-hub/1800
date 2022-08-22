#include <iostream>
#include <Windows.h>
#include <string>
#include <math.h>
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





	/*
	{
		class Object
		{
		private:
			string Key;
			int Attack;

		public:
			void Initialize()
			{
				Key = "";
				srand(GetTickCount64());
				Attack = rand() % 250 + 50;
			}

			void Render() { cout << "공격력 : " << Attack << " " << endl; }

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
				map<string, list<Object*>>::iterator iter = ObjectList.find(pObj->Getkey());

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

				// ** 반복문 종료 구문
				if (str == "q")
					break;

				// ** 입력한 문자열을 탐색한다.
				map<string, list<Object*>>::iterator iter = ObjectList.find(str);

				// ** 만약 탐색한 문자열이 없다면....
				if (iter == ObjectList.end())
				{
					cout << "무기가 없습니다." << endl;
					continue;
				}
				else
				{
					// ** 키값이 존재 한다면 해당 키값의 리스트를 모두 돌면서
					for (list<Object*>::iterator iter2 = iter->second.begin();
						iter2 != iter->second.end(); ++iter2)
					{
						// ** 출력 한다.
						(*iter2)->Render();
					}
					cout << endl;
				}
			}
			cout << "** 탐색 종료 **" << endl << endl;
		}
	}
	*/

	//============================================================================
	//============================================================================
	
	int i = 0;
	/*
	{
		multimap<string, int> strList;

		strList.insert(make_pair("홍길동", 1));
		strList.insert(make_pair("홍길동", 2));
		strList.insert(make_pair("홍길동", 3));
		strList.insert(make_pair("홍길동", 4));
		strList.insert(make_pair("홍길동", 5));
		strList.insert(make_pair("홍길동", 6));
		strList.insert(make_pair("홍길동", 7));
		strList.insert(make_pair("홍길동", 8));
		strList.insert(make_pair("홍길동", 9));
		strList.insert(make_pair("홍길동", 10));

		for (multimap<string, int>::iterator iter = strList.begin() ;
				iter != strList.end(); ++iter)
		{
			cout << iter->first << " : " << iter->second << endl;
		}
	}
	*/

	{
		class Vector3
		{
		public:
			float x, y, z;

			Vector3() : x(0), y(0), z(0) {}
			Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}
			Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		};


		class Object
		{
		private:
			string Key;
			Vector3 Position;

			Object* Target;
		public:
			void Initialize()
			{
				Key = "";

				Target = nullptr;

				srand(GetTickCount64() * ((rand() + 100) % rand() + 1));

				Position = Vector3(
					rand() % 50 + 1 ,
					rand() % 50 + 1 );
			}

			void Render() 
			{ 
				cout << "X : " << Position.x << endl;
				cout << "Y : " << Position.y << endl << endl;
			}

		public:
			string Getkey() const { return Key; }
			void Setkey(const string& _Key) { Key = _Key; }
			void SetTarget(Object* _Target) { Target = _Target; }
			Vector3 GetPosition() const { return Position; }
			void SetPosition(const float &_x, const float &_y) { Position = Vector3(_x, _y); }
		};

		Object* Player = new Object;
		Player->SetPosition(25.0f, 25.0f);


		multimap<float, Object*> ObjectList;

		for (int i = 0; i < 20; ++i)
		{
			// ** 색체 생성
			Object* pObj = new Object;

			// ** 객체 초기화
			pObj->Initialize();

			pObj->SetTarget(Player);

			// ** "Enemy" 값으로 객체 이름을 셋
			pObj->Setkey("Enemy");


			// ** 삼각 함수
			float X = pObj->GetPosition().x - Player->GetPosition().x;
			float Y = pObj->GetPosition().y - Player->GetPosition().y;

			float D = sqrt((X * X) + (Y * Y));


			// ** 거리를 키값으로 사용
			ObjectList.insert(make_pair(D, pObj));
		}

		// ** 출력
		for (multimap<float, Object*>::iterator iter = ObjectList.begin();
			iter != ObjectList.end(); ++iter)
		{
			cout << "Player 와의 거리 : " << iter->first << endl;
			iter->second->Render();
		}

		// ** Player와 제일 가까운 Enemy를 Target로 설정.
		multimap<float, Object*>::iterator iter = ObjectList.begin();
		Player->SetTarget((*iter).second);
	}

	return 0;
}