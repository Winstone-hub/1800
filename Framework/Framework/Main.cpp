// ** Framework v2.1
#include "MainUpdate.h"



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
		}
	}


	return 0;
}