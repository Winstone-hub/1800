#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	float Speed;
	int Option;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }
	//void SetAngle(float _Angle) { Angle = _Angle; }
public:
	Bullet();
	virtual ~Bullet();
};

