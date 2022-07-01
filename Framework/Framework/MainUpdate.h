#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	int Count;
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

