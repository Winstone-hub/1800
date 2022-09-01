#include "Stage.h"
#include "SceneManager.h"
#include "ObjectpoolManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"
#include "PrototypeManager.h"
#include "ScrollBox.h"

Stage::Stage() : EnemyTime(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();

	if(pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);

	EnemyTime = GetTickCount64();

	for (int i = 0; i < 20; ++i)
	{
		ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");
	}
	Box = new ScrollBox;
	Box->Start();
}

void Stage::Update()
{
	

	/*
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();

	float Result = ((PlayerPosition.x * 100) / 100);
	Result = (100 - Result);
	Result = Result / 100;

	if (EnemyTime + (2500 * Result) < GetTickCount64())
	{
		srand( int(GetTickCount64() * EnemyTime) );

		Object* pEnemy = PrototypeManager::GetInstance()->FindObject("Enemy")->Clone();
		
		if (pEnemy != nullptr)
		{
			pEnemy->SetPosition(
				float(rand() % 148 + 1),
				float(rand() % 39 + 1));

			ObjectManager::GetInstance()->AddObject(pEnemy);
		}

		EnemyTime = GetTickCount64();
	}
	*/

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	Box->Render();
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}

