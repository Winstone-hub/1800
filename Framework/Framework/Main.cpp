// ** Framework v1.0  GetTickCount64
#include <iostream>
#include <Windows.h>

using namespace std;


// ���� 

int main(void)
{
	// ** DWORD unsigned long
	// ** ULONGLONG unsigned __int64

	//					1 / 1000     max �ð� = 49��
	DWORD dwTime = GetTickCount();

	//					1 / 1000     max �ð� = 500��
	ULONGLONG Time = GetTickCount64();

	int i = 0;

	while (true)
	{
		if (Time + 1000 <= GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			cout << ++i << endl;
		}
	}


	return 0;
}