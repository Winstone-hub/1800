#include "Bullet.h"
#include "CursorManager.h"

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
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Target = nullptr;
}

void Bullet::Update()
{
	//Info.Position += Info.Direction * 0.01f;

	Info.Position.x += Info.Direction.x * 0.1f;
	Info.Position.y += Info.Direction.y * 0.1f;
}

void Bullet::Render()
{
	CursorManager::GetInstance()->SetCursorPosition(Info.Position, (char*)"*");
}

void Bullet::Release()
{

}
