#pragma once
#include "UserInterface.h"

class ScrollBox : public UserInterface
{
private:
	int Width, Height;
	string WidthTexture;
	char* HeightTexture;
	int ScrollBoxIndex;
public:	   
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	ScrollBox();
	virtual ~ScrollBox();
};

