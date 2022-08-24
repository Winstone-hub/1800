#include "Doomboo.h"
#include "Enemy.h"
#include "CursorManager.h"

Doomboo::Doomboo()
{
}

Doomboo::~Doomboo()
{
}

void Doomboo::Start()
{

}

int Doomboo::Update(Transform& _Transform)
{
	
	return 0;
}

void Doomboo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition() , (char*)"Doomboo", 10);
}

void Doomboo::Release()
{

}
