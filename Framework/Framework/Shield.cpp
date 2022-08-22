#include "Shield.h"
#include "CursorManager.h"
#include "MathManager.h"


Shield::Shield()
{

}

Shield::~Shield()
{
	Release();
}


void Shield::Start()
{
	Key = "Shield";

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Angle = 0.0f;
	Time = GetTickCount64();
}

int Shield::Update()
{
	if (Time + 500 < GetTickCount64())
	{
		Angle += 30;
		Time = GetTickCount64();
	}

	return 0;
}

void Shield::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		Info.Position.x + cosf(Angle * 180 / 3.141592f) * 4,
		Info.Position.y + -sinf(Angle * 180 / 3.141592f) * 2,
		(char*)"*", 13);
}

void Shield::Release()
{

}