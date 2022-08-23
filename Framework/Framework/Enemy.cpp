#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectFactory.h"
#include "Bullet.h"

Enemy::Enemy() : Count(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Key = "Enemy";
	
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);

	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();
}

int Enemy::Update()
{
	if (Time + 1000 < GetTickCount64())
	{
		Object* pBullet = ObjectFactory<Bullet>::CreateObject(Info.Position);

		pBullet->SetTarget(ObjectManager::GetInstance()->GetPlayer());

		ObjectManager::GetInstance()->AddObject(pBullet);

		Time = GetTickCount64();
	}

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"бр");
}

void Enemy::Release()
{

}