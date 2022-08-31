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
	else
	{
		// ** 리스트는 존재하지만 객체가 없는 상태를 확인.
		if (iter->second.empty())
		{
			Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);

			for (int i = 0; i < 5; ++i)
			{
				if (pProtoObj)
				{
					Object* pObject = pProtoObj->Clone();
					iter->second.push_back(pObject);
				}
				else
				{
					// Err : pProtoObj 에서 객체원본을 찾을수 없다.
					return;
				}
			}
		}
	}

	// ** 여기 까지 도달했다면 여분의 객체가 생성된 것이므로 
	// ** DisableList => EnableList 이동.

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