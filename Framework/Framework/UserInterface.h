#pragma once
#include "Headers.h"

class UserInterface
{
protected:
	Vector3 StartPos;
	Vector3 EndPos;
	string Key;
	vector<string> Texture;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	UserInterface();
	virtual ~UserInterface();
};
