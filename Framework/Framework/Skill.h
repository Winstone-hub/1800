#pragma once
#include "Object.h"

class UserInterface;
class Skill : public Object
{
private:
	UserInterface* Box;
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

