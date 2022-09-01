#include "ObjectpoolManager.h"
#include "PrototypeManager.h"
#include "Object.h"
#include "CursorManager.h"

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
		DisableList.insert(make_pair(_Key, Temp));
		iter = DisableList.find(_Key);
	}

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

void ObjectpoolManager::SwitchingObject(string _Key, Vector3 _Position)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter->second.empty())
		AddObject(_Key);


	Object* pObj = iter->second.back();
	pObj->SetPosition(_Position);

	EnableList[_Key].push_back(pObj);
	iter->second.pop_back();
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
				// ** EnableList => DisableList 이동.
				DisableList[(*iter2)->GetKey()].push_back((*iter2));
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

	CursorManager::GetInstance()->WriteBuffer(125, 0, (int)EnableList["Enemy"].size());
	CursorManager::GetInstance()->WriteBuffer(125, 1, (int)DisableList["Enemy"].size());
}