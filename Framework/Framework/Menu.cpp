#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::Start()
{

}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Menu::Render()
{
	cout << "Menu : " << endl;
}

void Menu::Release()
{

}

