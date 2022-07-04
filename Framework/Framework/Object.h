#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Object();
	virtual ~Object();
};

