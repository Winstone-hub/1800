#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}


void Stage::Start()
{
	ObjectManager::GetInstance()->Start();
}

void Stage::Update()
{
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}

