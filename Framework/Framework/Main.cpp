#pragma once
// ** Framework v2.2
#include "MainUpdate.h"
#include "Singleton.h"

Singleton* Singleton::Instance = nullptr;

int main(void)
{
	// ** ���ʿ� ������ �ʱ�ȭ.
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 30 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			// ** ������� �� �浹 ���� �̺�Ʈ üũ
			Main.Update();

			// ** �׸���
			Main.Render();


			cout << Singleton::GetInstance()->Number << endl;
		}
	}


	return 0;
}