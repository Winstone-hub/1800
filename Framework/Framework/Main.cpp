#pragma once
// ** Framework v10.1    ObjectFactory
#include "MainUpdate.h"


int main(void)
{
	system("title ȫ�浿 : �����̸�");
	system("mode con cols=150 lines=40");

	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time <= GetTickCount64())
		{
			system("cls");

			Main.Update();
			Main.Render();

			Time = GetTickCount64();
		}
	}

	return 0;
}