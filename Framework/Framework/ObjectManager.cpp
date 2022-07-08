#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

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
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			pBullet[i]->SetPosition(74.0f, 1.0f);

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = pPlayer->GetPosition() - pBullet[i]->GetPosition();
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
	pPlayer = new Player;
	pPlayer->Start();

	pEnemy = new Enemy;
	pEnemy->Start();
}

void ObjectManager::Update()
{
	pPlayer->Update();
	pEnemy->Update();

	int result = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			result = pBullet[i]->Update();

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