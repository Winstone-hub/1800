#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "Bullet.h"
#include "Bridge.h"
#include "Goolops.h"
#include "Mutant.h"
#include "Doomboo.h"


Bridge* Enemy::BridgeList[3];


Enemy::Enemy() : pBridge(nullptr), Time(0)
{
	for (int i = 0; i < 3; ++i)
		BridgeList[i] = nullptr;
}

Enemy::~Enemy()
{
	Release();
}

Object* Enemy::Start(string _Key)
{
	Key = _Key;

	Time = GetTickCount64() - 7000;

	pBridge = nullptr;

	BridgeList[EnemyID_Goolops] = new Goolops;
	BridgeList[EnemyID_Mutant] = new Mutant;
	BridgeList[EnemyID_Doomboo] = new Doomboo;

	return this;
}

int Enemy::Update()
{
	if (pBridge)
		pBridge->Update(Info);
	else
	{
		if (Time + 7000 < GetTickCount64())
		{
			srand(int(Time * GetTickCount64()));
			switch (rand() % 3)
			{
			case EnemyID_Goolops:
				pBridge = BridgeList[EnemyID_Goolops]->Clone();
				break;

			case EnemyID_Mutant:
				pBridge = BridgeList[EnemyID_Mutant]->Clone();
				break;

			case EnemyID_Doomboo:
				pBridge = BridgeList[EnemyID_Doomboo]->Clone();
				break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}

	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
}