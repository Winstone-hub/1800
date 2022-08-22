#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{

}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::AddObject(Object* _Object)
{
	// ** �ʿ� �Ű������� �Ѿ�� ������Ʈ�� Ű���� ���� �ϴ��� Ȯ��.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_Object->GetKey());

	// ** ���࿡ ���ٸ�.. ����Ʈ ��ü�� �����Ƿ� 
	if (iter == ObjectList.end())
	{
		// ** ���ο� ����Ʈ�� ����
		list<Object*> Temp;

		// ** ����Ʈ�� ������Ʈ�� ����.
		Temp.push_back(_Object);

		// ** ����Ʈ�� �ʿ� �߰�.
		ObjectList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
		// ** ���࿡ ����Ʈ�� ���� �Ѵٸ� �ش� ����Ʈ�� ������Ʈ�� �߰�.
		iter->second.push_back(_Object);
}

void ObjectManager::Update()
{
	pPlayer->Update();

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Update();
}

void ObjectManager::Render()
{
	pPlayer->Render();

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
			(*iter2)->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			delete (*iter2);
			(*iter2) = nullptr;
		}
		iter->second.clear();
	}
	ObjectList.clear();
}