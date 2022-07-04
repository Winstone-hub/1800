#include "Stage.h"
#include "SceneManager.h"
#include "Player.h"

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
}

void Stage::Update()
{
	pPlayer->Update();
}

void Stage::Render()
{
	pPlayer->Render();
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}

