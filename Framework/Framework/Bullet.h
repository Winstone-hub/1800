#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	float Speed;
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Bullet();
	virtual ~Bullet();
};

