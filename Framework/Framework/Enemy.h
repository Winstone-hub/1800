#pragma once
#include "Object.h"

class Bridge;
class Enemy : public Object
{
private:
	Bridge* pBridge;
	ULONGLONG Time;
public:
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Enemy();
	virtual ~Enemy();
};

