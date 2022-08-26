#pragma once
#include "EnemyBridge.h"


// ** 어린 해충
class Goolops : public EnemyBridge
{
public:
	virtual void Start()override;
	virtual int  Update(Transform& _Transform)override;
	virtual void Render()override;
	virtual void Release()override;

public:
	virtual Bridge* Clone()override { return new Goolops(*this); }
public:
	Goolops();
	virtual ~Goolops();
};

