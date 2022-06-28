#include "MainUpdate.h"
#include "Object.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	pPlayer = new Object;
	pPlayer->Start();
}

void MainUpdate::Update()
{
	pPlayer->Update();
}

void MainUpdate::Render()
{
	pPlayer->Render();
}

void MainUpdate::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}