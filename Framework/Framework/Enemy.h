#pragma once
#include "Object.h"

class Enemy : public Object
{
private:
	ULONGLONG Time;
	int Count;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Enemy();
	virtual ~Enemy();
};

