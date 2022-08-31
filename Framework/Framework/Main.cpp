#pragma once
//http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20
// ** Framework v11.1
#include "MainUpdate.h"


int main(void)
{
	// ** ���콺 Ŭ�� �ȵǰ� ������.
	// ** ��� ����.
	DWORD Mode;

	// ** �Է� ���
	HANDLE Handle = GetStdHandle(STD_INPUT_HANDLE);

	// ** �Է� ��带 ������.
	GetConsoleMode(Handle, &Mode);

	// ** �Է¸�尡 ����� ��忡 �Է��� �� �� ������ ��.
	SetConsoleMode(Handle, Mode & ~ENABLE_QUICK_EDIT_MODE);
	
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	
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