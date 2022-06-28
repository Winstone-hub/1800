#include "Object.h"
#include "Singleton.h"


Object::Object()
{
}

Object::~Object()
{
}

void Object::Start()
{
	Singleton::GetInstance()->Number = 10;
}

void Object::Update()
{
	Singleton::GetInstance()->Number++;
}

void Object::Render()
{
	//cout << Time << endl;
}

void Object::Release()
{

}