#pragma once
// ** Framework v2.3  ( Singleton )
#include "MainUpdate.h"
#include "Singleton.h"

Singleton* Singleton::Instance = nullptr;

int main(void)
{
	MainUpdate Main;
	Main.Start();


	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 100 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}