#include "Goolops.h"
#include "Enemy.h"
#include "CursorManager.h"

Goolops::Goolops()
{
}

Goolops::~Goolops()
{
}


void Goolops::Start()
{

}

int Goolops::Update(Transform& _Transform)
{

	return 0;
}

void Goolops::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Goolops", 13);
}

void Goolops::Release()
{

}