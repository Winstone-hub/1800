#pragma once
#include "Object.h"


class Shield : public Object
{
private:
	float Angle;
	ULONGLONG Time;
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Shield(*this); }
public:
	void SetAngle(float _Angle) { Angle = _Angle; }
public:
	Shield();
	Shield(Transform _Info) : Object(_Info) {};
	virtual ~Shield();
};
