#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "ObjectManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		Info.Position.y++;

	if (dwKey & KEY_DOWN)
		Info.Position.y--;

	if (dwKey & KEY_LEFT)
		Info.Position.x--;

	if (dwKey & KEY_RIGHT)
		Info.Position.x++;

	if (dwKey & KEY_SPACE)
		ObjectManager::GetInstance()->CreateObject();


	if (dwKey & KEY_ESCAPE)
		Info.Position = Vector3(0.0f, 0.0f);
}

void Player::Render()
{
	cout << "Player X : " << Info.Position.x << endl;
	cout << "Player Y : " << Info.Position.y << endl;
}

void Player::Release()
{

}