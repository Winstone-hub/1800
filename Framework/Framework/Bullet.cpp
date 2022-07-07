#include "Bullet.h"


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
}

void Bullet::Update()
{

}

void Bullet::Render()
{
	cout << "Bullet X : " << Info.Position.x << endl;
	cout << "Bullet Y : " << Info.Position.y << endl;
}

void Bullet::Release()
{

}
