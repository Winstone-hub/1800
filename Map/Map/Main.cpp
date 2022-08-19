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

		//Number.Key = "È«±æµ¿";
		//Number.Value = 32;

		// ** µ¥ÀÌÅÍ »ğÀÔ 1.
		Number.insert(make_pair("È«±æµ¿", 32));
		Number.insert(make_pair("ÀÓ²©Á¤", 35));

		// ** µ¥ÀÌÅÍ »ğÀÔ 2.
		Number["ÀÌ¸ù·æ"] = 38;


		// **find
		map<string, int>::iterator iter = Number.find("ÀÌ¸ù·æ");
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
				Temp.insert(make_pair(i, "È«±æµ¿ ÀÓ²©Á¤"));
				Number.push_back(Temp);

				map<int, string>::iterator iter = Number[i].find(i);

				if(!Number.empty())
					cout << iter->second.find("Á¤") << endl;
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
			void Render() { cout << "°ø°İ·Â : " << Attack << endl; }

		public:
			string Getkey() const { return Key; }
			void Setkey(const string& _Key) { Key = _Key; }
			void SetAttack(const int& _Attack) { Attack = _Attack; }
		};



		{
			map<string, list<Object*>> ObjectList;

			for (int i = 0; i < 5; ++i)
			{
				Object* pObj = new Object;
				pObj->Initialize();

				string str = "";
				cout << "ÀÌ¸§ ÀÔ·Â : "; cin >> str;
				pObj->Setkey(str);

				map<string, list<Object*>>::iterator iter = ObjectList.find(str);

				if (iter == ObjectList.end())
				{
					list<Object*> TempList;
					TempList.push_back(pObj);

					// **map µ¥ÀÌÅÍ »ğÀÔ
					ObjectList.insert(make_pair(pObj->Getkey(), TempList));
				}
				else
					iter->second.push_back(pObj);
			}
			cout << "** ÀÔ·Â Á¾·á **" << endl << endl;


			cout << "** Å½»ö ½ÃÀÛ **" << endl;
			while (true)
			{
				// ** map ÀÚ·á Å½»ö
				string str = "";
				cout << "ÀÌ¸§ ÀÔ·Â : "; cin >> str;

				if (str == "q")
					break;

				map<string, list<Object*>>::iterator iter = ObjectList.find(str);
				
				if (iter == ObjectList.end())
				{
					cout << "¹«±â°¡ ¾ø½À´Ï´Ù." << endl;
					continue;
				}
				else
				{
					iter->second.front()->Render();

				}
			}	
			cout << "** Å½»ö Á¾·á **" << endl << endl;
		}
	}


	return 0;
}