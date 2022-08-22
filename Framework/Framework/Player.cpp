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

void Player::Start()
{
	Key = "Player";

	Info.Position = Vector3(74.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		Info.Position.y--;

		if (Info.Position.y < 0)
			Info.Position.y = 39;
	}

	if (dwKey & KEY_DOWN)
	{
		Info.Position.y++;

		if (Info.Position.y > 39)
			Info.Position.y = 0;
	}

	if (dwKey & KEY_LEFT)
	{
		Info.Position.x -= 2;
	
		if (Info.Position.x < 0)
			Info.Position.x = 148;
	}

	if (dwKey & KEY_RIGHT)
	{
		Info.Position.x += 2;

		if (Info.Position.x > 150)
			Info.Position.x = 0;
	}

	//if (dwKey & KEY_SPACE)
		//ObjectManager::GetInstance()->CreateObject();

	//if (dwKey & KEY_ESCAPE)
		//Info.Position = Vector3(0.0f, 0.0f);

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡â");
}

void Player::Release()
{

}