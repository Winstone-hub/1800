#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}


void Logo::Start()
{

}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

}

void Logo::Render()
{
	cout << "Logo : " << Count << endl;
}

void Logo::Release()
{

}

