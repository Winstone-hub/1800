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

	Time = GetTickCount64();
}

void Enemy::Update()
{
	if (Time + 250 < GetTickCount64())
	{
		ObjectManager::GetInstance()->CreateObject();
		Time = GetTickCount64();
	}
}

void Enemy::Render()
{

}

void Enemy::Release()
{

}