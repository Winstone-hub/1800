#include "ScrollBox.h"
#include "CursorManager.h"


ScrollBox::ScrollBox() : Width(0), Height(0)
{

}

ScrollBox::~ScrollBox()
{

}


void ScrollBox::Start()
{
	Key = "ScrollBox";

	//Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	//Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	//Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	//Info.Direction = Vector3(0.0f, 0.0f, 0.0f);

	Width = 2;
	Height = 1;

	StartPos = Vector3(50, 10);
	EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);

	WidthTexture = "";
	HeightTexture = (char*)"¦¢";

	Texture.push_back("¦£¦¡¦¤");
	Texture.push_back("¦¢¡¡¦¢");
	Texture.push_back("¦¦¦¡¦¥");
	End = 3;
}

void ScrollBox::Update()
{

}

void ScrollBox::Render()
{
	/*
	if (GetAsyncKeyState(VK_CONTROL))
	{
		++Height;
		Width += 2;
		WidthTexture += "¦¡";

		EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);
	}

	// ** ÁÂ»ó
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y, "¦£");
	CursorManager::GetInstance()->WriteBuffer(StartPos.x + 2, StartPos.y, WidthTexture);
	
	// ** ¿ì»ó
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, StartPos.y, "¦¤");

	// ** ÁÂÇÏ
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, EndPos.y, "¦¦");
	CursorManager::GetInstance()->WriteBuffer(StartPos.x + 2, EndPos.y, WidthTexture);

	// ** ¿ìÇÏ
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, EndPos.y, "¦¥");

	for (int y = StartPos.y + 1 ; y < EndPos.y ; ++y)
	{
		CursorManager::GetInstance()->WriteBuffer(StartPos.x, y, HeightTexture);
		CursorManager::GetInstance()->WriteBuffer(EndPos.x, y, HeightTexture);
	}
	*/

	if (GetAsyncKeyState(VK_CONTROL))
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

	int n = 0;
	for (vector<string>::iterator iter = Texture.begin(); iter != Texture.end(); ++iter, ++n)
		CursorManager::GetInstance()->WriteBuffer(50, 1 + n, (*iter));
}

void ScrollBox::Release()
{

}
