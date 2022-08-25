#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	float Speed;
	ULONGLONG Time;
public:
	virtual Object* Start(string _Key)override; 
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Bullet(*this); }
public:
	Bullet();
	Bullet(Transform _Info) : Object(_Info) {};
	virtual ~Bullet();
};

