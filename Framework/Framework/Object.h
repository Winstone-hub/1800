#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
	string Key;
	float Speed;
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Transform GetTransform() const { return Info; }
	string GetKey() const { return Key; }
	void SetKey(const string& _Key ) { Key = _Key; }

	Vector3 GetPosition() const { return Info.Position; } 
	void SetPosition(Vector3 _Position) { Info.Position = _Position; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }

	void SetDirection(Vector3 _Direction) { Info.Direction = _Direction; }
	void SetDirection(float _x, float _y) { Info.Direction = Vector3(_x, _y); }
	void SetTarget(Object* _Target) { Target = _Target; }
public:
	Object();
	virtual ~Object();
};

