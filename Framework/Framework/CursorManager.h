#pragma once
#include "Headers.h"

class CursorManager
{
private:
	static CursorManager* Instance;
public:
	static CursorManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new CursorManager;
		return Instance;
	}
public:
	void SetCursorPosition(float _x, float _y , char* _str, int _Color = 15);
	void SetCursorPosition(Vector3 _Position, char* _str, int _Color = 15);

	void SetColor(int _Color);
private:
	CursorManager();
public:
	~CursorManager();
};