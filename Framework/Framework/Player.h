#pragma once
#include "Object.h"


class Player : public Object
{
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Player(*this); }
public:
	Player();
	Player(Transform _Info) : Object(_Info) {};
	virtual ~Player();
};

