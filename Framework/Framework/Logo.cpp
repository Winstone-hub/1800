#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}


void Logo::Start()
{
	Count = 0;
}

void Logo::Update()
{
	Count++;

	if(Count >= 50)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	cout << "Logo : " << Count << endl;
}

void Logo::Release()
{

}

