#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::Start()
{
	Count = 0;
}

void Menu::Update()
{
	Count++;

	if (Count >= 50)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Menu::Render()
{
	cout << "Menu : " << Count << endl;
}

void Menu::Release()
{

}

