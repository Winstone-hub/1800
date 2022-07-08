#include "Enemy.h"
#include "ObjectManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);

	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();
}

int Enemy::Update()
{
	if (Time + 250 < GetTickCount64())
	{
		Count++;

		if (Count >= 10)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(1);
		}
		else
			ObjectManager::GetInstance()->CreateObject(0);

		Time = GetTickCount64();
	}
	return 0;
}

void Enemy::Render()
{

}

void Enemy::Release()
{

}