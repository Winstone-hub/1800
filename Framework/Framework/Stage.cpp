#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"

Stage::Stage() : EnemyTime(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject(150.f / 2, 40.f / 2));

	EnemyTime = GetTickCount64();
}

void Stage::Update()
{
	if (EnemyTime + 1000 < GetTickCount64())
	{
		srand( int(GetTickCount64() * EnemyTime) );

		Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
			float(rand() % 148 + 1),
			float(rand() % 39 + 1));

		ObjectManager::GetInstance()->AddObject(pEnemy);

		EnemyTime = GetTickCount64();
	}

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}

