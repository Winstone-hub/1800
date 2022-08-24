#include "Mutant.h"
#include "Enemy.h"
#include "CursorManager.h"

Mutant::Mutant()
{
}

Mutant::~Mutant()
{
}


void Mutant::Start()
{

}

int Mutant::Update(Transform& _Transform)
{

	return 0;
}

void Mutant::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Mutant", 12);
}

void Mutant::Release()
{

}