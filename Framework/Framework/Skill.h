#pragma once
#include "Object.h"

class UserInterface;
class Skill : public Object
{
private:
	char* Texture[5];
	UserInterface* Box;
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;

	virtual Object* Clone()override { return new Skill(*this); }
public:
	void SetTexture(char* _Texture[])
	{
		for (int i = 0; i < 5; ++i)
			Texture[i] = _Texture[i];
	}
public:
	Skill();
	Skill(Transform _Info) : Object(_Info) {};
	virtual ~Skill();
};

