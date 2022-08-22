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
	
	return 0;
}

void Enemy::Render()
{

}

void Enemy::Release()
{

}