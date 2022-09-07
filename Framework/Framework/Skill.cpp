#include "Skill.h"
#include "ScrollBox.h"
#include "CursorManager.h"

Skill::Skill()
{
}

Skill::~Skill()
{
	Release();
}


Object* Skill::Start(string _Key)
{
	Key = _Key;

	//Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(10.0f, 5.0f);

	Box = new ScrollBox;
	Box->Start();
	Box->SetPosition(int(Info.Position.x - (Info.Scale.x / 2)), int(Info.Position.y - (Info.Scale.y / 2)));
	Box->SetBoxSize(Info.Scale.x, Info.Scale.y);

	Texture[0] = (char*)"¦¢¡¡¦¢¡¡¦¢";
	Texture[1] = (char*)"¦¢¡¡¦¢¡¡¦¢";
	Texture[2] = (char*)"¦¢¡¡¦¢¡¡¦¢";
	Texture[3] = (char*)"¦¢¡¡¦¢¡¡¦¢";
	Texture[4] = (char*)"¦¦¦¡¦ª¦¡¦¥";

	return nullptr;
}

int Skill::Update()
{
	Box->Update();
	return 0;
}

void Skill::Render()
{
	Box->Render();

	for (int i = 0; i < 5; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			int(Info.Position.x - (Info.Scale.x / 2) + 2),
			int(Info.Position.y - (Info.Scale.y / 2) + 1 + i),
			Texture[i]);
	}
}

void Skill::Release()
{
	delete Box;
	Box = nullptr;
}
