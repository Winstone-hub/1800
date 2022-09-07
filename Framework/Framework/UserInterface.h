#pragma once
#include "Headers.h"

class UserInterface
{
protected:
	Vector3 StartPos;
	Vector3 EndPos;
	string Key;
	vector<string> Texture;
	int End;
public:
	static int Index;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetPosition(int _x, int _y) { StartPos = Vector3(_x, _y); } 

	void SetBoxSize(int _x, int _y)
	{
		if (_x % 2 == 1)
			_x += 1;

		EndPos = Vector3(StartPos.x + _x, StartPos.y + _y);

		for (int y = StartPos.y + 1; y < EndPos.y; ++y)
		{
			auto Heightiter = Texture.begin() + 1;
			Texture.insert(Heightiter, (*Heightiter));

			vector<string>::iterator Widthiter = Texture.begin();

			Widthiter[0].pop_back();
			Widthiter[0].pop_back();
			Widthiter[0] += "¦¡¦¤";

			for (int i = 1; i < End; ++i)
			{
				Widthiter[i].pop_back();
				Widthiter[i].pop_back();
				Widthiter[i] += "¡¡¦¢";
			}

			Widthiter[End].pop_back();
			Widthiter[End].pop_back();
			Widthiter[End] += "¦¡¦¥";
			++End;
		}
	}
public:
	UserInterface();
	virtual ~UserInterface();
};
