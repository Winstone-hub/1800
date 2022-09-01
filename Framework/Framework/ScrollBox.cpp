#include "ScrollBox.h"
#include "CursorManager.h"


ScrollBox::ScrollBox()
{

}

ScrollBox::~ScrollBox()
{

}


void ScrollBox::Start()
{
	Key = "ScrollBox";

	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f, 0.0f);

	Texture.push_back("------");
	Texture.push_back("¦¢¡¡¦¢");
	Texture.push_back("------");

	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

	int length = int(str.size() / 2) + 1;
	
	
}

void ScrollBox::Update()
{

}

void ScrollBox::Render()
{
	int i = 0;
	for (vector<string>::iterator iter = Texture.begin(); iter != Texture.end(); ++iter)
	{
		string::iterator iter2 = iter->begin() + 2;

		iter->insert(iter2, (char)"-");
		
		//CursorManager::GetInstance()->WriteBuffer(int(150 / 2), 1 + i, (*));
		//CursorManager::GetInstance()->WriteBuffer(100, 1 + i, (*iter2));
		CursorManager::GetInstance()->WriteBuffer(50, 1 + i, (*iter));
		i++;
		//system("pause");
	}
}

void ScrollBox::Release()
{

}
