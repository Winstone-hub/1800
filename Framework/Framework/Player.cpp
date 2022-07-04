#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{

}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		cout << "KEY_UP" << endl;

	if (dwKey & KEY_DOWN)
		cout << "KEY_DOWN" << endl;

}

void Player::Render()
{

}

void Player::Release()
{

}