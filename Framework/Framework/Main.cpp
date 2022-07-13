#pragma once
// ** Framework v9.0    DoubleBuffer
#include "MainUpdate.h"


int main(void)
{
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