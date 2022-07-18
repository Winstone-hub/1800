#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	int Length;
	int MaxSize;
	char* Buffer[32];

	int Color;
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Logo();
	virtual ~Logo();
};