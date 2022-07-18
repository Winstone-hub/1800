#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{
	Release();
}


void Logo::Start()
{
	Buffer[0] = (char*)"LLLLLLLLLLL                                                                   ";
	Buffer[1] = (char*)"L:::::::::L                                                                   ";
	Buffer[2] = (char*)"L:::::::::L                                                                   ";
	Buffer[3] = (char*)"LL:::::::LL                                                                   ";
	Buffer[4] = (char*)"  L:::::L                  ooooooooooo      ggggggggg   ggggg   ooooooooooo   ";
	Buffer[5] = (char*)"  L:::::L                oo:::::::::::oo   g:::::::::ggg::::g oo:::::::::::oo ";
	Buffer[6] = (char*)"  L:::::L               o:::::::::::::::o g:::::::::::::::::go:::::::::::::::o";
	Buffer[7] = (char*)"  L:::::L               o:::::ooooo:::::og::::::ggggg::::::ggo:::::ooooo:::::o";
	Buffer[8] = (char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o";
	Buffer[9] = (char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o";
	Buffer[10] = (char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o";
	Buffer[11] = (char*)"  L:::::L         LLLLLLo::::o     o::::og::::::g    g:::::g o::::o     o::::o";
	Buffer[12] = (char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::og:::::::ggggg:::::g o:::::ooooo:::::o";
	Buffer[13] = (char*)"L::::::::::::::::::::::Lo:::::::::::::::o g::::::::::::::::g o:::::::::::::::o";
	Buffer[14] = (char*)"L::::::::::::::::::::::L oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo ";
	Buffer[15] = (char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo       gggggggg::::::g    ooooooooooo   ";
	Buffer[16] = (char*)"                                                     g:::::g                  ";
	Buffer[17] = (char*)"                                         gggggg      g:::::g                  ";
	Buffer[18] = (char*)"                                         g:::::gg   gg:::::g                  ";
	Buffer[19] = (char*)"                                          g::::::ggg:::::::g                  ";
	Buffer[20] = (char*)"                                           gg:::::::::::::g                   ";
	Buffer[21] = (char*)"                                             ggg::::::ggg                     ";
	Buffer[22] = (char*)"                                                gggggg                 	   ";

	Length = strlen("L::::::::::::::::::::::L oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo ");

	MaxSize = 23;

	Color = 15;

	Time = GetTickCount64();
}

void Logo::Update()
{
	if (Time + 500 < GetTickCount64())
	{
		Time = GetTickCount64();

		Color = rand() % 7 + 9;
	}

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	for (int i = 0; i < MaxSize ; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length / 2), 5.0f + i, Buffer[i], Color);
}

void Logo::Release()
{
	
}













