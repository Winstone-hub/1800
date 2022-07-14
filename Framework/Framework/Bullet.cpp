#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}


void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;

	Target = nullptr;
}

int  Bullet::Update()
{
	switch (Index)
	{
	case 0:
		Info.Position += Info.Direction * Speed;
		break;
	case 1:
	{
		Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
		Info.Position += Info.Direction * (Speed * 0.5f);
	}
		break;
	}

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
	{
		return 1;
	}

	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*");
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
		break;
	}
}

void Bullet::Release()
{

}
