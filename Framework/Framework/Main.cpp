#pragma once
//http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
// ** Framework v11.1
#include "MainUpdate.h"


int main(void)
{
	// ** 마우스 클릭 안되게 막아줌.
	// ** 모드 설정.
	DWORD Mode;

	// ** 입력 모드
	HANDLE Handle = GetStdHandle(STD_INPUT_HANDLE);

	// ** 입력 모드를 적용함.
	GetConsoleMode(Handle, &Mode);

	// ** 입력모드가 적용된 모드에 입력을 할 수 없도록 함.
	SetConsoleMode(Handle, Mode & ~ENABLE_QUICK_EDIT_MODE);
	
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	
	system("title 홍길동 : 게임이름");
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

/*
* 
INPUT_RECORD rec;
DWORD        dw;
DWORD        dwNOER;


POINT ptMouse;
//SetCursorPos();

while (true)
{
	ReadConsoleInput(Handle, &rec, 1, &dwNOER)
	int x = rec.Event.MouseEvent.dwMousePosition.X;
	int y = rec.Event.MouseEvent.dwMousePosition.Y;
	GetCursorPos(&ptMouse);
	system("cls");

	cout << ptMouse.x << " : " << ptMouse.y << endl;
	cout << x << " : " << y << endl;
}
*/