#pragma once
#include "Headers.h"

class Object
{
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	Object();
	~Object();
};

