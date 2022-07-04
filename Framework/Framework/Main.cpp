#pragma once
// ** Framework v4.3  InputManager [OR] [AND]
#include "MainUpdate.h"

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