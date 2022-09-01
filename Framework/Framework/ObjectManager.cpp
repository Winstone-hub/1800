#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include "ObjectpoolManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{

}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::AddObject(string _Key)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key);
}

void ObjectManager::AddObject(Vector3 _position, string _Key)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);

	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _position);
}

void ObjectManager::Update()
{
	pPlayer->Update();
	ObjectpoolManager::GetInstance()->Update();
}

void ObjectManager::Render()
{
	pPlayer->Render();
	ObjectpoolManager::GetInstance()->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}