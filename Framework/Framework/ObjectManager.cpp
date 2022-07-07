#include "ObjectManager.h"
#include "Bullet.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::Start()
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
}

void ObjectManager::Update()
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Update();
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}