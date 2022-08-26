#pragma once
#include "Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
public:
	void SetObject(Object* _Object) { pObject = _Object; }
public:
	virtual void Start()PURE;
	virtual int  Update(Transform& _Transform)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

	virtual Bridge* Clone()PURE;
public:
	Bridge() : pObject(nullptr) {}
	virtual ~Bridge() {}
};