#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "InputManager.h"
#include "CursorManager.h"

Player::Player()
{
}

Player::~Player()
{
	Release();
}


Object* Player::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(74.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;

	return this;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		if(Info.Position.y != 0)
			Info.Position.y--;
	}

	if (dwKey & KEY_DOWN)
	{
		if(Info.Position.y != 39)
			Info.Position.y++;
	}

	if (dwKey & KEY_LEFT)
	{
		if(Info.Position.x > 1)
			Info.Position.x -= 2;
	}

	if (dwKey & KEY_RIGHT)
	{
		if (Info.Position.x < 98)
			Info.Position.x += 2;
	}
	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡â");
}

void Player::Release()
{

}