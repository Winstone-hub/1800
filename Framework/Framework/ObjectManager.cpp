#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = ObjectFactory::CreateBullet(Vector3(74.0f, 1.0f));

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = MathManager::GetDirection(pBullet[i]->GetPosition(), pPlayer->GetPosition());
				pBullet[i]->SetDirection(Direction);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
			}
				break;
			case 1:
				pBullet[i]->SetTarget(pPlayer);
				((Bullet*)pBullet[i])->SetIndex(_StateIndex);
				break;
			}
			break;
		}
	}
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();
	pEnemy = ObjectFactory::CreateEnemy();
}

void ObjectManager::Update()
{
	pPlayer->Update();
	pEnemy->Update();

	int result = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			result = pBullet[i]->Update();

			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(), 
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다.");
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}

void ObjectManager::Render()
{
	pPlayer->Render();
	pEnemy->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	delete pEnemy;
	pEnemy = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}