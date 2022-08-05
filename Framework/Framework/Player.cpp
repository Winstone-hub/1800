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
	Info.Position = Vector3(74.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;

	for (int i = 0; i < 4; ++i)
	{
		Bullets[i] = new Shield;
		Bullets[i]->Start();
		Bullets[i]->SetPosition(Info.Position);
		((Shield*)Bullets[i])->SetAngle(90.0f * i);
	}
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		Info.Position.y--;

	if (dwKey & KEY_DOWN)
		Info.Position.y++;

	if (dwKey & KEY_LEFT)
		Info.Position.x -= 2;

	if (dwKey & KEY_RIGHT)
		Info.Position.x += 2;

	//if (dwKey & KEY_SPACE)
		//ObjectManager::GetInstance()->CreateObject();

	//if (dwKey & KEY_ESCAPE)
		//Info.Position = Vector3(0.0f, 0.0f);

	for (int i = 0; i < 4; ++i)
	{
		Bullets[i]->SetPosition(Info.Position);
		Bullets[i]->Update();
	}

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡â");

	for (int i = 0; i < 4; ++i)
		Bullets[i]->Render();
}

void Player::Release()
{
	for (int i = 0; i < 4; ++i)
	{
		delete Bullets[i];
		Bullets[i] = nullptr;
	}
}