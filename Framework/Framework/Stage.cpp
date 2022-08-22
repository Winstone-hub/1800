#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Player.h"
#include "ObjectFactory.h"

Stage::Stage() : Time(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	ObjectManager::GetInstance()->SetPlayer(
		ObjectFactory<Player>::CreateObject(150.f / 2, 40.f / 2));

	Time = GetTickCount64();
}

void Stage::Update()
{
	if (GetAsyncKeyState(VK_TAB))
	{
		if (Time + 250 < GetTickCount64())
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject();

			((Bullet*)pBullet)->SetIndex(1);
			pBullet->SetTarget(
				ObjectManager::GetInstance()->GetPlayer());

			ObjectManager::GetInstance()->AddObject(pBullet);

			Time = GetTickCount64();
		}
	}
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
	
}

