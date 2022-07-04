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

	if (dwKey & KEY_LEFT)
		cout << "KEY_LEFT" << endl;

	if (dwKey & KEY_RIGHT)
		cout << "KEY_RIGHT" << endl;

	if (dwKey & KEY_SPACE)
		cout << "KEY_SPACE" << endl;

	if (dwKey & KEY_RETURN)
		cout << "KEY_RETURN" << endl;

	if (dwKey & KEY_ESCAPE)
		cout << "KEY_ESCAPE" << endl;
}

void Player::Render()
{

}

void Player::Release()
{

}