#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	CursorManager::GetInstance()->CreateBuffer(150.0f, 40.0f);

	SceneManager::GetInstance()->SetScene(SCENEID::LOGO);
}

void MainUpdate::Update()
{
	CursorManager::GetInstance()->FlippingBuffer();

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