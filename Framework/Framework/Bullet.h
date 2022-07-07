#pragma once
#include "Object.h"

class Bullet : public Object
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Bullet();
	virtual ~Bullet();
};

