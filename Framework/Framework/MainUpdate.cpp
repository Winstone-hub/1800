#include "MainUpdate.h"
#include "Player.h"
#include "Enemy.h"
#include "Singleton.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	pPlayer = new Player;
	pPlayer->Start();

	pEnemy = new Enemy;
	pEnemy->Start();
}

void MainUpdate::Update()
{
	pPlayer->Update();
	pEnemy->Update();
}

void MainUpdate::Render()
{
	pPlayer->Render();
	pEnemy->Render();
}

void MainUpdate::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;
}