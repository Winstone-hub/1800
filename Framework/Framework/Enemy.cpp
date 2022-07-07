#include "Enemy.h"

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
}

void Enemy::Update()
{

}

void Enemy::Render()
{
	cout << "Enemy X : " << Info.Position.x << endl;
	cout << "Enemy Y : " << Info.Position.y << endl;
}

void Enemy::Release()
{

}