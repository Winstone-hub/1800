#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }
public:
	Bullet();
	virtual ~Bullet();
};

