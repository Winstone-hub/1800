#pragma once
#include "UserInterface.h"

class ScrollBox : public UserInterface
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	ScrollBox();
	virtual ~ScrollBox();
};

