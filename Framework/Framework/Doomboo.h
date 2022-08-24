#pragma once
#include "EnemyBridge.h"

class Doomboo : public EnemyBridge
{
public:
	virtual void Start()override;
	virtual int  Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Doomboo();
	virtual ~Doomboo();
};

