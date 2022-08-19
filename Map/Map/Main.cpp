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






	{
		class Object
		{
		private:
			string Key;
			int Attack;

		public:
			void Initialize() { Key = ""; Attack = rand()%250 + 50; }
			void Render() { cout << "���ݷ� : " << Attack << endl; }

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
				map<string, list<Object*>>::iterator iter = ObjectList.find(str);

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

				if (str == "q")
					break;

				map<string, list<Object*>>::iterator iter = ObjectList.find(str);
				
				if (iter == ObjectList.end())
				{
					cout << "���Ⱑ �����ϴ�." << endl;
					continue;
				}
				else
				{
					iter->second.front()->Render();

				}
			}	
			cout << "** Ž�� ���� **" << endl << endl;
		}
	}


	return 0;
}