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
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	float Result = ((PlayerPosition.x * 100) / 100);
	Result = (100 - Result);
	Result = Result / 100;

	if (EnemyTime + (2500 * Result) < GetTickCount64())
	{
		srand( int(GetTickCount64() * EnemyTime) );

		Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
			float(rand() % 130 + 1), float(rand() % 39 + 1));

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

