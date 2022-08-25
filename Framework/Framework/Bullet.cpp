#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"

Bullet::Bullet() : Speed(0), Time(0)
{
}

Bullet::~Bullet()
{
}


Object* Bullet::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;

	Target = nullptr;

	/*
	switch (rand() % 4)
	{
	case 0: // ** 위
		Info.Position = Vector3(float(rand() % 148), 0.0f);
		break;

	case 1: // 아래
		Info.Position = Vector3(float(rand() % 148), 39.0f);
		break;
		 
	case 2: // 오른쪽
		Info.Position = Vector3(0.0f, float(rand() % 40));
		break;

	case 3: // 왼쪽
		Info.Position = Vector3(148.0f, float(rand() % 40));
		break;
	}
	*/
	
	//Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());
	
	Time = GetTickCount64();

	return this;
}

int  Bullet::Update()
{
	Info.Position += Info.Direction * (Speed * 0.5f);

	//if (Time + 5000 < GetTickCount64())
		//return 2;

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;

	return 0;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
}

void Bullet::Release()
{

}
