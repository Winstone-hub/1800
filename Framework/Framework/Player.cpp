#include "Player.h"
#include "Singleton.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Singleton::GetInstance()->SceneState = "Menu";
}

void Player::Update()
{

}

void Player::Render()
{

}

void Player::Release()
{

}