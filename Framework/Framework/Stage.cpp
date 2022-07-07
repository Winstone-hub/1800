#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"
#include "Enemy.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}


void Stage::Start()
{
	pPlayer = new Player;
	pPlayer->Start();

	pEnemy = new Enemy;
	pEnemy->Start();
}

void Stage::Update()
{
	pPlayer->Update();
	pEnemy->Update();
}

void Stage::Render()
{
	pPlayer->Render();
	//pEnemy->Render();

	//cout << "Player X : " << pPlayer->GetPosition().x << endl;
	//cout << "Player Y : " << pPlayer->GetPosition().y << endl;

	cout << "Enemy X : " << pEnemy->GetPosition().x << endl;
	cout << "Enemy Y : " << pEnemy->GetPosition().y << endl;
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;
}

