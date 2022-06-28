// ** Framework v2.1
#include "MainUpdate.h"



int main(void)
{
	// ** 최초에 생성후 초기화.
	MainUpdate Main;
	Main.Start();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 30 <= GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			// ** 변경사항 및 충돌 등의 이벤트 체크
			Main.Update();

			// ** 그리기
			Main.Render();
		}
	}


	return 0;
}