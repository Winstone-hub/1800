#pragma once
#include "Object.h"


class Shield : public Object
{
private:
	float Angle;
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetAngle(float _Angle) { Angle = _Angle; }
public:
	Shield();
	virtual ~Shield();
};
