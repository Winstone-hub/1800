#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"

MainUpdate::MainUpdate(): Count(0)
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->CheckKey();

	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{
	
}