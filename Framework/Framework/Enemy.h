#pragma once
#include "Object.h"

class Singleton;
class Enemy : public Object
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Enemy();
	virtual ~Enemy();
};

