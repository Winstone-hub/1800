#include <iostream>
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


	return 0;
}