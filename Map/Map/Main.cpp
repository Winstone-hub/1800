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

		//Number.Key = "ȫ�浿";
		//Number.Value = 32;

		// ** ������ ���� 1.
		Number.insert(make_pair("ȫ�浿", 32));
		Number.insert(make_pair("�Ӳ���", 35));

		// ** ������ ���� 2.
		Number["�̸���"] = 38;


		// **find
		map<string, int>::iterator iter = Number.find("�̸���");
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
				Temp.insert(make_pair(i, "ȫ�浿 �Ӳ���"));
				Number.push_back(Temp);

				map<int, string>::iterator iter = Number[i].find(i);

				if(!Number.empty())
					cout << iter->second.find("��") << endl;
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

			void Render() { cout << "���ݷ� : " << Attack << " " << endl; }

		public:
			string Getkey() const { return Key; }
			void Setkey(const string& _Key) { Key = _Key; }
			void SetAttack(const int& _Attack) { Attack = _Attack; }
		};

		{
			// ** map ����
			map<string, list<Object*>> ObjectList;

			// ** ������ �Է��� ���� �ݺ���
			for (int i = 0; i < 5; ++i)
			{
				// ** ��ü ����
				Object* pObj = new Object;

				// ** ��ü �ʱ�ȭ
				pObj->Initialize();

				// ** ��ü�� �̸��� �Է¹ޱ� ����
				string str = "";

				// ** �Է�
				cout << "�̸� �Է� : "; cin >> str;

				// ** �Է¹��� ������ ������ �̸��� ��
				pObj->Setkey(str);

				// ** �������� Ž��
				map<string, list<Object*>>::iterator iter = ObjectList.find(pObj->Getkey());

				// ** ���� �������� ���ٸ�....
				if (iter == ObjectList.end())
				{
					// ** ����Ʈ�� ���Ӱ� ����
					list<Object*> TempList;

					// ** ����Ʈ�� �������� ����
					TempList.push_back(pObj);

					// ** ����Ʈ�� map �� �߰�
					ObjectList.insert(make_pair(pObj->Getkey(), TempList));
				}
				else // ** Ž���� Ű���� �ִٸ�....
					// ** ������ ���Ե� �������� �ִٴ� ���̱� ������ ���� ����Ʈ�� push_back
					iter->second.push_back(pObj);
			}
			cout << "** �Է� ���� **" << endl << endl;

			cout << "** Ž�� ���� **" << endl;
			while (true)
			{
				// ** map �ڷ� Ž��
				string str = "";
				cout << "�̸� �Է� : "; cin >> str;

				// ** �ݺ��� ���� ����
				if (str == "q")
					break;

				// ** �Է��� ���ڿ��� Ž���Ѵ�.
				map<string, list<Object*>>::iterator iter = ObjectList.find(str);

				// ** ���� Ž���� ���ڿ��� ���ٸ�....
				if (iter == ObjectList.end())
				{
					cout << "���Ⱑ �����ϴ�." << endl;
					continue;
				}
				else
				{
					// ** Ű���� ���� �Ѵٸ� �ش� Ű���� ����Ʈ�� ��� ���鼭
					for (list<Object*>::iterator iter2 = iter->second.begin();
						iter2 != iter->second.end(); ++iter2)
					{
						// ** ��� �Ѵ�.
						(*iter2)->Render();
					}
					cout << endl;
				}
			}
			cout << "** Ž�� ���� **" << endl << endl;
		}
	}
	*/

	//============================================================================
	//============================================================================
	
	int i = 0;
	/*
	{
		multimap<string, int> strList;

		strList.insert(make_pair("ȫ�浿", 1));
		strList.insert(make_pair("ȫ�浿", 2));
		strList.insert(make_pair("ȫ�浿", 3));
		strList.insert(make_pair("ȫ�浿", 4));
		strList.insert(make_pair("ȫ�浿", 5));
		strList.insert(make_pair("ȫ�浿", 6));
		strList.insert(make_pair("ȫ�浿", 7));
		strList.insert(make_pair("ȫ�浿", 8));
		strList.insert(make_pair("ȫ�浿", 9));
		strList.insert(make_pair("ȫ�浿", 10));

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
			// ** ��ü ����
			Object* pObj = new Object;

			// ** ��ü �ʱ�ȭ
			pObj->Initialize();

			pObj->SetTarget(Player);

			// ** "Enemy" ������ ��ü �̸��� ��
			pObj->Setkey("Enemy");


			// ** �ﰢ �Լ�
			float X = pObj->GetPosition().x - Player->GetPosition().x;
			float Y = pObj->GetPosition().y - Player->GetPosition().y;

			float D = sqrt((X * X) + (Y * Y));


			// ** �Ÿ��� Ű������ ���
			ObjectList.insert(make_pair(D, pObj));
		}

		// ** ���
		for (multimap<float, Object*>::iterator iter = ObjectList.begin();
			iter != ObjectList.end(); ++iter)
		{
			cout << "Player ���� �Ÿ� : " << iter->first << endl;
			iter->second->Render();
		}

		// ** Player�� ���� ����� Enemy�� Target�� ����.
		multimap<float, Object*>::iterator iter = ObjectList.begin();
		Player->SetTarget((*iter).second);
	}

	return 0;
}