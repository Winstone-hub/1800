#include "Enemy.h"
#include "Singleton.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Singleton::GetInstance()->SceneState = "Logo";
}

void Enemy::Update()
{

}

void Enemy::Render()
{

}

void Enemy::Release()
{

}