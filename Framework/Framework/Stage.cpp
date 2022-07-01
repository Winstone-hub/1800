#include "Stage.h"
#include "SceneManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{

}


void Stage::Start()
{
	Count = 0;
}

void Stage::Update()
{
	Count++;

	if (Count >= 50)
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
}

void Stage::Render()
{
	cout << "Stage : " << Count << endl;
}

void Stage::Release()
{

}

