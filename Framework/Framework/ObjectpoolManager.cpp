#include "ObjectpoolManager.h"
#include "PrototypeManager.h"
#include "Object.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;


ObjectpoolManager::ObjectpoolManager()
{

}

ObjectpoolManager::~ObjectpoolManager()
{

}

bool ObjectpoolManager::FindObject(string _Key)
{
	auto iter = DisableList.find(_Key);

	if (iter == DisableList.end())
		return false;
	else
		return true;
}

void ObjectpoolManager::AddObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);

		for (int i = 0; i < 5; ++i)
		{
			if (pProtoObj)
			{
				Object* pObject = pProtoObj->Clone();
				Temp.push_back(pObject);
				DisableList.insert(make_pair(_Key, Temp));
			}
			else
			{
				// Err : pProtoObj 에서 객체원본을 찾을수 없다.
				return;
			}
		}
	}

	/*
	map<string, list<Object*>> List = (_b == true) ? EnableList : DisableList;


	if (iter == List.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		DisableList.insert(make_pair(_Object->GetKey(), Temp));
	}
	else
	{
		if (!iter->second.empty())
		{

		}
		else
		{
			for (int i = 0; i < 5; ++i)
			{
				Object* pEnemy = _Object->Clone();

				srand(GetTickCount64() * GetTickCount64());

				pEnemy->SetPosition(
					float(rand() % 148 + 1),
					float(rand() % 39 + 1));
			}
		}

		Object* pObj = iter->second.back();
		iter->second.pop_back();




		map<string, list<Object*>>::iterator iter = EnableList.find(_Object->GetKey());

		
	}
	*/
}

void ObjectpoolManager::SwitchingObject(Object* _Object)
{
	
}

void ObjectpoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); )
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				SwitchingObject((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
}

void ObjectpoolManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}