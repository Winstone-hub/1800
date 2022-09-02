#pragma once
#include "Object.h"

class Skill : public Object
{
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Skill(*this); }
public:
	Skill();
	Skill(Transform _Info) : Object(_Info) {};
	virtual ~Skill();
};

